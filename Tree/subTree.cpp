class Solution
{
private:
    bool isSame(TreeNode *r, TreeNode *sR)
    {
        if (r == NULL || sR == NULL)
            return r == sR; // will return true when both are NULL, false when one is and other is not.

        if (r->val != sR->val) //No need to check further if values do not match in the current Node
            return false;

        //final step will be executed only if present nodes match, then we will look the left & right part of the tree
        return isSame(r->left, sR->left) && isSame(r->right, sR->right); //if left & right part are equal then it's a sub tree
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL)
            return false;

        if (isSame(root, subRoot)) //checking if root & subRoot are equal
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); // traversing because we might find subtree in EITHER left OR right side
    }
};