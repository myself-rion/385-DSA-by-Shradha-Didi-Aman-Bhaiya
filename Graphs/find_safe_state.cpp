// intuition: reverse the graph edges & set the terminal node as starting node to find all the connected nodes in the leading path

class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> adj2[V];
        int inDegree[V] = {0};

        for (int i = 0; i < V; ++i)
        {
            for (auto nodes : adj[i])
            {
                adj2[nodes].push_back(i);
                inDegree[i]++;
            }
        }

        // topo sort using Kahn's Algo
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nodes : adj2[node])
            {
                if (--inDegree[nodes] == 0)
                    q.push(nodes);
            }
        }

        sort(begin(ans), end(ans));

        return ans;
    }
};