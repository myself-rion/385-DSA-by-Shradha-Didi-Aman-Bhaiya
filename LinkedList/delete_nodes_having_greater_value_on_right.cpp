class Solution
{
private:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *curr = head;
        Node *forward = NULL;
        Node *prev = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    Node *compute(Node *head)
    {
        // your code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        head = reverse(head);
        Node *current = head;
        Node *maxnode = current;
        Node *temp;
        while (current != NULL &&
               current->next != NULL)
        {
            /* If current is smaller than max,
            then delete current */
            if (current->next->data < maxnode->data)
            {
                temp = current->next;
                current->next = temp->next;
                temp->next = NULL;
                delete(temp);
                // current=current->next;
            }

            /* If current is greater than max,
                then update max and move current */
            else
            {
                current = current->next;
                maxnode = current;
            }
        }
        Node *ans = reverse(head);
        return ans;
    }
};