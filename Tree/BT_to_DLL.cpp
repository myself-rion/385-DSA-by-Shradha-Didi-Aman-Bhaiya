class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    void solveDLL(Node *root)
    {
        if (root == NULL)
            return;

        solveDLL(root->left);
        tail->right = root;
        root->left = tail;
        tail = tail->right;

        solveDLL(root->right);
    }
    Node *bToDLL(Node *root)
    {
        solveDLL(root);
        dummy->right->left = NULL; //head pointers left arrow should be NULL;
        Node *head = dummy->right;
        delete (dummy);
        return head;
    }
};