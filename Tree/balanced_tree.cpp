class Solution
{
    // pair<int,int> {balanced or not, height}
private:
    pair<bool, int> isBalancedFast(Node *root)
    {
        if (root == NULL)
        {
            return {true, 0};
        }
        // checking for every node
        pair<bool, int> left = isBalancedFast(root->left); //checking if left subtree is balanced
        pair<bool, int> right = isBalancedFast(root->right); // checking if right subtree is balanced
        bool diff = abs(left.second - right.second) <= 1; //difference btwn left subtree height & right subtree height
        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1; //height
        if (left.first && right.first && diff) // all 3 conditions are true
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