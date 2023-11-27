class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head->next == NULL || head->next->next == NULL)
            return;

        ListNode *curr = head, *temp = head, *prev = NULL;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        temp->next = curr->next;
        curr->next = temp;

        reorderList(temp->next);
    }
};