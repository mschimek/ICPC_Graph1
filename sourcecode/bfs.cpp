vector<int> d(V, -1);
d[s] = 0;
queue<int> q;
q.push(s);
while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (d[v] == -1) {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}
