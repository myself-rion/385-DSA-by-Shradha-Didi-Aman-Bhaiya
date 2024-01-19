class Solution
{
private:
    set<int> s;

public:
    bool check(Node *root, int level = 0)
    {
        if (root == NULL)
            return true;

        if (!root->left && !root->right) //reached leaf node
            s.insert(level);

        check(root->left, level + 1);
        check(root->right, level + 1);

        return s.size() == 1; //if all leaf nodes are on same level then set should contain only one value
    }
};