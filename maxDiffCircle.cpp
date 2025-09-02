#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution{
public:
    int maxAdjacentDistance(const vector<int>& nums){
        int maxDiff=0;
        int n=nums.size();

        for (int i=0; i<n; ++i){
            int next=(i+1)%n;
            int diff=abs(nums[i]-nums[next]);
            maxDiff=max(maxDiff, diff);
        }
        return maxDiff;
    }
};

//Helper function to run a test
void runTest(int testNum, const vector<int>& nums, int expected){
    Solution sol;
    int result=sol.maxAdjacentDistance(nums);
    if (result==expected){
        cout<<"Test case"<<testNum<<": PASS\n";
    }else{
        cout<<"Test case"<<testNum<<": FAIL | Output:"<<result<<", Expected:"<<expected<<"\n";
    }
}

int main(){
    runTest(1, {1, 2, 4}, 3);
    runTest(2, {-5, -10, -5}, 5);
    runTest(3, {5, 10}, 5);
    runTest(4, {-100, 100}, 200);
    runTest(5, {5, 5, 5, 5, 5}, 0);
    runTest(6, {1, 3, 7, 1}, 6);

    return 0;
}