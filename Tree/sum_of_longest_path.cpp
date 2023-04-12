void solve(Node *root, int len, int &maxLen, int sum, int &maxSum)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }
    sum += root->data;
    solve(root->left, len + 1, maxLen, sum, maxSum);
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root, len, maxLen, sum, maxSum);
    return maxSum;
}