#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        // Try all possible starting positions
        for (int i = 0; i < n; i++) {
            int north = 0, south = 0, east = 0, west = 0;
            
            // Try all possible ending positions from current start
            for (int j = i; j < n; j++) {
                char c = s[j];
                
                // Update direction counts
                if (c == 'N') north++;
                else if (c == 'S') south++;
                else if (c == 'E') east++;
                else if (c == 'W') west++;
                
                // Calculate net displacement
                int x = abs(north - south);
                int y = abs(east - west);
                int distance = max(x, y);
                
                // Check if we can make this substring with k operations
                int substringLength = j - i + 1;
                if (substringLength <= k) {
                    ans = max(ans, distance);
                }
            }
        }
        
        return ans;
    }
};

// Test class
class TestMaxDistance {
private:
    Solution solution;
    int testCount = 0;
    int passedTests = 0;

public:
    void runTest(string s, int k, int expected, string testName) {
        testCount++;
        int result = solution.maxDistance(s, k);
        
        cout << "Test " << testCount << " (" << testName << "): ";
        cout << "s=\"" << s << "\", k=" << k;
        cout << " -> Expected: " << expected << ", Got: " << result;
        
        if (result == expected) {
            cout << " ✓ PASS" << endl;
            passedTests++;
        } else {
            cout << " ✗ FAIL" << endl;
        }
    }
    
    void runAllTests() {
        cout << "Running Max Distance Tests...\n" << endl;
        
        // Test 1: Basic case
        runTest("NSEW", 4, 1, "Basic four directions");
        
        // Test 2: Single direction
        runTest("NNNN", 4, 4, "All same direction");
        
        // Test 3: Opposing directions
        runTest("NSNS", 4, 0, "Alternating opposite directions");
        
        // Test 4: Limited operations
        runTest("NNNNSSS", 5, 4, "Limited k with mixed directions");
        
        // Test 5: Optimal substring selection
        runTest("SWNNNE", 4, 2, "Optimal substring within k");
        
        // Test 6: Edge case - k = 1
        runTest("NSEW", 1, 1, "Single operation allowed");
        
        // Test 7: Edge case - empty effective movement
        runTest("NSEW", 2, 1, "Two operations from four directions");
        
        // Test 8: Longer string
        runTest("NNNEEESSSSWWW", 6, 3, "Longer string with pattern");
        
        // Test 9: All operations used optimally
        runTest("NNNWWW", 6, 3, "All operations used");
        
        // Test 10: Mixed case requiring careful selection
        runTest("NESWNESWNESW", 8, 2, "Complex mixed pattern");
        
        cout << "\nTest Summary:" << endl;
        cout << "Passed: " << passedTests << "/" << testCount << endl;
        
        if (passedTests == testCount) {
            cout << "🎉 All tests passed!" << endl;
        } else {
            cout << "❌ Some tests failed. Please review the algorithm." << endl;
        }
    }
};

// Helper function to demonstrate the algorithm step by step
void demonstrateAlgorithm(string s, int k) {
    cout << "\n=== Algorithm Demonstration ===" << endl;
    cout << "Input: s = \"" << s << "\", k = " << k << endl;
    cout << "Finding optimal substring of length ≤ " << k << endl;
    
    Solution sol;
    int n = s.size();
    int maxDist = 0;
    string bestSubstring = "";
    int bestStart = -1, bestEnd = -1;
    
    for (int i = 0; i < n; i++) {
        int north = 0, south = 0, east = 0, west = 0;
        
        for (int j = i; j < n; j++) {
            char c = s[j];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
            
            int substringLength = j - i + 1;
            if (substringLength <= k) {
                int x = abs(north - south);
                int y = abs(east - west);
                int distance = max(x, y);
                
                cout << "Substring [" << i << "," << j << "]: \"" 
                     << s.substr(i, substringLength) << "\" -> distance = " << distance << endl;
                
                if (distance > maxDist) {
                    maxDist = distance;
                    bestSubstring = s.substr(i, substringLength);
                    bestStart = i;
                    bestEnd = j;
                }
            }
        }
    }
    
    cout << "\nBest result:" << endl;
    cout << "Substring: \"" << bestSubstring << "\" at positions [" << bestStart << "," << bestEnd << "]" << endl;
    cout << "Maximum distance: " << maxDist << endl;
}

int main() {
    // Run comprehensive tests
    TestMaxDistance tester;
    tester.runAllTests();
    
    // Demonstrate algorithm with example
    demonstrateAlgorithm("NESWNESWNESW", 8);
    
    return 0;
}