#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector <vii> AdjList;
vector <bool> dfs_visited;

void dfs(int u) {
	dfs_visited[u] = true;
	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		ii v = AdjList[u][i];			
		if (dfs_visited[v.first] == false) {
			dfs(v.first);
		}
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
		AdjList.push_back(current);
	}
	dfs_visited.assign(V,false);
	for (int i = 0; i < AdjList.size(); i++) {
		if (!dfs_visited[i]) {
			dfs(i);
		}
	}
}
