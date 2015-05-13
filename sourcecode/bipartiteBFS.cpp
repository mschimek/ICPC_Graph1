vector< vector<int> > adjList;
const int UNVISITED = -1, NOT_BIP = 0, BIP = 1;

int checkBFS(int nVertex) {
	vector<int> color(nVertex, UNVISITED);
	queue<int> q; q.push(0);
	while(!q.empty()) {
		int vertex = q.front(); q.pop();
		for(int i = 0; i < adjList[vertex].size(); i++) {
			int next = adjList[vertex][i];
			if(color[next] == UNVISITED) {
				color[next] = 1 - color[vertex];
				q.push(next); }
			else if(color[next] == color[vertex]) 
				return NOT_BIP;
		}
	}
	return BIP;
}
