class Solution
{
    vector<int> in;   // for inorder
    vector<int> leaf; // for leaf nodes

    void inOrder(Node *root)
    {
        if (!root)
            return;

        inOrder(root->left);

        in.push_back(root->data);
        if (!root->left && !root->right)
            leaf.push_back(root->data);

        inOrder(root->right);
    }

public:
    bool isDeadEnd(Node *root)
    {
        in = {0}; //inserting 0 as the first element because of in[i-1]==leaf[j]-1 condition
        leaf = {};
        inOrder(root);

        int j = 0;

        for (int i = 1; i < in.size(); ++i)
        {
            if (in[i] == leaf[j])
            {
                if (in[i - 1] == leaf[j] - 1 && in[i + 1] == leaf[j] + 1) //When a node doesn't have any children (meaning it's a leaf) and its value is only one more or one less than its parent, that's a dead end.
                    return true;
                j++;
            }
        }

        return false;
    }
};