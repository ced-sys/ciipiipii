#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    int findLHS(vector<int>& nums){
        if (nums.size()<=1) return 0;

        unordered_map<int, int> freq;

        //COunt frequency of each element
        for(int num: nums){
            freq[num]++;
        }

        int maxLen=0;

        //check for ech key if key-1 exists
        for(auto& [num, count]: freq){
            if (freq.count(num-1)){
                maxLen=max(maxLen, count+freq[num-1]);
            }
        }

        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1, 3, 2, 2, 5, 2, 3, 7};

    int result=sol.findLHS(nums);
    cout<<"Longest Harmonious Subsequence length:"<<result<<endl;

    return 0;
}