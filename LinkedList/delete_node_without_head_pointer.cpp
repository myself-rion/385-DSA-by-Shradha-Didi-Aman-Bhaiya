class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        //   point to the next node
        Node *temp = del->next;
        del->data = temp->data; // copy data of next node
        del->next = temp->next;
        temp->next = NULL;
        delete (temp);
    }
};