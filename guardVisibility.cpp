#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize grid: 0 = empty, 1 = guard, 2 = wall, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        
        // Mark walls
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Process each guard's visibility
        for (const auto& guard : guards) {
            int r = guard[0];
            int c = guard[1];
            
            // Extend visibility in all 4 directions
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                
                // Continue until hitting a wall, guard, or boundary
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                       grid[nr][nc] != 1 && grid[nr][nc] != 2) {
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 3;  // Mark as guarded
                    }
                    nr += dr;
                    nc += dc;
                }
            }
        }
        
        // Count unguarded empty cells
        int count = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    // Helper function to visualize the grid
    void printGrid(int m, int n, const vector<vector<int>>& grid) {
        cout << "\n📊 Grid Visualization:\n";
        cout << "G = Guard, W = Wall, * = Guarded, . = Unguarded\n\n";
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) cout << ". ";
                else if (grid[r][c] == 1) cout << "G ";
                else if (grid[r][c] == 2) cout << "W ";
                else cout << "* ";  // guarded
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Method that also returns the grid for visualization
    int countUnguardedWithVisualization(int m, int n, vector<vector<int>>& guards, 
                                        vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (const auto& guard : guards) {
            int r = guard[0];
            int c = guard[1];
            
            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                       grid[nr][nc] != 1 && grid[nr][nc] != 2) {
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 3;
                    }
                    nr += dr;
                    nc += dc;
                }
            }
        }
        
        // Print the grid
        printGrid(m, n, grid);
        
        int count = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    cout << "🧩 Guard Visibility Problem - Test Cases\n";
    cout << "=========================================\n\n";
    
    // Test case 1
    cout << "Test Case 1:\n";
    int m1 = 4, n1 = 6;
    vector<vector<int>> guards1 = {{0,0}, {1,1}, {2,3}};
    vector<vector<int>> walls1 = {{0,1}, {2,2}, {1,4}};
    
    int result1 = sol.countUnguardedWithVisualization(m1, n1, guards1, walls1);
    cout << "✅ Unguarded cells: " << result1 << endl;
    cout << "\n-----------------------------------------\n";
    
    // Test case 2
    cout << "\nTest Case 2:\n";
    int m2 = 3, n2 = 3;
    vector<vector<int>> guards2 = {{1,1}};
    vector<vector<int>> walls2 = {{0,1}, {1,0}, {2,1}, {1,2}};
    
    int result2 = sol.countUnguardedWithVisualization(m2, n2, guards2, walls2);
    cout << "✅ Unguarded cells: " << result2 << endl;
    cout << "\n-----------------------------------------\n";
    
    // Test case 3: Empty grid with one guard
    cout << "\nTest Case 3: Single guard, no walls\n";
    int m3 = 5, n3 = 5;
    vector<vector<int>> guards3 = {{2,2}};
    vector<vector<int>> walls3 = {};
    
    int result3 = sol.countUnguardedWithVisualization(m3, n3, guards3, walls3);
    cout << "✅ Unguarded cells: " << result3 << endl;
    
    return 0;
}