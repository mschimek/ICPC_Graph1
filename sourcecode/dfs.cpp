#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vector <vi> AdjList;
vector <bool> dfs_visited;

void dfs(int u) {
	dfs_visited[u] = true;
	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];			
		if (dfs_visited[v] == false) {
			dfs(v);
		}
	}
}

int main() {
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		vi current;
		int edges;
		cin >> edges;
		for (int j = 0; j < edges; j++) {
			int cur;
			cin >> cur;
			current.push_back(cur);	
		}
		AdjList.push_back(current);
	}
	dfs_visited.assign(V,false);
	for (int i = 0; i < AdjList.size(); i++) {
		if (!dfs_visited[i]) {
			dfs(i);
		}
	}
}
