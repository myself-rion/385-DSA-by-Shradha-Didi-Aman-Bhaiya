// remove nth node from tail end in one pass
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *curr = head;
        ListNode *temp = head;

        while (n--)
        {
            curr = curr->next;
        }

        if (!curr) //if curr is null means the first node needs to be deleted
            return head->next;

        while (curr->next != NULL)
        {
            temp = temp->next;
            curr = curr->next;
        }

        ListNode *bin = temp->next;
        temp->next = temp->next->next;
        delete (bin);
        return head;
    }
};