// Using loop

class Solution
{
public:
    Node *insert(Node *root, int k)
    {

        Node *temp = root;

        while (true)
        {
            if (temp->data == k)
                break;

            else if (k > temp->data)
            {
                if (temp->right != nullptr)
                    temp = temp->right;
                else
                {
                    Node *node = new Node(k);
                    temp->right = node;
                    break;
                }
            }
            else
            {

                if (temp->left != nullptr)
                    temp = temp->left;
                else
                {
                    Node *node = new Node(k);
                    temp->left = node;
                    break;
                }
            }
        }
        return root;
    }
};