class Solution
{
private:
    Node *constructTree(string str, int &start, int n)
    {
        if (start >= n)
        {
            return NULL;
        }

        int num = 0;

        while (start < n && (str[start] != '(' && str[start] != ')'))
        {
            num = num * 10 + (str[start] - '0');
            start++;
        }

        Node *root = NULL;
        if (num > 0)
            root = new Node(num);

        if (start < n && str[start] == '(')
        {
            start++;
            root->left = constructTree(str, start, n);
        }
        if (start < n && str[start] == ')')
        {
            start++;
            return root;
        }

        if (start < n && str[start] == '(')
        {
            start++;
            root->right = constructTree(str, start, n);
        }

        if (start < n && str[start] == ')')
        {
            start++;
        }
        return root;
    }

public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        int i = 0;
        return constructTree(str, i, str.length());
    }