
int setSetBit(int x, int y, int l, int r)
{
    int temp = y >> (l - 1);
    int ans = x;

    for (int i = l - 1; i < r; i++)
    {
        if (temp & 1)
        {
            int n = 1 << i;
            ans = ans | n;
        }
        temp >>= 1;
    }

    return ans;
}