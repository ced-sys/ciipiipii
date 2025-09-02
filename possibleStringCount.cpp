#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int count = n;

        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                count--;
            }
        }

        return count;
    }
};

// Optional test
int main() {
    Solution sol;
    cout << sol.possibleStringCount("abbcccc") << endl;  // Expected: 4
    cout << sol.possibleStringCount("abcd") << endl;     // Expected: 4
    cout << sol.possibleStringCount("aaaa") << endl;     // Expected: 1
    cout << sol.possibleStringCount("a") << endl;        // Expected: 1
    cout << sol.possibleStringCount("aabbaa") << endl;   // Expected: 4
    cout << sol.possibleStringCount("abcabcabc") << endl;// Expected: 9
    return 0;
}
