#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long createPalindrome(long long num, bool odd) {
        long long x = num;
        if (odd) x /= 10;
        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }
    
    bool isPalindrome(long long num, int base) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % base);
            num /= base;
        }
        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--]) return false;
        }
        return true;
    }
    
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        
        for (long long len = 1; count < n; len *= 10) {
            // Generate odd-length palindromes
            for (long long i = len; count < n && i < len * 10; i++) {
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k)) {
                    sum += p;
                    count++;
                }
            }
            
            // Generate even-length palindromes
            for (long long i = len; count < n && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k)) {
                    sum += p;
                    count++;
                }
            }
        }
        
        return sum;
    }
};

// Test function
int main() {
    Solution sol;
    
    // Test cases
    cout << "k=2, n=5: " << sol.kMirror(2, 5) << endl;  // Expected: 25
    cout << "k=3, n=7: " << sol.kMirror(3, 7) << endl;  // Expected: 499
    cout << "k=7, n=17: " << sol.kMirror(7, 17) << endl; // Expected: 20379000
    
    return 0;
}