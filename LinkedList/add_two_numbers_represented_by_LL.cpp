class Solution
{
private:
    Node *reverseLL(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void insertAtTail(Node *&head, Node *&tail, int digit)
    {
        Node *newNode = new Node(digit);
        // if list is empty
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            // Node* newNode=new Node(digit);
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {

        Node *headF = reverseLL(first);
        Node *headS = reverseLL(second);
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        int sum = 0;
        int carry = 0;
        int digit = 0;
        while (headF != NULL || headS != NULL || carry != 0)
        {
            int val1 = 0;
            if (headF != NULL)
                val1 = headF->data;

            int val2 = 0;
            if (headS != NULL)
                val2 = headS->data;
            sum = carry + val1 + val2;
            carry = sum / 10;
            digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            // if size of two given linkedLists are different
            if (headF != NULL)
            {
                headF = headF->next;
            }
            if (headS != NULL)
            {
                headS = headS->next;
            }
        }
        Node *ans = reverseLL(ansHead);
        return ans;
    }
};