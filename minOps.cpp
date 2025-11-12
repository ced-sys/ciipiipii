/* You are given a 0-indexed array nums consisting of positive integers. You can do the following operation on the array any number of times.
 *
 * Select and index `i` such that `0<=i<n-1` and replace either of `nums[i]` or `nums[i+1]` with their gcd value.
 *
 * Return the minimum number of operations to make all elements of `nums` equal to `1`. If it's impossible, return `-1`.
 *
 *
 * **SOLUTION**
 * You are given an array `nums` of positive integers.
 *  You can repeatedly choose an index `i` (`0<=i<n-1`) and replace either `nums[i]` or `nums[i+1]` with gd (nums[i], nums[i+1]).
 *
 *  You need to find the minimum number of operations to make all elements equal to 1. 
 *  Because gcd operations can neer introduce new prime factors -- only remove them.
 *  So: `if (gcd(nums)> 1) return -1;`
 *
 *  2. If any element is already 1,
 *  then you can use it to spread 1s across the array with `n_count(1)` operations.
 *  3. Otherwise, we need to create a 1 first.
 *  The minimal way to do this is to find the shortest subarray whose gcd=1.
 *  Because if you take that subarray and reduce it step-by-step using gcd operations, you can create a 1 there.
 *
 *  Once we have a single `1`, it takes `(n-1)` additional operations to spread it.
 *
 *  So the total operations= `(length_of_shortest_subarray_with_gcd_1 -1)+(n-1)`
 *
 *  **ALGORITHM**
 *  1. Compute `g=gcd of all elements'.
 *  if `g!=1`, return `-1`.
 *
 *  2. Count `cnt1=number of 1s`.
 *  if `cnt1>0`, return `n-cnt1`.
 *
 *  3. Otherwise, find the shortest subarray with gd =1:
 *  	For each `i`, expand `j` from `i` to `n-1`, keeping track of the gcd.
 *  	If at any point `gcd==1`, record `(j-i+1)` as a candidate length and break.
 *
 *  4. Take the smalles such length=`len`
 *
 *  5. Return `(len-1)+(n-1)`
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums){
	int n=nums.size();
	int overall_gcd=nums[0];
	for (int x : nums)
		overall_gcd=gcd(overall_gcd, x);

	if (overall_gcd>1) return -1;

	int ones=count(nums.begin(), nums.end(), 1);
	if (ones>0)
		return n-ones;

	int best=INT_MAX;
	for (int i=0; i<n; ++i){
		int g=nums[i];
		for(int j=i+1; j<n; ++j){
			g=gcd(g, nums[j]);
			if (g==1){
				best=min(best, j-i+1);
				break;
			}
		}
	}
	return (best-1)+(n-1);
}

int main(){
	vector<int> nums={2, 6, 3, 4};
	cout<<minOperations(nums)<<endl;
	return 0;
}
