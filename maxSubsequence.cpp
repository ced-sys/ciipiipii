#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> maxSubsequence(vector<int>& nums, int k){
        vector<pair<int, int>> nums_with_indices;

        //1. Pair each number with its original index
        for (int i=0; i<nums.size(); ++i){
            nums_with_indices.push_back({nums[i], i});
        }

        //2. Sort by value descending
        sort(nums_with_indices.begin(), nums_with_indices.end(),
    [](const pair<int, int>& a, const pair<int, int>& b){
        return a.first>b.first;
    });

    //3. Take top-k and store in a separate vector
    vector<pair<int, int>> top_k(nums_with_indices.begin(), nums_with_indices.begin()+k);

    //4. Sort top-k by original index to preserve order
    sort(top_k.begin(), top_k.end(),
[](const pair<int, int>& a, const pair<int, int>& b){
    return a.second<b.second; //compare by index
});

//5. Extract values only
vector<int> result;
for(const auto& [value, index]: top_k){
    result.push_back(value);
}

return result;
    }
};


int main(){
    Solution sol;
    vector<int> nums={3, 5, 1, 2};
    int k=2;

    vector<int> result=sol.maxSubsequence(nums, k);
    for(int num : result){
        cout<<num<<"";
    }

    cout<<endl; //Output: 3 5
    return 0;
}