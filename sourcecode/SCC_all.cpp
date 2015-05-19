#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int UNVISITED = -1;
vector <vii> AdjacenceList;
int dfsNumberCounter = 0;
int numSCC = 0;

vi dfs_num, dfs_low, S, visited;   // store infos;


void findSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // initalize
	S.push_back(u); visited[u]  = 1; // S is Stack
	
	for (int j = 0; j < AdjacenceList[u].size(); j++) {
		ii v = AdjacenceList[u][j]; // Pair
		if (dfs_num[v.first] == UNVISITED) // not yet visited by DFS
			findSCC(v.first);
		if (visited[v.first]) // belongs to current SCC
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);	
	}
	if (dfs_low[u] == dfs_num[u]) { // root of current SCC 
		cout << "SCC " << ++numSCC; // print vertices in SCC
		while(true) { 
			int v = S.back(); S.pop_back(); visited[v] = 0;
			cout << " " <<v;
			if (u == v) break;	
		}
		cout << endl;
	}
}

int main() {
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		vii current;
		int edges;
		cin >> edges;
		for (int j = 0; j < edges; j++) {
			int cur;
			cin >> cur;
			current.push_back(ii(cur,0));	
		}
		AdjacenceList.push_back(current);
	}
	dfs_num.assign(V,UNVISITED); dfs_low.assign(V,0); visited.assign(V,0); 
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < V; i++) {
		if (dfs_num[i] == UNVISITED)
			findSCC(i);
	}
	
}