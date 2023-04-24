void inOrder(struct Node *root, vector<int> &in)
{
    if (root == NULL)
        return;
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

int isPairPresent(struct Node *root, int target)
{
    vector<int> inOrderVal;
    inOrder(root, inOrderVal); //inOrder of a BST is always in ascending order

    int i = 0, j = inOrderVal.size() - 1, sum = 0;

    while (i < j)
    {
        sum = inOrderVal[i] + inOrderVal[j];

        if (sum == target) //sum found
            return 1;
        else if (sum > target) //sum is greater means we need smaller values from right
            j--;
        else ////sum is lower means we need greater values from left
            i++;
    }
    return 0;
}