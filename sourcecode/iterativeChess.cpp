vector< vector<int> > moveList;

int thinkDFS(int origin, int movesAhead)
{
	int bestValue = 0, bestMove;
	for(int depth = 1; depth <= movesAhead; depth++)
	{
		int found = limitedDFS(origin,depth);
		depth++;
	}
	return found;
}
	
int limitedDFS(int v, int depth)
{
	if(depth == 0)
		return evaluate(boardState);
	else
	{
		for(int i = 0; i < moveList[v].size(); i++)	
		{
			int found = limitedDFS(adjList[v][i], depth-1);
			if(found != LIMITBREAK)
				return found;
		}
	}
	return LIMITBREAK;
}
