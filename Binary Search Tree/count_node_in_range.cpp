// Function to count number of nodes in BST that lie in the given range.
class Solution
{
    void findInOrder(Node *root, int l, int h, int &count)
    {
        if (!root)
            return;

        findInOrder(root->left, l, h, count);

        if (root->data >= l && root->data <= h)
            count++;

        findInOrder(root->right, l, h, count);
    }

public:
    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        findInOrder(root, l, h, count);
        return count;
    }
};