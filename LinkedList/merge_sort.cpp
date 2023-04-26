public:
// Function to sort the given linked list using Merge Sort.
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeFunc(Node *L1, Node *L2)
{
    if (L1 == NULL)
    {
        return L2;
    }
    if (L2 == NULL)
    {
        return L1;
    }

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (L1 != NULL && L2 != NULL)
    {
        if (L1->data < L2->data)
        {
            temp->next = L1;
            temp = L1;
            L1 = L1->next;
        }
        else
        {
            temp->next = L2;
            temp = L2;
            L2 = L2->next;
        }
    }

    while (L1 != NULL)
    {
        temp->next = L1;
        temp = L1;
        L1 = L1->next;
    }
    while (L2 != NULL)
    {
        temp->next = L2;
        temp = L2;
        L2 = L2->next;
    }

    return dummy->next;
}

Node *ms(Node *head)
{
    // base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findMid(head);
    // divding into two halves
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive call for left & right LL
    left = ms(left);
    right = ms(right);

    // merging two sorted LL
    Node *result = mergeFunc(left, right);

    return result;
}

Node *mergeSort(Node *head)
{
    return ms(head);
}