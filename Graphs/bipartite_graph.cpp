class Solution
{
private:
    bool check(vector<int> adj[], vector<int> &color, int start)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; ++i)
        {
            if (color[i] == -1)
            {
                if (!check(adj, color, i))
                    return false;
            }
        }

        return true;
    }
};