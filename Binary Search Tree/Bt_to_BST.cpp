class Solution
{

private:
    void traverseTree(Node *root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if (!root)
            return;

        pq.push(root->data);
        traverseTree(root->left, pq);
        traverseTree(root->right, pq);
    }

    void convertBTtoBST(Node *root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if (!root)
            return;

        convertBTtoBST(root->left, pq); //going left subtree to insert the smaller elements

        root->data = pq.top();
        pq.pop();

        convertBTtoBST(root->right, pq); // going right subtree insert the greater elements
    }

public:
    
    Node *binaryTreeToBST(Node *root)
    {
        if (!root->left && !root->right)
            return root;

        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        traverseTree(root, pq); // traversing & inserting elements in min heap

        convertBTtoBST(root, pq);

        return root;
    }
};