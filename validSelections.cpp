#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int countValidSelections(vector<int>& nums){
        int n=nums.size();
        int count=0;

        //Try each index where nums[i]==0 as a starting position
        for (int start=0; start<n; start++){
            if (nums[start]!=0){
                continue;
            }

            //Try both directions: left(-1) and right (+1)
            for (int direction: {-1, 1}){
                //Create a copy of nums to simulate on
                vector<int> arr=nums;
                int curr=start;
                int dir=direction;

                //simulate the movement process
                while (curr>=0 && curr <n){
                    if (arr[curr]==0){
                        //Move one step in current direction
                        curr+=dir;
                    }else{
                        //Decrement, reverse direction, then move
                        arr[curr]--;
                        dir *=-1;
                        curr+=dir;
                    }
                }

                //Chec if all elements are zero
                bool allZero=true;
                for (int x: arr){
                    if (x!=0){
                        allZero=false;
                        break;
                    }
                }

                if (allZero){
                    count++;
                }
            }
        }

        return count;
    }
};

//Test cases
int main(){
    Solution sol;

    //Test case 1
    vector<int> nums1={1, 0, 1};
    cout<<"Test 1 [1, 0, 1]:"<<sol.countValidSelections(nums1)<<endl;  //Expected: 2

    //Test case 2
    vector<int> nums2={0};
    cout<<"Test 2[0]:"<<sol.countValidSelections(nums2)<<endl; //Expected: 2

    //Test case 3
    vector<int> nums3={1, 0, 0};
    cout<<"test 3[1, 0, 0]:"<<sol.countValidSelections(nums3)<<endl; //Expected: 0

    vector<int> nums5={1, 0, 1, 0, 1};
    cout<<"Test 5 [1, 0, 1, 0, 1]:"<<sol.countValidSelections(nums5)<<endl; //Expected: 4

    return 0;
}