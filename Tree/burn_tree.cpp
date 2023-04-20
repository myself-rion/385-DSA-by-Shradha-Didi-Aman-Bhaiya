private:
Node *createMapping(Node *root, int target, map<Node *, Node *> &nTp) // finding the target node by level order traversal & creating parent child mapping
{
    Node *ans = NULL;
    queue<Node *> q;
    q.push(root);
    nTp[root] = NULL;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == target)
        {
            ans = temp;
        }

        if (temp->left)
        {
            q.push(temp->left);
            nTp[temp->left] = temp;
        }

        if (temp->right)
        {
            q.push(temp->right);
            nTp[temp->right] = temp;
        }
    }
    return ans;
}

int burnTree(Node *targetNode, map<Node *, Node *> &nTp)
{
    int reqTime = 0; // time to burn the entire tree
    map<Node *, bool> visited; // tracking if the nodes are visited
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = true;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false; // flag for keeping track if a Node is inserted in the queue

        for (int i = 0; i < size; i++)
        {
            // processing neighbouring nodes
            Node *temp = q.front();
            q.pop();

            //left child processing
            if (temp->left && !visited[temp->left])
            {
                flag = true;
                q.push(temp->left);
                visited[temp->left] = true;
            }
            // right child processing
            if (temp->right && !visited[temp->right])
            {
                flag = true;
                q.push(temp->right);
                visited[temp->right] = true;
            }

            //parent node processing
            if (nTp[temp] && !visited[nTp[temp]])
            {
                flag = true;
                q.push(nTp[temp]);
                visited[nTp[temp]] = true;
            }
        }

        if (flag == true)
        {
            reqTime++;
        }
    }
    return reqTime;
}

public:
int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createMapping(root, target, nodeToParent);
    return burnTree(targetNode, nodeToParent);
}