pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> result;
    result.first = root->data + leftAns.second + rightAns.second;
    result.second = max(leftAns.first, leftAns.second) + max(rightAns.second, rightAns.first);

    return result;
}
// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root); // <including current node, excluding current node>
    return max(ans.first, ans.second);
}