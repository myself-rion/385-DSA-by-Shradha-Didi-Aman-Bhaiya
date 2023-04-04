// LeetCode
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 2 base conditions
        if (p == NULL && q == NULL)
        {
            return true;
        }

        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            return false;
        }

        bool check = p->val == q->val;                      // check the current node value is same or not
        bool leftSubTree = isSameTree(p->left, q->left);    // left subtree same or not
        bool rightSubTree = isSameTree(p->right, q->right); // right subtree same or not
        if (check && leftSubTree && rightSubTree)
            return true;
        else
            return false;
    }
};