// for unique elements
void createMapping(int in[], unordered_map<int, int> &nodeToindex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToindex[in[i]] = i;
    }
}

Node *solve(int in[], int post[], int &postIndex, int inOrderStart, int inOrderEnd, int size, unordered_map<int, int> &m)
{

    if (postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = post[postIndex--]; // taking value from postOrder array

    Node *root = new Node(element); // creating root

    int pos = m[element]; // finding position of the element in inOrder array
    
    root->right = solve(in, post, postIndex, pos + 1, inOrderEnd, size, m);
    root->left = solve(in, post, postIndex, inOrderStart, pos - 1, size, m);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    int postIndex = n - 1;
    unordered_map<int, int> m;
    createMapping(in, m, n);
    Node *ans = solve(in, post, postIndex, 0, n - 1, n, m);
    return ans;
}