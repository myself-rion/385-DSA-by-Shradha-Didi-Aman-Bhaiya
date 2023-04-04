class Solution
{
public:
    int height(struct Node *node)
    {
        //base condition
        if (node == NULL)
        {
            return 0;
        }
        int leftHeight = height(node->left); //height of left subtree
        int rightHeight = height(node->right); // height of right subtree

        int ans = max(leftHeight, rightHeight) + 1; // max height + parent node

        return ans;
    }
};