#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};

// --------------------- Test Function -----------------------
void runTest(vector<int> nums, int key, int k, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "Input: [";
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << (i < nums.size() - 1 ? "," : "");
    cout << "], key = " << key << ", k = " << k << endl;

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << (i < result.size() - 1 ? "," : "");
    cout << "]" << endl;

    cout << "Expected: [";
    for (int i = 0; i < expected.size(); ++i)
        cout << expected[i] << (i < expected.size() - 1 ? "," : "");
    cout << "]" << endl;

    assert(result == expected);
    cout << "✅ Test Passed!\n" << endl;
}

// --------------------- Main -----------------------
int main() {
    runTest({3, 4, 9, 1, 3, 9, 5}, 9, 1, {1, 2, 3, 4, 5, 6});
    runTest({2, 2, 2, 2}, 2, 2, {0, 1, 2, 3});
    runTest({1, 2, 3}, 4, 1, {});
    runTest({1, 2, 3, 9, 4, 5}, 9, 1, {2, 3, 4});
    runTest({}, 1, 0, {});

    cout << "All tests passed!\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};

// --------------------- Test Function -----------------------
void runTest(vector<int> nums, int key, int k, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "Input: [";
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << (i < nums.size() - 1 ? "," : "");
    cout << "], key = " << key << ", k = " << k << endl;

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << (i < result.size() - 1 ? "," : "");
    cout << "]" << endl;

    cout << "Expected: [";
    for (int i = 0; i < expected.size(); ++i)
        cout << expected[i] << (i < expected.size() - 1 ? "," : "");
    cout << "]" << endl;

    assert(result == expected);
    cout << "✅ Test Passed!\n" << endl;
}

// --------------------- Main -----------------------
int main() {
    runTest({3, 4, 9, 1, 3, 9, 5}, 9, 1, {1, 2, 3, 4, 5, 6});
    runTest({2, 2, 2, 2}, 2, 2, {0, 1, 2, 3});
    runTest({1, 2, 3}, 4, 1, {});
    runTest({1, 2, 3, 9, 4, 5}, 9, 1, {2, 3, 4});
    runTest({}, 1, 0, {});

    cout << "All tests passed!\n";
    return 0;
}

