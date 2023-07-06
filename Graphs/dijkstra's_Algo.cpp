class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        vector<int> dist(V, INT_MAX); // setting all distance values to max(infinity)

        dist[S] = 0;

        set<pair<int, int>> s; //{node, distanceNode}
        s.insert({S, 0});

        while (!s.empty())
        {
            auto top = *(s.begin()); //beacuse s.begin() returns a pointer

            int node = top.first;
            int nodeDistance = top.second;

            s.erase(s.begin());

            for (auto neighbour : adj[node]) //accessing neighbour nodes
            {
                if (nodeDistance + neighbour[1] < dist[neighbour[0]]) //neighbour[0]= node, neighbour[1]= path cost/ distance
                {

                    auto record = s.find(make_pair(neighbour[0], dist[neighbour[0]]));
                    if (record != s.end())
                    {
                        s.erase(record);
                    }

                    dist[neighbour[0]] = nodeDistance + neighbour[1];

                    s.insert(make_pair(neighbour[0], dist[neighbour[0]]));
                }
            }
        }

        return dist;
    }
};