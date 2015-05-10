void findSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // initalize
	S.push_back(u);  visited[u]  = 1;
		
	for (int j = 0; j < AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if (dfs_num[v.first] == UNVISITED) // not visited by DFS
			findSCC(v.first);		
		if (visited[v.first])  // belongs to current SCC
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);	
	}
	
	if (dfs_low[u] == dfs_num[u]) { // root of SCC reached
		cout << "SCC " << ++numSCC;
		while(true) {    // print vertices in SCC
			int v = S.back(); S.pop_back(); visited[v] = 0;
			cout << " " <<v;
			if (u == v) 
				break;
		}
		cout << endl;
	}
}
