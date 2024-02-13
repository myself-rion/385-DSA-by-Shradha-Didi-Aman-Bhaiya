// iterative solution, T.C: O(h)
// three cases to handle: node with no children, node with only one child, node with both children

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        TreeNode *find = root, *parent = nullptr; // parent= predecessor of the node to delete
        while (find != nullptr && find->val != key)
        {
            parent = find;
            if (find->val < key)
                find = find->right;
            else
                find = find->left;
        }

        if (!find)
            return root; // key doesn't exist in BST

        if (!find->right || !find->left)
        { // node with only one child
            TreeNode *child = (find->left != nullptr) ? find->left : find->right; //successor of node to delete

            if (!parent)
                root = child;              // root with no children
            else if (parent->left == find) //
                parent->left = child;
            else
                parent->right = child;
            delete find;
        }
        else
        { // node with 2 children
            TreeNode *parent = find;
            TreeNode *child = find->right;
            while (child->left != nullptr)
                parent = child, child = child->left;
            find->val = child->val;
            if (parent->left == child)
                parent->left = child->right;
            else
                parent->right = child->right; //(edge case) if it doesn't go into the while
                                              // loop for child->left being null
            delete child;
        }
        return root;
    }
};