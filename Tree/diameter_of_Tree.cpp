class Solution
{
public:
    pair<int, int> diameterOfTree(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            pair<int, int> p = {0, 0};
            return p;
        }
        pair<int, int> left = diameterOfTree(root->left);
        pair<int, int> right = diameterOfTree(root->right);

        int op1 = left.first;  // diameter of left subtree
        int op2 = right.first; // diameter of right subtree

        int op3 = (left.second + right.second) + 1; // height of left subtree + height of right subree + root node

        pair<int, int> ans = {max(op1, max(op2, op3)), max(left.second, right.second) + 1};
        return ans;
    }
    int diameter(Node *root)
    {
        return diameterOfTree(root).first;
    }
};