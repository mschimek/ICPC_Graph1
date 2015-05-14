#include <iostream>
#include <vector>
using namespace std;

bool dfs_visited[AdjMatrix.size()] = {0};

void dfs(int u) {
	dfs_visited[u] = true;
	// possibly do something
	for (int i = 0; i < AdjMatrix[u].size(); i++) {
		if (AdjMatrix[u][i] == 1 
			&& dfs_visited[i] == false) {
			dfs(i);
		}
	}
}

for (int i = 0; i < AdjMatrix.size(); i++) {
	if (dfs_visited[i] == false) {
		dfs(i);
	}
}

int main()
{
	int AdjMatrix[5][5];
	int counter;
	cin >> counter;
	for (int i = 0; i < counter; i++) {
		int a;
		cin >> a;
		int b;
		cin >> b;
		AdjMatrix[a][b] = 1;
		AdjMatrix[b][a] = 1;
	}

	int c; 
	cin >> c;
	dfs(c);	
	dfs(c);	
	
}
