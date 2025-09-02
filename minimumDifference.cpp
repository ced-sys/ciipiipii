#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minimumDifference(vector<int>& nums){
        int m=nums.size();
        int n=m/3;

        //Left max sum using min n elements (max heap)
        vector<long long> left(m, 0);
        priority_queue<int> maxheap;
        long long prefSum=0;

        for (int i=0; i<n; ++i){
            prefSum+=nums[i];
            maxheap.push(nums[i]);
        }
        left[n-1]=prefSum;

        for(int i=n; i<2*n; ++i){
            maxheap.push(nums[i]);
            prefSum+= nums[i]-maxheap.top();
            maxheap.pop();
            left[i]=prefSum;
        }

        //Right min sum using max n elements (min heap)
        vector<long long> right(n, 0);
        priority_queue<int, vector<int>, greater<int>> minheap;
        long long suffSum=0;

        for (int i=m-1; i>=2*n; --i){
            suffSum+=nums[i];
            minheap.push(nums[i]);
        }
        right[2*n]=suffSum;

        for (int i=2*n-1; i>=n; --i){
            minheap.push(nums[i]);
            suffSum+=nums[i]-minheap.top();
            minheap.pop();
            right[i]=suffSum;
        }

        //Compute minimum differene
        long long diff=LLONG_MAX;
        for(int i=n-1; i<2*n; ++i){
            diff=min(diff, left[i]-right[i+1]);
        }
        return (int)diff;
    }
};
