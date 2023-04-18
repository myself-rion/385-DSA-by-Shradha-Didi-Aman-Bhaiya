// Solution for duplicate + unique cases
void createMapping(int in[], unordered_map<int, vector<int>> &nodeToindex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToindex[in[i]].push_back(i); // using vector because of duplicate elements on different index
    }
}
Node *solve(int in[], int pre[], int &preIndex, int inOrderStart, int inOrderEnd, int size, unordered_map<int, vector<int>> &m)
{

    if (preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[preIndex++]; // taking value from preOrder array
    Node *root = new Node(element); // creating root

    vector<int> pos = m[element]; // finding position of the element in inOrder array
    int i;
    for (i = 0; i < pos.size(); i++)
    {
        if (pos[i] >= inOrderStart && pos[i] <= inOrderEnd) // i increments incase of duplicate elements
        {
            break;
        }
    }

    root->left = solve(in, pre, preIndex, inOrderStart, pos[i] - 1, size, m);
    root->right = solve(in, pre, preIndex, pos[i] + 1, inOrderEnd, size, m);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int preIndex = 0;
    unordered_map<int, vector<int>> m;
    createMapping(in, m, n);
    Node *ans = solve(in, pre, preIndex, 0, n - 1, n, m);
    return ans;
}