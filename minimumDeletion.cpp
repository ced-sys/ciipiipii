#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution{
public:
    int minimumDeletions(string word, int k){
        unordered_map<char, int> freqMap;
        for(char c: word){
            freqMap[c]++;
        }

        vector<int> frequencies;
        for (auto& p: freqMap){
            frequencies.push_back(p.second);
        }

        sort(frequencies.begin(), frequencies.end());
        int n=frequencies.size();
        int minDeletions=INT_MAX;

        for(int i=0; i<n; ++i){
            int base=frequencies[i];
            int totalDeletions=0;

            for (int j=0; j<i; ++j){
                totalDeletions+=frequencies[j];
            }

            for(int j=i+1; j<n; ++j){
                if (frequencies[j]> base+k){
                    totalDeletions+=frequencies[j]-(base+k);
                }
            }

            minDeletions=min(minDeletions, totalDeletions);
        }

        return minDeletions;
    }
};

int main(){
    Solution sol;
    string word="aabcaba";
    int k=0;
    cout<<sol.minimumDeletions(word, k)<<endl;
    return 0;
}