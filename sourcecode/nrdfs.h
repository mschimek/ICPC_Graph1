bool dfs_visited[AdjMatrix.size()] = {0};

nrdfs(int u) {
	stack myStack;
	myStack.push(u);
	int current;
	while(!myStack.empty()){
		current = myStack.top();
		myStack.pop();
		for(int i = 0; i < AdjMatrix.size(); i++){
			if(AdjMatrix[current][i] == 1){
				if(dfs_visited[i] == false){ 
					myStack.push(i);
					visit_table[i] = true;
					// possibly do something
				}
			}
		}
	}
}

for (int i = 0; i < AdjMatrix.size(); i++) {
	if (dfs_visited[i] == false) {
		nrdfs(i);
	}
}