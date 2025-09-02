#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        if (word.empty()) return 0;

        // Step 1: Group consecutive characters
        vector<int> groups;
        int count = 1;

        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        // Step 2: Compute total combinations without the k-limit
        long long total = 1;
        for (int num : groups) {
            total = (total * num) % MOD;
        }

        // Step 3: Early return if k is larger than any group
        int sumGroups = 0;
        for (int g : groups) sumGroups += g;
        if (k >= sumGroups) return total;

        // Step 4: DP to count invalid combinations
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;

        for (int num : groups) {
            vector<long long> new_dp(k + 1, 0);
            long long sum_val = 0;

            for (int s = 0; s <= k; ++s) {
                if (s > 0) {
                    sum_val = (sum_val + dp[s - 1]) % MOD;
                }

                if (s > num) {
                    sum_val = (sum_val - dp[s - num - 1] + MOD) % MOD;
                }

                new_dp[s] = sum_val;
            }

            dp = new_dp;
        }

        long long invalid = 0;
        for (int i = 0; i <= k; ++i) {
            invalid = (invalid + dp[i]) % MOD;
        }

        return (total - invalid + MOD) % MOD;
    }
};

int main() {
    Solution sol;
    cout << sol.possibleStringCount("aaabbb", 2) << endl; // Output: 4
    cout << sol.possibleStringCount("abc", 1) << endl;    // Output: 1
    cout << sol.possibleStringCount("aaaa", 2) << endl;   // Output: 3
    return 0;
}
