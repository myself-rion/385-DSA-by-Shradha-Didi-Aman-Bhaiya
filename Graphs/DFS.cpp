void dfs(vector<int> &ans, vector<bool> &visited, int node, vector<int> adj[])
{
    visited[node] = true;
    ans.push_back(node);

    for (auto i : adj[node]) //accessing neighbouring elements
    {

        if (!visited[i])
        {
            dfs(ans, visited, i, adj);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V + 1, false);

    dfs(ans, visited, 0, adj); //recursive calls

    return ans;
}