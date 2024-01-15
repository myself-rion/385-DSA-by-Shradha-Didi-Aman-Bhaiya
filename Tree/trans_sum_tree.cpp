class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of nodes in left and right subtrees in the original tree
    int sumTree(Node *temp)
    {
        if (temp == NULL)
            return 0;

        int leftSum = sumTree(temp->left), rightSum = sumTree(temp->right);

        int currVal = temp->data;

        temp->data = leftSum + rightSum;

        return currVal + temp->data;
    }

    void toSumTree(Node *node)
    {
        sumTree(node);
        return;
    }
};