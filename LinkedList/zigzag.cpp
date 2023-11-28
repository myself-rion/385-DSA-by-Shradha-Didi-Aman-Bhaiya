// Intuition: odd positions should be less than neighbours & even should be greater
class Solution
{
public:
    Node *zigZag(Node *head)
    {
        bool flag = true; //true in ODD, false in EVEN
        Node *ptr = head;

        while (ptr->next != NULL)
        {
            if ((flag && ptr->data > ptr->next->data) || (!flag && ptr->data < ptr->next->data))
            {
                swap(ptr->data, ptr->next->data);
            }
            flag = !flag;
            ptr = ptr->next;
        }

        return head;
    }
};