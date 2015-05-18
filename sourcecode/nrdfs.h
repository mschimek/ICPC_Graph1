bool dfs_visited[AdjMatrix.size()] = {0};

nrdfs(int u) {
	stack myStack;
	myStack.push(u);
	int current;
	while(!myStack.empty()){
		current = myStack.top();
		myStack.pop();
		for(int i = 0; i < (int) AdjList.size(); i++) {
			if(AdjList[current][i] == 1 && 
			dfs_visited[i] == false) { 
				myStack.push(i);
				visit_table[i] = true;
				// possibly do something
			}
		}
	}
}

for (int i = 0; i < AdjList.size(); i++) {
	if (dfs_visited[i] == false) {
		nrdfs(i);
	}
}