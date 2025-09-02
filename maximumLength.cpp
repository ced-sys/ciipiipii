#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int maximumLength(vector<int>& nums){
        int max_len=1, curr_len=1;

        for(int i=1; i<nums.size(); ++i){
            if ((nums[i]%2)!=(nums[i-1]%2)){
                curr_len++;
                max_len=max(max_len, curr_len);
            }else{
                curr_len=1;
            }
        }
        return max_len;
    }
};