#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k, vector<int>& operations) {
        int n = 1;  // Current length of the word
        int i = 0;  // Index to track how many operations are needed to reach length >= k

        // First, determine how many operations are needed so that string length >= k
        while (n < k) {
            n *= 2;
            i++;
        }

        int d = 0;  // Total number of cyclic shifts applied to character 'a'

        // Walk backwards through the operations to trace how the k-th character evolved
        while (n > 1) {
            if (k > n / 2) {
                // If k is in the second half of the string, then it was affected by this operation
                k -= n / 2;  // Map back to its position in the previous string
                d += operations[i - 1];  // Accumulate the shift if operation was type 1
            }
            n /= 2;  // Half the size of the word in the previous step
            i--;     // Move to the previous operation
        }

        // Compute the final character after all cyclic shifts
        return static_cast<char>((d % 26) + 'a');
    }
};

int main(){
    Solution sol;
    vector<int> ops1={0, 0, 0};
    vector<int> ops2={0, 1, 0, 1};

    cout<<sol.kthCharacter(5, ops1)<<endl; //Output: a
    cout<<sol.kthCharacter(10, ops2)<<endl; //Output: b

    return 0;
}