#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution{
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
    vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
        //Keep track of boxes we have and keys we have
        unordered_set<int> haveBoxes(initialBoxes.begin(), initialBoxes.end());
        unordered_set<int> haveKeys;

        //Keep track of visited boxes to avoid processing them again
        unordered_set<int> visited;

        //Queue for BFS- contains boxes we can currently open
        queue<int> q;

        //Add initially openable boxes to queue
        for (int box: initialBoxes){
            if(status[box]==1){
                q.push(box);
            }
        }

        int totalCandies=0;

        while(!q.empty()){
            int currentBox=q.front();
            q.pop();

            //Skip if already visited 
            if (visited.count(currentBox)){
                continue;
            }

            visited.insert(currentBox);

            //collect candies from current box
            totalCandies+= candies[currentBox];

            //Get keys from current box
            for (int key: keys[currentBox]){
                haveKeys.insert(key);
            }

            //Get contained boxes from current box
            for (int box: containedBoxes[currentBox]){
                haveBoxes.insert(box);
            }

            //Check if we can now open any new boxes
            //We need to check all boxes we have 
            //Because we might have gotten a key that opens a box we already had
            for (int box: haveBoxes){
                if(!visited.count(box)){
                    //can open if box is initially open OR we have the key
                    if (status[box]==1 || haveKeys.count(box)){
                        q.push(box);
                    }
                }
            }
        }
        return totalCandies;
    }

    //Alternative implementation using iterative approach
    int maxCandiesAlternative(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
    vector<vector<int>>& containedBoxes, vector<int>& initialBoxes){
        unordered_set<int> haveBoxes(initialBoxes.begin(), initialBoxes.end());
        unordered_set<int> haveKeys;
        unordered_set<int> visited;
        int totalCandies=0;

        //Keep trying until no more progress can be made
        bool changed=true;
        while(changed){
            changed=false;

            //Find boxes we can open but haven't visited yet
            vector<int> openableBoxes;
            for (int box: haveBoxes){
                if (!visited.count(box)&& (status[box]==1|| haveKeys.count(box))){
                    openableBoxes.push_back(box);
                }
            }

            for(int box: openableBoxes){
                visited.insert(box);
                totalCandies+=candies[box];

                //Collect keys
                for(int key: keys[box]){
                    haveKeys.insert(key);
                }

                //Collect contained boxes
                for (int containedBox: containedBoxes[box]){
                    haveBoxes.insert(containedBox);
                }
                changed=true;
            }
        }
        return totalCandies;
    }
};

//Test function
void testSolution(){
    Solution solution;

    //Test case 1
    vector<int> status1={1, 0, 1, 0};
    vector<int> candies1={7, 5, 4, 9};
    vector<vector<int>> keys1={{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes={{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes={0};

    int result1_bfs=solution.maxCandies(status1, candies1, keys1, containedBoxes, initialBoxes);
    int result1_alt=solution.maxCandiesAlternative(status1, candies1, keys1, containedBoxes, initialBoxes);
    cout<<"Test 1- BFS:"<<result1_bfs<<", Alternative: "<<result1_alt<<endl;
    //Expected: 25 (boxes 0, 2, 1, 3-> candies 7+4+5+9=25)

    //Test case 2
    vector<int> status2={1, 0, 0, 0, 0, 0};
    vector<int> candies2={1, 1, 1, 1, 1, 1};
    vector<vector<int>> keys2={{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
    vector<vector<int>> containedBoxes2={{}, {}, {}, {}, {}, {}};
    vector<int> initialBoxes2={0};

    int result2_bfs=solution.maxCandies(status2, candies2, keys2, containedBoxes2, initialBoxes2);
    int result2_alt=solution.maxCandiesAlternative(status2, candies2, keys2, containedBoxes2, initialBoxes2);
    cout<<"Test 2- BFS:"<<result2_bfs<<", Alternative:"<<result2_alt<<endl;
    //Expected: 6 (all boxes)

    //Test case 3
    vector<int> status3={1, 1, 1};
    vector<int> candies3={100, 1, 100};
    vector<vector<int>> keys3={{}, {0, 2}, {}};
    vector<vector<int>> containedBoxes3={{}, {}, {}};
    vector<int> initialBoxes3={1};

    int result3_bfs=solution.maxCandies(status3, candies3, keys3, containedBoxes3, initialBoxes3);
    int result3_alt=solution.maxCandiesAlternative(status3, candies3, keys3, containedBoxes3, initialBoxes3);
    cout<<"Test 3- BFS:"<<result3_bfs<<", Alternative:"<< result3_alt<<endl;
    //expected: 201 (all boxes)
}

int main(){
    testSolution();
    return 0;
}