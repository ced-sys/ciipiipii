/* You are given a 0-indexed array `stations` of length `n` where `stations[i]` represents the number of power stations in the `ith` city.
 *
 * Each power station can provide to every city in a fixed range. In other words, if the range is denoted by `r`, then a power station at city `i` can provide all the city `j` such that `|i-j|<=r` and `O<=i, j<=n-1`.
 *
 * The power of a city is the total number of power station its being provided from. The government has sacntioned building `k` more power stations of a city if the additional power stations ae built optimally.
 *
 * Note that you can build the `k` power stations in multiple cities.
 *
 * **SOLUTION**
 *
 * 1. Pre-compute each city's base (how many existing stations already cover that city) using prefixes `sums` and range `r`
 * 2. Binary search the answer `target`=the minimum power we try to guarantee
 * 3. For a given `target`, check if its possible with at most `k` added stations:
 * 	* Sweep left-> Right
 * 	* Maintain a sliding `currAdd<target`, greedily place the required number of stations that affect current city (use a difference array `diff` so contributions expire after `2r` cities).
 * 	If `base[i]+currAdd<target`, greedily place the required number of stations at position `p=min (n-1, i+r)` (furthest right coverage).Update  `currAdd`, `diff`, and remaining `k`.
 * 	* If you need more than remaining `k` this `target` s infeasible.
 * 4. Binary Search until you find the largest feasible `target`.
 * This runs in O(n log m) where m is roughly `max(base)+k`
 * */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long maxPower(vector<int>& stations, int r, int k){
		int n=stations.size();

		//Step 1:Prefix sums to compute base power for each city
		vector<long long> pref(n+1, 0);
		for (int i=0;i<n; i++)
			pref[i+1]=pref[i]+stations[i];

		auto rangeSum=[&](int l, int rr)-> long long{
			if (l>rr) return 0;
			return pref[rr+1]-pref[l];
		};

		vector<long long> base(n, 0);
		for (int i=0; i<n; i++){
			int left=max(0, i-r);
			int right=min(n-1, i+r);
			base[i]=rangeSum(left, right);
		}

		//Binary search range
		long long lo=*min_element(base.begin(), base.end());
		long long hi=*max_element(base.begin(), base.end());
		long long ans=lo;

		auto canAchieve=[&](long long target) -> bool{
			vector<long long> diff(n+1, 0);
			long long currAdd=0;
			long long remaining=k;

			for(int i=0; i<n; i++){
				currAdd+=diff[i];
				long long total=base[i]+currAdd;
				if (total<target){
					long long need=target-total;
					if (need > remaining) return false;
					remaining-=need;
					currAdd+=need;

					int end=min(n-1, i+2*r);
					diff[end+1]-=need; //Effect expires after end
				}
			}
			return true;
		};

		while (lo<=hi){
			long long mid=(lo+hi)/2;
			if (canAchieve(mid)){
				ans=mid;
				lo=mid+1;
			}else{
				hi=mid-1;
			}
		}
		return ans;
	}
};

int main(){
	Solution sol;
	vector<int> stations={1, 2, 0, 1, 0};
	int r=1, k=2;
	cout<<sol.maxPower(stations, r, k)<<"\n"; //example output
	return 0;
}

