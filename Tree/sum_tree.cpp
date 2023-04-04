class Solution
{
private:
    // pair<bool,int> {true/false,sum}
    pair<bool, int> solve(Node *root)
    {
        // base condition
        if (root == NULL)
        {
            return {true, 0};
        }
        // leaf nodes condition
        if (root->left == NULL && root->right == NULL)
        {
            return {true, root->data};
        }

        pair<bool, int> leftSubTree = solve(root->left);
        pair<bool, int> rightSubTree = solve(root->right);
        bool check = leftSubTree.second + rightSubTree.second == root->data;

        pair<bool, int> ans;
        if (leftSubTree.first && rightSubTree.first && check) // left subtree & right sum tree both are sum trees
            ans = {true, (2 * root->data)};
        else
            ans = {false, root->data};

        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        return solve(root).first;
    }
};