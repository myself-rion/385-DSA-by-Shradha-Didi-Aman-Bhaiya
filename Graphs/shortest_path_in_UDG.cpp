#include <bits/stdc++.h>

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> answer;
    vector<int> parent(n + 1, -1); //taking n+1 instead of n because nodes are starting from 1 index
    vector<bool> visited(n + 1, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {

            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    int currentNode = t; // destination node

    // backtracking using parent vector
    answer.push_back(currentNode);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        answer.push_back(currentNode);
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
