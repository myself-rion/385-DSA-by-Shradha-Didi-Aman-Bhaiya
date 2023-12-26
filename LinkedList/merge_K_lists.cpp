// without using any PQ

class Solution
{
private:
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        if (l2 == NULL)
            return l1;
        if (l1 == NULL)
            return l2;

        if (l1->val <= l2->val)
        {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;
        if (k == 1)
            return lists[0];
        int i = 0;

        while (k > 1) //until there's one list left
        {
            for (int i = 0; i < k / 2; i++)
            {
                lists[i] = merge2Lists(lists[i], lists[k - i - 1]); // merging 2 lists at a time
            }
            k = (k + 1) / 2;
        }

        return lists.front(); // final linked list
    }
};

// T.C: O(nlogK)