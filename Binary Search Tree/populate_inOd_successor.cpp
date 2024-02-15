class Solution
{
    void findInOrder(Node *root, vector<Node *> &storeNodes)
    {
        if (!root)
            return;

        findInOrder(root->left, storeNodes);

        storeNodes.push_back(root);

        findInOrder(root->right, storeNodes);
    }

public:
    void populateNext(Node *root)
    {
        vector<Node *> storeNodes;
        findInOrder(root, storeNodes);

        for (int i = 0; i < storeNodes.size() - 1; ++i)
        {
            storeNodes[i]->next = storeNodes[i + 1];
        }

        return;
    }
};