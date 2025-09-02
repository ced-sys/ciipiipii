#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        queue<pair<int, int>> q; // {current square, moves}
        vector<bool> visited(n * n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            for (int dice = 1; dice <= 6; ++dice) {
                int next = curr + dice;
                if (next > target) continue;

                auto [row, col] = getCoordinates(next, n);

                // If there's a ladder or snake, take it
                int destination = board[row][col] != -1 ? board[row][col] : next;

                if (destination == target) return moves + 1;

                if (!visited[destination]) {
                    visited[destination] = true;
                    q.push({destination, moves + 1});
                }
            }
        }

        return -1; // Not reachable
    }

private:
    // Convert square number (1-indexed) to board coordinates (0-indexed)
    pair<int, int> getCoordinates(int square, int n) {
        square--; // Convert to 0-indexed
        int rowFromBottom = square / n;
        int col = square % n;

        if (rowFromBottom % 2 == 1) {
            col = n - 1 - col; // Zigzag pattern
        }

        int row = n - 1 - rowFromBottom;
        return {row, col};
    }
};

// Optional: helper to debug square mapping
void printBoardMapping(int n) {
    Solution sol;
    cout << "Board mapping for " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int s = 1; s <= n * n; ++s) {
                auto [r, c] = sol.getCoordinates(s, n);
                if (r == i && c == j) {
                    cout << s << "\t";
                    break;
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    Solution solution;

    // Test case 1: direct ladder from square 2 to target (6)
    vector<vector<int>> board1 = {
        {-1, -1, -1},
        {-1, 9, 8},
        {-1, 8, 9}
    };
    cout << "Test Case 1 (Expected 1): " << solution.snakesAndLadders(board1) << "\n";

    // Test case 2: LeetCode example
    vector<vector<int>> board2 = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    cout << "Test Case 2 (Expected 4): " << solution.snakesAndLadders(board2) << "\n";

    return 0;
}
