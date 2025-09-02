#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxEvents(vector<int>>& events){
        //Step 1: Sort events by start day
        sort(events.begin(), events.end());

        //min-heap to store end days of active events
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n=events.size();
        int day=0, index=0, result=0;

        //Step 2: Loop while events remain or heap is not empty
        while(index<n || !minHeap.empty()){
            //If no events are active, jump to the next event's start day
            if (minHeap.empty()){
                day=events[index][0];
            }

            //Step 3: Push all events that start on or before current day
            while(index <n && events[index][0]<= day){
                minHeap.push(events[index][1]); //Push end day
                index++;
            }

            //Step 4: Attend the event that ends earliest
            minHeap.pop();
            result++;
            day++;

            //Step 5: Remove all expired events
            while(!minHeap.empty() && minHeap.top()<day){
                minHeap.pop();
            }
        }
        return result;


    }
};

int main(){
    Solution sol;
    vector<vector<int>> events={{1,2}, {2, 3}, {3, 4}};
    cout<<"Maximum events that can be attended:"<<sol.maxEvents(events)<<endl;
    return 0;
}