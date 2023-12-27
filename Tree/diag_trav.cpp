// right children are priortised over left children, we first print the right children & then get back to the left ones

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> leftPointers; //to keep track of left children
    Node *temp = root;

    while (temp != NULL)
    {
        ans.push_back(temp->data);

        if (temp->left)
            leftPointers.push(temp->left);

        if (temp->right)
        {
            temp = temp->right;
        }

        else //means no right children remain
        {
            if (!leftPointers.empty())
            {
                temp = leftPointers.front();
                leftPointers.pop();
            }
            else //means no children remain
            {
                temp = NULL;
            }
        }
    }

    return ans;
}