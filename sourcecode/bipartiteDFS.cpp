vector< vector<int> > adjList;
vector<int> colorDFS[200];
const int UNVISITED = -1, NOT_BIP = 0, BIP = 1;
int checkDFS(int v, int color) //int main() -> checkDFS(0,0)
{
	if(colorDFS[v] == UNVISITED)
	{
		colorDFS[v] = color;
		for(int i = 0; i < adjList[v].size(); i++)	
			if(solveDFS(adjList[v][i], 1 - color) == NOT_BIP)
				return NOT_BIP;
	}
	else if(colorDFS[v] != color)
		return NOT_BIP;
	return BIP;
}
