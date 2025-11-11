/* You are given an array of binary strings `strs` and two integers `m` and `n`. Return the size of the largest subset of `strs` such that there are at most `m`0s and 1's in the subset.
 *
 * A set `x` is a subset of a set `y` if all elements of `x` are also element of `y`.
 *
 *
 * **SOLUTION**
 * An array of binary strings `strs` (each containing only `0` and `1`) 
 * Two integers `m` and `n`
 *
 * You must return the maximum size of a subset of `strs` such that:
 * 	* The total number of `0` characters used is at most `m`.
 * 	* The total number of `1` characters used is at most `n`.
 *
 * **EXAMPLE**
 * 	* subset["10", "0001", "1", "0"]
 * 	* It has 5 zeros and 3 ones-valid
 * 	* It contains 4 strings, the largest possible
 *
 * **INTUITION**
 * 	*The problem is similar to a `2D 0/1 Knapsack problem` where:
 * 		* Each string `s` is and `item`
 * 		* cout_0(s) and count_1(s) are the weights on two dimensions.
 * 		* We want to maximize the number of items (string(s)) we can take without exceeding te capacities `m` and `n`.
 *
 *
 * **DYNAMIC PROGRAMMING APPROACH**
 * 	 * We use a 2D DP array
 * 	 * `dp[i][j]`=maximum number of strings that can be formed using at most `i` zeros and `j` ones.
 * 	 * We iterate through each string, and count its zeros and update `dp` backwrds (to avoid recomputation conflicts)
 * 	 */
#include <bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n){
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for(auto& s: strs){
		int zeros=count(s.begin(), s.end(), '0');
		int ones=count(s.begin(), s.end(), '1');

		//Update backwards to avoid the same string twice
		for (int i=m; i>=zeros; --i){
			for (int j=n; j>=ones; --j){
				dp[i][j]=max(dp[i][j], dp[i-zeros][j-ones]+1);
			}
		}
	}

	return dp[m][n];
}

int main(){
	vector<string> strs={"10", "0001", "111001", "1", "0"};
	int m=5, n=3;

	cout<<findMaxForm(strs, m, n)<<endl;
	return 0;
}


