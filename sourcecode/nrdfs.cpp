#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector <vi> AdjList;

vector <bool> dfs_visited;

void nrdfs(int u) {
	dfs_visited[u] = true;
	stack<ii> myStack;
	int pos = 0;
	int i = u;
	while (!myStack.empty() || pos < AdjList[i].size()) {
		if (pos < (int) AdjList[i].size()) {
			int v = AdjList[i][pos];
			if (dfs_visited[v] == false) {
				ii p (i, pos + 1);
				myStack.push(p);
				i = v;
				pos = 0;
				dfs_visited[v] = true;
				cout << i;
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
			nrdfs(i);
		}
	}
}
