// User function template for C++

// create a even nodes linklist with even_start as head & even_end as tail, do it for odd nodes as well
// link them & return
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *even_st = NULL, *even_end = NULL, *odd_st = NULL, *odd_end = NULL;
        Node *curr = head;

        while (curr)
        {
            if (curr->data % 2 == 0)
            {
                if (even_st == NULL)
                {
                    even_st = curr;
                    even_end = curr;
                }
                else
                {
                    even_end->next = curr;
                    even_end = curr;
                }
            }
            else
            {
                if (odd_st == NULL)
                {
                    odd_st = curr;
                    odd_end = curr;
                }
                else
                {
                    odd_end->next = curr;
                    odd_end = curr;
                }
            }

            curr = curr->next;
        }

        if (even_end != NULL)
        {
            even_end->next = odd_st;
        }

        if (odd_end != NULL)
        {
            odd_end->next = NULL;
        }

        if (even_st != NULL)
        {
            return even_st;
        }
        return odd_st; //no even nodes were there
    }
};