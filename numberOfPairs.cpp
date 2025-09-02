#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /* Sort points:
       * By x ascending
       * if x is equal, by y descending(This ensures for each left point A, the candidates for the right point B are ordered properly)*/

    int numberOfPairs(vector<vector<int>>& points){
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
                if (a[0]==b[0]) return a[1]>b[1];
                return a[0] < b[0];
                });

        int n=points.size(), result=0;
        
        //Loop over each point i(Candidates A):
        //* Keep track of the top y (from A)
        //* Initialize bot=-infinity (lowest boundary)
        for (int i=0; i<n; i++){
            int top=points[i][1];
            int bot=INT_MIN;

            /*
             Loop over points j>i (Candidate B):
             *Get y of B (y=points [j][1])
             *Check if this y lies within (bot, top]
             ** If yes->valid pair found->increment result, then update bot=y.
             ** If bot equals top(the rectangle fully filled), break out
             */
            for(int j=i+1; j<n; j++){
                int y=points[j][1];
                if (bot< y && y<=top){
                    result++;
                    bot=y;
                    if (bot==top) break;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;

    //Example input
    vector<vector<int>> points={{1,1}, {2,2}, {3,3}};

    //Run function
    int result=sol.numberOfPairs(points);

    //Print output
    cout<<"Number of valid pairs:"<<result<<endl;

    return 0;
}




