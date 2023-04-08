vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode; // <horizontal distance, node value>
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int horizontalDis = temp.second;

        if (topNode.find(horizontalDis) == topNode.end())
            topNode[horizontalDis] = frontNode->data;

        if (frontNode->left)
            q.push({frontNode->left, horizontalDis - 1});
        if (frontNode->right)
            q.push({frontNode->right, horizontalDis + 1});
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}