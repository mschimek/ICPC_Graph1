vector<node> goalPath;
int limitedDFS(node v, int depth)
{
	if(v == goal) {
		goalPath.push_back(v);
		return 1;
	}
	
	if(depth > 0) {
		vector<node> neighbors = neighborhood(v);
		for( int i = 0; i < neighbors.size(); i++) {
			if( limitedDFS(neighbors[i], depth-1) == 1) {	
				goalPath.push_back(v);
				return 1;
	}	}	}
	return 0;
}

void iterativeDFS(node origin) {
	int depth = 0;
	while( limitedDFS(origin,depth) != 1) 
		depth++;
	return;
}
