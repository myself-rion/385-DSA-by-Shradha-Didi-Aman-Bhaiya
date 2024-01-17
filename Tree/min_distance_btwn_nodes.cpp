class Solution
{
private:
    Node *LCA(Node *root, int a, int b) // find lowest common ancestor of both nodes
    {
        if (root == NULL)
            return NULL;

        if (root->data == a || root->data == b)
            return root;

        Node *left = LCA(root->left, a, b);
        Node *right = LCA(root->right, a, b);

        if (left != NULL && right != NULL)
            return root;

        else if (left == NULL && right != NULL)
            return right;

        else if (right == NULL && left != NULL)
            return left;

        else
            return NULL;
    }

    int findD(Node *root, int x, int dis) //LCA to distance of each node
    {
        if (root == NULL)
            return -1;

        if (root->data == x)
            return dis;

        int left = findD(root->left, x, dis + 1);

        if (left != -1)
        {
            return left;
        }
        else
            return findD(root->right, x, dis + 1);
    }

public:
    /* Should return minimum distance between a and b
    in a tree with given root*/

    int findDist(Node *root, int a, int b)
    {
        Node *ancestor = LCA(root, a, b);

        int d1 = findD(ancestor, a, 0);
        int d2 = findD(ancestor, b, 0);

        return d1 + d2;
    }
};