class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        // storing ans
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<Node *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {

            int size = q.size();
            // temp array to store a level's data
            vector<int> temp(size);

            // Level Process
            for (int i = 0; i < size; i++)
            {

                Node *frontNode = q.front();
                q.pop();

                // normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                temp[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // opposite direction
            leftToRight = !leftToRight;

            for (auto i : temp)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};