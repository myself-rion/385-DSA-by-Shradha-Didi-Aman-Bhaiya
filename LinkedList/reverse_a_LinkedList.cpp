class Solution
{
public:
    // using LOOP
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
        head = prev;
        return head;
    }

    // Using Recursion
    void reverseLL(Node *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *reversed_Head = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversed_Head;
    }
    Node *reverse(Node *head)
    {
        return reverseLL(head);
    }
};