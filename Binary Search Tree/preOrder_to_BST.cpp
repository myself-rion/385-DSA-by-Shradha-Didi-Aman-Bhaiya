class Solution
{
    Node *constructTree(int arr[], int low, int high)
    {
        if (low > high)
            return nullptr;

        Node *root = newNode(arr[low]);

        int i = low + 1; //separate the left part & right part using i

        while (arr[i] < arr[low] && i <= high) //finding the left part
            i++;

        root->left = constructTree(arr, low + 1, i - 1);
        root->right = constructTree(arr, i, high);

        return root;
    }

public:
    // Function that constructs BST from its preorder traversal.
    Node *post_order(int pre[], int size)
    {
        return constructTree(pre, 0, size - 1);
    }
};