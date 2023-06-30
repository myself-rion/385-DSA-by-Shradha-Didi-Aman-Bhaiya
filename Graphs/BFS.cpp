vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V + 1, false);
    queue<int> q;
    q.push(0); // pushing 0 at first because all the test cases started with 0 node
    visited[0] = true;

    while (!q.empty())
    {
        int frontNum = q.front();
        q.pop();
        ans.push_back(frontNum);

        // search neighbours
        for (auto i : adj[frontNum]) //adj vector is a vector of arrays where nodes are indexes & the arrays inside the nodes are connected with it
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}