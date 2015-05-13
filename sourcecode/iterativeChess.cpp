vector< vector<int> > adjList;
const int LIMITBREAK = -1;

int iterativeDFS(int origin)
{
	int depth = 0, found = LIMITBREAK;
	while(found == LIMITBREAK) 
	{
		found = limitedDFS(origin,depth);
		depth++;
	}
	return found;
}
	
int limitedDFS(int v, int depth)
{
	if(depth == 0 && v == goal)
		return v;
	else if(depth > 0)
	{
		for(int i = 0; i < adjList[v].size(); i++)	
		{
			int found = limitedDFS(adjList[v][i], depth-1);
			if(found != LIMITBREAK)
				return found;
		}
	}
	return LIMITBREAK;
}
