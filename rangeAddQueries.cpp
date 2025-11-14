/* You are given a positive integer `n`, indicating that we initially have an `nxn` 0-indexed matrix `mat` filled with zeroes. 
 *
 * You are also given a 2D integer array query. For eac `query[i]=[row1i, col1i, row2i, col2]`, you should do the following operation:
 *
 * Add `1`to every element in the submatrix with the top left corner `(row2i, col2i)`. That is, add `1` to `mat[x][y]` for all `row1i<=x<=row2i` and `col1i<=y<=col2i`
 *
 * Return the matrix mat after performing every query
 * */


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries){
	vector<vector<int>> diff(n+1, vector<int>(n+1, 0));

	for (auto &q: queries){
		int r1=q[0], c1=q[1], r2=q[2], c2=q[3];

		diff[r1][c1]+=1;

		if (c2+1<n) diff[r1][c2+1]-=1;
		if (r2+1<n) diff[r2+1][c1]-=1;
		if (r2+1<n && c2+1<n) diff[r2+1][c2+1]+=1;
	}

	vector<vector<int>> mat(n, vector<int>(n, 0));

	for (int i=0; i<n; i++){
		int rowSum=0;
		for(int j=0; j<n; j++){
			rowSum+=diff[i][j];
			if(i>0) mat[i][j]=mat[i-1][j] + rowSum;
			else mat[i][j]=rowSum;
		}
	}
	return mat;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cout<<"Enter n:";
	cin>>n;

	int q;
	cout<<"Enter number of queries: ";
	cin>>q;

	vector<vector<int>> queries(q, vector<int>(4));

	cout<<"Enter queries (row1 col1 row2 col2): \n";
	for(int i=0; i<q; i++){
		cin>> queries[i][0] >>queries[i][1]>> queries[i][2]>>queries[i][3];
	}

	vector<vector<int>> result=rangeAddQueries(n, queries);

	cout<<"\nResulting matrix: \n";
	for(auto &row: result){
		for(auto &val : row){
			cout<<val<<" ";
		}
		cout<< "\n";
	}
	return 0;
}
