bool isCycleBfs(vector<int> adj[], vector<bool> &visited, vector<int> &parent, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = true;

    parent[node] = -1;

    while (!q.empty())
    {
        int frontNum = q.front();
        q.pop();

        // search neighbours
        for (auto i : adj[frontNum])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = frontNum;
            }
            else if (visited[i] && i != parent[frontNum]) //condition for cycle detection
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{

    vector<bool> visited(V, false);
    vector<int> parent(V, 0);

    for (int i = 0; i < V; i++) //for components of graphs
    {
        if (!visited[i])
        {
            bool ans = isCycleBfs(adj, visited, parent, i);
            if (ans)
                return true;
        }
    }
    return false;
}