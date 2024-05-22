class Solution
{
public:
    void dfs_topo(int i, bool vis[], vector<int> adj[], vector<int> &ans)
    {
        vis[i] = true;

        for (auto nodes : adj[i])
        {
            if (!vis[nodes])
            {
                dfs_topo(nodes, vis, adj, ans);
            }
        }

        ans.push_back(i);
    }
    vector<int> topoSort(int V, vector<int> adj[]) // using dfs
    {
        bool vis[V] = {false};
        //avoiding stack for extra auxiliary space & just reversing the ans array to get the LIFO results
        vector<int> ans;

        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                dfs_topo(i, vis, adj, ans);
            }
        }

        reverse(begin(ans), end(ans));
        return ans;
    }


    //Kahn's Algo
    vector<int> topoSort_using_bfs(int V, vector<int> adj[])
    {
        int inDegree[V] = {0}; //indegree of each vertex
        vector<int> ans;

        for (int i = 0; i < V; ++i)
        {
            for (auto &node : adj[i])
            {
                inDegree[node]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            if (inDegree[i] == 0) //push vertices who have 0 indegree, means the traversal needs to start with them
                q.push(i);
        }

        while (!q.empty())
        {
            int temp = q.front();
            ans.push_back(temp);
            q.pop();

            for (auto &node : adj[temp])
            {
                inDegree[node]--;
                if (inDegree[node] == 0) //push nodes who reached 0 indegree
                    q.push(node);
            }
        }

        return ans;
    }
};