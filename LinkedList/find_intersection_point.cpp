
// Intuition: calculate length & find the bigger ll, cut off the difference & start traversing

int findAns(Node *biggerLL, Node *smallerLL, int skip)
{

    while (skip--)
    {
        biggerLL = biggerLL->next;
    }

    while (biggerLL && smallerLL)
    {
        if (biggerLL == smallerLL)
            return biggerLL->data;
        else
        {
            biggerLL = biggerLL->next;
            smallerLL = smallerLL->next;
        }
    }

    return -1;
}

int intersectPoint(Node *head1, Node *head2)
{
    int len1 = 0, len2 = 0;
    Node *temp1 = head1, *temp2 = head2;

    while (temp1) //length of ll1
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2) //length of ll2
    {
        len2++;
        temp2 = temp2->next;
    }

    temp1 = head1, temp2 = head2;

    int skip = abs(len1 - len2);

    if (len1 > len2) //ll1 is bigger
    {
        return findAns(temp1, temp2, skip);
    }
    else //ll2 is bigger
    {
        return findAns(temp2, temp1, skip);
    }
}