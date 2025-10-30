#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int minNumberOperations(vector<int>& target){
        int ops=target[0]; //Initial operations needed for first element

        for (size_t i=1; i<target.size(); i++){
            //Add extra operations only when height increases
            ops+=max(0, target[i]-target[i-1]);
        }

        return ops;
    }
};

//Test function to verify the solution
void runTest(vector<int> target, int expected, string testName){
    Solution sol;
    int result=sol.minNumberOperations(target);

    cout<<testName<<":";
    cout<<"Input: [";
    for (size_t i=0; i<target.size(); i++){
        cout<<target[i];
        if (i<target.size()-1)cout<<", ";
    }
    cout<<"] ->";

    if (result==expected){
        cout<<"PASS (Result:"<<result<<")"<<endl;
    }else{
        cout<<"Fail (Expected: "<<expected<<", Got:"<<result<<")"<<endl;
    }
}

int main(){

    //Test Case 1: From the example
    runTest({1, 2, 3, 2, 1}, 3, "Test 1");

    //Test case 2: From the examples
    runTest({3, 1, 5, 4, 2}, 7, "Test 2");

    //Test case 3: Single element
    runTest({5}, 5, "Test 3");

    //Test case 4: All same elements
    runTest({3, 3, 3, 3}, 3, "Test 4");

    //Test Case 5: Strictly increasing
    runTest({1, 2, 3, 4, 5}, 5, "Test 5");

    //Test Case 6: Strictly decreasing
    runTest({5, 4, 3, 2, 1}, 5, "Test 6");

    //Test Case 7: Multiple peaks
    //ops=1+mac(0, 3-1)+ max(0, 2-3) + max(0, 4-2)+ max(0, 1-4)
    //ops=1+2+0+2+0=5
    runTest({1, 3, 2, 4, 1}, 5, "Test 7");

    //Test Case 8: Large values
    //ops=100+max(0, 50-100)+max(0, 200-50)+max(0, 150-200)
    //ops=100+0+150+0=250
    runTest({100, 50, 200, 150}, 250, "Test 8");

    cout<<"The Solution uses a greedy approach:"<<endl;
    cout<<"1. Start with ops=target[0](operations to reach first element)"<<endl;
    cout<<"2. For each subsequent element:"<<endl;
    cout<<"- If target[i]> target[i-1]: add (target[i]-targe[i-1]) new operations"<<endl;
    cout<<" - If target[i]<=target[i-1]: No new operations needed"<<endl;
    cout<<"3. This works because we only need nw operations when height increases"<<endl;

    return 0;
}