vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> nodes; // horizontal distance,<level,vector of nodes>>
    vector<int> ans;

    if (root == NULL)
        return ans;
    //queue for level order traversal
    queue<pair<Node *, pair<int, int>>> q; //node,<horizontal distance, level>
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data); // creating nodes mapping corresponding to horizontal distance & level

        if (frontNode->left)
        {
            q.push({frontNode->left, {hd - 1, lvl + 1}});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right, {hd + 1, lvl + 1}});
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {

                ans.push_back(k);
            }
        }
    }
    return ans;
}