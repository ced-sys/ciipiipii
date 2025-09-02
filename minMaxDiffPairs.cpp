#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minimizeMax(vector<int>& nums, int p){
        sort(nums.begin(), nums.end());

        int left=0, right=nums.back()-nums.front();
        int result=right;

        while (left<=right){
            int mid=left+(right-left)/2;
            if (canFormPairs(nums, p, mid)){
                result=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return result;
    }
private:
    bool canFormPairs(const vector<int>& nums, int p, int maxDiff){
        int count=0;
        int i=0;
        while (i<nums.size()-1){
            if (nums[i+1]-nums[i]<=maxDiff){
                count++;
                i+=2;
            }else{
                i++;
            }
        }
        return count >= p;
    }
};

int main(){
    Solution sol;

    vector<int> nums1={10, 1, 2, 7, 1, 3};
    int p1=2;
    cout<<"Result for test 1:"<<sol.minimizeMax(nums1, p1)<<endl;

    vector<int> nums2={4, 2, 1, 2};
    int p2=1;
    cout<<"Result for test 2:"<<sol.minimizeMax(nums2, p2)<<endl;

    return 0;
}
