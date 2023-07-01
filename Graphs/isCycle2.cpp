bool detectCycle(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[]) //recursive dfs function
{

    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool isCycle = detectCycle(neighbour, visited, dfsVisited, adj);

            if (isCycle)
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> dfsVisited(V, false); // to detect cycle in directed graphs

    for (int i = 0; i < V; i++)
    {
        bool isCycle = detectCycle(i, visited, dfsVisited, adj);

        if (isCycle)
            return true;
    }

    return false;
}