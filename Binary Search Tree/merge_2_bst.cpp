class Solution
{
private:
    void inOrder(Node *root, vector<int> &arr)
    {
        if (!root)
            return;

        inOrder(root->left, arr);
        arr.push_back(root->data);
        inOrder(root->right, arr);
    }

public:
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> b1, b2, ans;
        inOrder(root1, b1);
        inOrder(root2, b2);

        //merge 2 arrays
        int i = 0, j = 0, n = b1.size(), m = b2.size();

        while (i < n && j < m)
        {
            if (b1[i] <= b2[j])
                ans.push_back(b1[i]), i++;
            else
                ans.push_back(b2[j]), j++;
        }

        while (i < n)
        {
            ans.push_back(b1[i]), i++;
        }

        while (j < m)
        {
            ans.push_back(b2[j]), j++;
        }

        return ans;
    }
};