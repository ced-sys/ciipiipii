#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:end
	int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>&startTime, vector<int>& endTime){
		vector<int> gap;
		int n=startTime.size();

		//Step 1: Contrast gap array
		gap.push_back(startTime[0]); //gap before first meeting
		for (int i=1; i<n; ++i)
			gap.push_back(startTime[i]-endTime[i-1]);

		gap.push_back(eventTime-endTime[n-1]); //go after last meeting
		
		//Step 2: largest gap to the right
		int m=gap.size();
		vector<int> largestRight(m, 0);
		for(int i=m-2; i>=0; --i)
			largestRight[i]=max(largestRigt[i+1], gap[i+1]);

		//Step 3: Try replacing one meeting to maximize free time
		int ans=0, largestLeft=0;
		for (int i=1; i<m; ++i){
			int curGap=endTime[i-1]-startTime[i-1];
			if(curGap <=max(largestLeft, largestRight[i]))
				ans=max(ans, gap[i-1]+ gap[i]+curGap);
			else
				ans=max(ans, gap[i-1]+gap[i]);

			largestLeft=max(largestLeft, gap[i-1]);
		}

		return ans;
	}
};

//Test
int main() {
	Solution sol;
	int eventTime=10;
	vector<int> startTime={1, 3};
	vector<int> endTime={2, 5};
	cout<<sol.maxFreeTime(eventTime, startTime, endTime)<<endl;
	return 0;
}

