
class Solution
{
public:
    void dfs(int i, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[i] = true;
        for (int j = 0; j < adj[i].size(); ++j) //traversing neighbour column
        {
            if (adj[i][j] == 1 && vis[j] == false) //unvisited neighbour condition
            {
                dfs(j, vis, adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        int count_provinces = 0;
        vector<bool> vis(V, false); //visiting array

        for (int i = 0; i < V; ++i)
        {
            if (vis[i] == false)
            {
                count_provinces++; //for each new component
                dfs(i, vis, adj);
            }
        }
        return count_provinces;
    }
};
// T.C: O(V+E)
// S.C: O(V)