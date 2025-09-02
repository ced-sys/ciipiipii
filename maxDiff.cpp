// Here's the implementation of the Leeetcode problem 3442. Maximum difference between even and odd frequency I
#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Solution{
public:
    int maxDifference(string s){
        unordered_map<char, int> freq;

        //Count character frequencies
        for (char c: s){
            freq[c]++;
        }

        int maxOdd=INT_MIN;
        int minEven=INT_MAX;

        //Classify frequencies
        for(auto [ch, count]: freq){
            if (count % 2==1){
                maxOdd=max(maxOdd, count);
            }else{
                minEven=min(minEven, count);
            }
        }
        if (maxOdd==INT_MIN || minEven==INT_MAX){
            return 0; //Either no odd or even frequency
        }
        return maxOdd-minEven;
    }
};

//Simple test function
void runTest(string s, int expected){
    Solution sol;
    int result=sol.maxDifference(s);
    cout<< "Input: \""<<s<<"\"\n";
    cout<<"Expected:"<<expected<<", Got:"<<result<<"\n";
    cout<<(result == expected? "Passed": "Failed")<<"\n\n";
}

int main(){
    runTest("aaaaabbc", 3);
    runTest("abcabcab", 1);
    runTest("aabbcc", 0);
    runTest("abcde", 0);
    runTest("a", 0);
    return 0;
}