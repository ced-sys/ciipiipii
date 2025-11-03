#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution{
public:
	int minCost(string colors, vector<int>& neededTime){
		int total=0;
		int prev=0;

		for(int i=1; i<colors.size(); i++){
			if (colors[i]==colors[prev]){
				if (neededTime[i]<neededTime[prev]){
					total+=neededTime[i];
				}else{
					total+=neededTime[prev];
					prev=i;
				}
			}else{
				prev=i;
			}
		}
		return total;
	}
};

void runTests(){
	Solution sol;
	{
		string colors="aab";
		vector<int> neededTime={1, 2, 3};
		int result=sol.minCost(colors, neededTime);
		assert(result==1);
		cout<<"Test 1 Passed: 2 consecutive colors\n";
	}
}
int main(){
	runTests();
	return 0;
}
