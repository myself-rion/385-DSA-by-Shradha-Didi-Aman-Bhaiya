class Solution
{
private:
    unordered_map<string, int> mp; //string is the preOrder traversal for every subTree & int is the number of occurance of the same tree

    string solve(Node *root)
    {
        if (root == NULL)
            return "$"; // separator for null children

        string s = "";

        if (!root->left && !root->right)
        {
            s += to_string(root->data);
            return s;
        }

        s += to_string(root->data);
        s += '/'; // separating values like 1 & 11

        s += solve(root->left);
        s += '/'; // separating values like 1 & 11
        s += solve(root->right);

        mp[s]++;

        return s;
    }

public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root)
    {
        solve(root);

        for (auto &it : mp)
        {
            if (it.second >= 2)
                return true;
        }

        return false;
    }
};