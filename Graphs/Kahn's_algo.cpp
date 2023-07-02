vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // creating adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // finding indegree
    vector<int> indegree(v);
    for (auto i : adj) // traverse through keys
    {
        for (auto j : i.second) // traverse through list
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> answer;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        answer.push_back(front);
        for (auto neighbours : adj[front])
        {
            indegree[neighbours]--;

            if (indegree[neighbours] == 0)
                q.push(neighbours);
        }
    }

    return answer;
}