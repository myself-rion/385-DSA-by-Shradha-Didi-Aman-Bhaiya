void topo(stack<int> &stck, vector<bool> &visited, int node, vector<int> adj[])
{
    visited[node] = true;

    for (auto i : adj[node]) // accessing neighbouring elements
    {

        if (!visited[i])

            topo(stck, visited, i, adj);
    }

    stck.push(node);
}
// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V, false);
    stack<int> stck;

    for (int i = 0; i < V; i++)
    { // for disconnected components
        if (!visited[i])
            topo(stck, visited, i, adj); // recursive calls
    }

    while (!stck.empty())
    {
        ans.push_back(stck.top());
        stck.pop();
    }

    return ans;
}

// T.C : O(V+E)
// S.C : O(V)