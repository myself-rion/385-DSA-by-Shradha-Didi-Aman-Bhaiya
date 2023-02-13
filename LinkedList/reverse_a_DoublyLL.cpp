Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *pr = NULL;
    Node *fr = NULL;
    //rotating
    while (curr != NULL)
    {
        fr = curr->next;
        pr = curr->prev;
        curr->next = pr;
        curr->prev = fr;
        pr = curr;
        curr = fr;
    }
    return pr;
}