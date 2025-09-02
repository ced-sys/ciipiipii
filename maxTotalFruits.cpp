#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

class Solution{
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k){
        if (startPos-k>fruits.back()[0] || startPos+k<fruits[0][0])
            return 0;

        int n=fruits.size();
        vector<int> positions, prefix_sum(n);
        for(int i=0; i<n; ++i){
            positions.push_back(fruits[i][0]);
        }

        prefix_sum[0]=fruits[0][1];
        for (int i=1; i<n; ++i)
            prefix_sum[i]=prefix_sum[i-1]+fruits[i][1];

        int res=0;

        //Case 1: Left then right
        int l=lower_bound(positions.begin(), positions.end(), startPos-k)-positions.begin();
        int r=upper_bound(positions.begin(), positions.end(), startPos)-positions.begin();
        int start_pos_idx=r;

        while (l<=start_pos_idx && r <=n){
            int amount_right=k-(2*(startPos-min(startPos, fruits[l][0])));
            while(r<n && amount_right>= fruits[r][0]-startPos){
                r++;
            }

            int curr_sum=prefix_sum[r-1]-(l>0 ? prefix_sum[l-1]: 0);
            res=max(res, curr_sum);
            l++;
        }

        //Case 2: Right then left
        l=lower_bound(positions.begin(), positions.end(), startPos)-positions.begin();
        r=upper_bound(positions.begin(), positions.end(), startPos+k)-positions.begin();
        start_pos_idx=l;

        while(l>= -1 && r>=start_pos_idx){
            int amount_left=k-(2*(max(startPos, fruits[r-1][0])-startPos));
            while (l>=0 && amount_left >=startPos-fruits[l][0]){
                l--;
            }

            int curr_sum=prefix_sum[r-1]-(l>=0 ? prefix_sum[l]: 0);
            res=max(res, curr_sum);
            r--;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> fruits1={{2,4}, {4, 3}, {10, 2}};
    cout<<sol.maxTotalFruits(fruits1, 6, 4)<<endl;

    vector<vector<int>> fruits2={{0,9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    cout<<sol.maxTotalFruits(fruits2, 5, 4)<<endl;

    vector<vector<int>> fruits3={{0, 3}, {6, 4}, {8, 5}};
    cout<<sol.maxTotalFruits(fruits3, 3, 2)<<endl;

    vector<vector<int>> fruits4 ={{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}};
    cout<<sol.maxTotalFruits(fruits4, 3, 2)<<endl;

    return 0;

}