#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector <vii> AdjList;

vector <bool> dfs_visited;

void nrdfs(int u) {
	dfs_visited[u] = true;
	stack<ii> myStack;
	int pos = 0;
	int i = u;
	while (!myStack.empty() || pos < AdjList[i].size()) {
		if (pos < (int) AdjList[i].size()) {
			ii v = AdjList[i][pos];
			if (dfs_visited[v.first] == false) {
				ii p (i, pos + 1);
				myStack.push(p);
				i = v.first;
				pos = 0;
				dfs_visited[v.first] = true;
			} else {
				pos++;
			}
		} else {
			ii p = myStack.top();
			myStack.pop();
			i = p.first;
			pos = p.second;
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
			nrdfs(i);
		}
	}
}
