string solve(Node *root, unordered_map<string, int> &m, vector<Node *> &v)
{
    if (!root)
        return "";

    string left = solve(root->left, m, v);
    string right = solve(root->right, m, v);

    string ans = to_string(root->data) + "$" + left + "$" + right;

    if (m[ans] == 1)
        v.push_back(root);

    m[ans]++;

    return ans;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> v;
    unordered_map<string, int> m;
    solve(root, m, v);

    return v;
}