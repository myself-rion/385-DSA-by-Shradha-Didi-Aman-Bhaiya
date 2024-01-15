class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);// level separator

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                ans.push_back(v);
                v.clear();
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                v.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }

        return ans;
    }
};