#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    //Check if sub* k is a subsequence of s
    bool isK(const string& sub, const string& s, int k){
        int count=0, i=0;
        for(char ch: s){
            if(i<sub.size()&& ch==sub[i]){
                i++;
                if (i==sub.size()){
                    count++;
                    i=0;
                    if(count==k) return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k){
        string res="";
        queue<string> q;
        q.push("");

        while(!q.empty()){
            string curr=q.front();
            q.pop();

            for(char ch='a'; ch<='z'; ++ch){
                string next=curr+ch;
                if(isK(next, s, k)){
                    //Update the resultif the new string is longer
                    //or equal length but lex greater but lex greater
                    if (next.size()>res.size()||
                (next.size()==res.size()&&next>res)){
                    res=next;
                }
                q.push(next);
                }
            }
        }
        return res;
    }
};

//Test
int main(){
    Solution sol;
    string s="letsleetcode";
    int k=2;
    cout<<sol.longestSubsequenceRepeatedK(s, k)<<endl; //Expected: 'ete; or 'let'
    return 0;
}