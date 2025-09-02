#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers){
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i=0, j=0, count=0;

        while (i<players.size() && j<trainers.size()){
            if (players[i]<=trainers[j]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }

        return count;
    }
};

//Simple test
int main(){
    Solution sol;

    vector<int> players={4, 7, 9};
    vector<int> trainers={5, 8, 10};

    int result=sol.matchPlayersAndTrainers(players, trainers);
    cout<< "Matched Players:"<<result<<endl;

    return 0;
}