class Solution
{
public:
    // Note: Can be done using a vector storing frequencies
    Node *segregate(Node *head)
    {

        Node *zD = new Node(-1); // dummy nodes
        Node *oD = new Node(-1);
        Node *tD = new Node(-1);

        Node *zeroTemp = zD; //pointers which will move accross the 0, 1 , 2 chains
        Node *oneTemp = oD;
        Node *twoTemp = tD;

        Node *curr = head;

        while (curr)
        {
            if (curr->data == 0)
            {
                zeroTemp->next = curr;
                zeroTemp = zeroTemp->next;
            }
            else if (curr->data == 1)
            {
                oneTemp->next = curr;
                oneTemp = oneTemp->next;
            }
            else
            {
                twoTemp->next = curr;
                twoTemp = twoTemp->next;
            }
            curr = curr->next;
        }

        zeroTemp->next = (oD->next) ? oD->next : tD->next; //condition to pass the case if the list only consists of 0 & 2
        oneTemp->next = tD->next;
        twoTemp->next = NULL;

        head = zD->next;

        delete (zD);
        delete (oD);
        delete (tD);

        return head;
    }
};