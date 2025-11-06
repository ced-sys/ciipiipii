/* **PROBLEM**
 * You are given an integer `c` representing `c` power stations, each with a unique identifier `id` from 1 to `c` (1-based indexing).
 * These stations are interconnected via `n` bidirectional cables, represented by a 2D array `connections` where each element `connections[i]=[u1, v1]`indicates a connection between station `u1` and station `v1` stations that are directly or indirectly connected from the power grid. 
 *
 * Initially all stations are online (operational)
 *
 * You are also given a 2D array `queries` where each query is one of the following types:
 * 	 `[1,x]`: A maintenance check is requested for station `x`. If station `x` is online, it resolves the check by itself. If station `x` is offline, the check is resolved by the operational station with the smallest `id` in the same power grid as `x`. If no operational station exists in that grid, then return -1.
 *
 * 	 `[2, x]`: Station `x` goes offline. 
 *
 * Return an array of integers representing the results of each query of type `[1, x]` in the order they appear */

#include <bits/stdc++.h>
using namespace std;

/* 
 * DISJOINT SET UNION (Union-Find data structure)
 *
 * This class efficiently keeps trakc of which stations belong to the same component (power grid).
 *
 * Operations:
 *  	- find(X): returns the representative (root) of x's component.
 *  	-unite (a, b); meres the components of a and b.
 * */

class DSU{
public:
	vector<int> parent; //parent[i]=represntative of station i
	vector<int> rank; //rank[i]=approximate tree depth (for union optimization)
	//Constructor: Initialize `n` stations, each in its own set
	DSU(int n){
		parent.resize(n+1);
		rank.assign(n+1, 0);
		iota(parent.begin(), parent.end(), 0); //parent[i]=i
		}
	//Path compression: recursively find root and compress paths
	int find(int x){
		if (x!=parent[x])
			parent[x]=find(parent[x]);
		return parent[x];
	}

	//Union by rank: attach smaller tree under larger one
	void unite(int a, int b){
		a=find(a);
		b=find(b);
		if (a==b) return; //already in the same component

		if (ran[a]<rank[b]) swap (a,b);
		parent[b]=a;
		if(rank[a]==rank[b])rank[a]++;
	}
};

/* 
 * POWER GRID MAINTENANCE QUERY PROCESSOR
 *
 * Given:
 * 	- c stations (1..c)
 * 	-connections between them (bidirectional)
 * 	-queries describing maintanance checks and shutdowns
 *
 * * QUERY TYPES:
 * 	[1, x]-> maintenance check at station x
 * 		-if x is online -> x handles it -> return x
 * 		-if x is offline -> find the smallest online station in the same grid -> return its ID
 * 		- if no online station -> return -1
 * 	[2, x]-> mark station x as offline.
 *
 * Returns:
 * 	A vector of resuts corresponding to all [1, x] queries.
 *
 * */

class Solution{
public:
	vector<int> powerQueries(
			int c, //number of stations
			vector<vector<int>>& connections, // connections between stations
			vector<vector<int>>& queries //maintenance/offline queries
			}{
			//Step 1: Build grids (connected components) using DSU
			DSU dsu(c);
			for (auto& e : connections)
				dsu.unite(e[0], e[1]);

			//Step 2: For each grid (component root), store a sorted set
			//of all currently online stations (to get smallest ID easily)
			unordered_map<int, set<int>> gridOnline;
			for(int i=1; i<=c; i++)
				gridOnline[dsu.find(1)].insert(i);

			//Step3: Kepp track of online/offline status
			vector<bool> online(c+1, true);

			//Step 4: Result array for all tpe [1, x] queries
			vector<int> result;

			//Step 5: Process queries in order
			for (auto& q: queries){
				int type=q[0];
				int x=q[1];
				int root=dsu.find(x); //find grid representative for statistics
				//Maintenacne check
				if (type==1){
					if (online[x]){
						//x is online -> resolves its own check
						result.push_back(x);
					}else{
						//x is offline -> check smallest online stations in same grid
						if (gridOnline[root].empty())
							result.push_back(-1); // no online station
							else
								result.push_back(*gridOnline[root].begin()); //smallest ID
					}
				}

				//Station goes offline
				else if (type==2){
					if (online[x]){
						//Remove from its grid's online set and mark as offline
						gridOnline[root].erase(x);
						online[x]=false;
					}
				}

				return result;
			}
			
		};
