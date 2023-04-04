class Solution
{
private:
    pair<bool, int> isBalancedFast(Node *root)
    {
        if (root == NULL)
        {
            return {true, 0};
        }

        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        bool diff = abs(left.second - right.second) <= 1;
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;
        if (left.first && right.first && diff)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }

        return ans;
    }

public:
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};