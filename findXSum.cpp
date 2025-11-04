#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> freq;
        
        // Multiset with custom comparator: sort by (-frequency, -value)
        auto cmp = [&](int a, int b) {
            if (freq[a] != freq[b]) 
                return freq[a] > freq[b];  // Higher frequency first
            return a > b;  // Higher value first for ties
        };
        
        // Using multiset with custom comparator
        multiset<int, decltype(cmp)> ordered(cmp);
        
        vector<int> answer;
        
        // Helper to compute x-sum from current window
        auto computeSum = [&]() -> long long {
            long long sum = 0;
            int count = 0;
            for (int num : ordered) {
                if (count >= x) break;
                sum += (long long)num * freq[num];
                count++;
            }
            return sum;
        };
        
        // Build first window
        for (int i = 0; i < k; i++) {
            int num = nums[i];
            
            // Remove old entry if exists
            if (freq[num] > 0) {
                ordered.erase(ordered.find(num));
            }
            
            freq[num]++;
            ordered.insert(num);
        }
        
        answer.push_back(computeSum());
        
        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            int out_num = nums[i - k];
            int in_num = nums[i];
            
            // Remove outgoing element
            ordered.erase(ordered.find(out_num));
            freq[out_num]--;
            if (freq[out_num] > 0) {
                ordered.insert(out_num);
            }
            
            // Add incoming element
            if (freq[in_num] > 0) {
                ordered.erase(ordered.find(in_num));
            }
            freq[in_num]++;
            ordered.insert(in_num);
            
            answer.push_back(computeSum());
        }
        
        return answer;
    }
};

int main(){
	Solution sol;
	vector<int> nums={1,1,2,2,3,4,2,3};
	int k=6, x=2;

	vector<int> result=sol.findXSum(nums, k, x);

	cout<<"Result: [";
	for(int i=0; i<result.size(); i++){
		cout<<result[i];
		if (i<result.size()-1)cout<<", ";
	}
	cout<<"]\n";

	return 0;
}
