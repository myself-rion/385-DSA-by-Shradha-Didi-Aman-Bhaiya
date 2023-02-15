// using extra space
// Time Complexity : O(n)
// Space Complexity: O(n)
class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        map<int, bool> visited;
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (visited[curr->data] == true)
            {
                // removeNode
                prev->next = curr->next;
                curr->next = NULL;
                Node *nodeToDelete = curr;
                delete nodeToDelete;
            }
            else
            {
                visited[curr->data] = true;
                prev = curr;
            }
            curr = prev->next;
        }
        return head;
    }
};