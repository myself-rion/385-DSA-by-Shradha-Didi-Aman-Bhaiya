// intuition: turn the dissimilar characters into Directed Graphs & use toposort to find the order

class Solution
{
private:
    string topoSort(int &K, vector<int> adj[])
    {
        int inDegree[K] = {0}; // indegree of each vertex

        string ans = "";

        for (int i = 0; i < K; ++i)
        {
            for (auto &node : adj[i])
            {
                inDegree[node]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; ++i)
        {
            if (inDegree[i] == 0) // push vertices who have 0 indegree, means the traversal needs to start with them
                q.push(i);
        }

        while (!q.empty())
        {
            int temp = q.front();
            ans = ans + char(temp + 'a');
            q.pop();

            for (auto &node : adj[temp])
            {
                inDegree[node]--;
                if (inDegree[node] == 0) // push nodes who reached 0 indegree
                    q.push(node);
            }
        }

        return ans;
    }

public:
    string findOrder(string dict[], int n, int K)
    {
        vector<int> adj[K]; //for DAG

        for (int i = 0; i < n - 1; ++i)
        {
            string temp1 = dict[i];
            string temp2 = dict[i + 1];

            int j = 0, len = min(temp1.size(), temp2.size());
            for (int j = 0; j < len; ++j)
            {
                if (temp1[j] != temp2[j])
                {
                    adj[temp1[j] - 'a'].push_back(temp2[j] - 'a'); //finding dissimilar characters
                    break;
                }
            }
        }

        return topoSort(K, adj);
    }
};