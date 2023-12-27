vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}