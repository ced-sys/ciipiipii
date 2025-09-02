#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;  // nodes in first tree
        int m = edges2.size() + 1;  // nodes in second tree

        // Build adjacency lists
        vector<vector<int>> tree1 = buildTree(edges1, n);
        vector<vector<int>> tree2 = buildTree(edges2, m);

        // For each node in tree1, calculate nodes reachable within k steps
        vector<int> reachable1(n);
        for (int i = 0; i < n; i++) {
            reachable1[i] = countReachable(tree1, i, k);
        }

        // For tree2, find the maximum nodes reachable within k-1 steps from any node
        int maxFromTree2 = 0;
        if (k > 0) {  // Only if we have steps left after crossing the bridge
            for (int i = 0; i < m; i++) {
                maxFromTree2 = max(maxFromTree2, countReachable(tree2, i, k - 1));
            }
        }

        // Result: for each node in tree1, add its reachable count + best from tree2
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = reachable1[i] + maxFromTree2;
        }

        return result;
    }

private:
    vector<vector<int>> buildTree(vector<vector<int>>& edges, int n) {
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        return tree;
    }

    int countReachable(vector<vector<int>>& tree, int start, int k) {
        if (k < 0) return 0;

        vector<bool> visited(tree.size(), false);
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        int count = 0;
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            count++;

            if (dist < k) {
                for (int neighbor : tree[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, dist + 1});
                    }
                }
            }
        }

        return count;
    }
};

// Test runner
void test() {
    Solution sol;

    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;

    vector<int> result = sol.maxTargetNodes(edges1, edges2, k);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

// Main function for VS Code
int main() {
    test();
    return 0;
}
