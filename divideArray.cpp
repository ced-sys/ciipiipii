#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        // Step 2: Traverse in chunks of 3
        for (int i = 0; i < nums.size(); i += 3) {
            // Make sure we don't go out of bounds
            if (i + 2 >= nums.size()) {
                return {};
            }

            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];

            // Step 3: If difference is more than k, return empty result
            if (c - a > k) {
                return {};
            }

            // Step 4: Add valid triplet to result
            result.push_back({a, b, c});
        }

        return result;
    }
};

// 🔍 Optional: Quick main() function to test
int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 9, 10, 12};
    int k = 3;

    vector<vector<int>> result = sol.divideArray(nums, k);

    for (const auto& triplet : result) {
        for (int n : triplet) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
