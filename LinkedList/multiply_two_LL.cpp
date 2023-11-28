#define mod 1000000007

long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long num1 = 0, num2 = 0;
    while (l1)
    {
        num1 = (num1 * 10) % mod;
        num1 += l1->data;
        l1 = l1->next;
    }

    while (l2)
    {
        num2 = (num2 * 10) % mod;
        num2 += l2->data;
        l2 = l2->next;
    }

    return ((num1 % mod) * (num2 % mod)) % mod;
}