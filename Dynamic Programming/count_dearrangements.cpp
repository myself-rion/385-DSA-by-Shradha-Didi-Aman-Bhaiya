#define mod 1000000007
public:
long int disarrange(int N)
{
    long long int prev1 = 0; // size of n=1
    long long int prev2 = 1; // size of n=2

    long long int first; //f(n-1)
    long long int second;// f(n-2)

    long long int sum;// f(n-1) + f(n-2)

    for (int i = 3; i <= N; i++)
    {
        first = prev2 % mod;
        second = prev1 % mod;
        sum = (first + second) % mod;

        long long int ans = ((i - 1) * sum) % mod;

        prev1 = prev2;
        prev2 = ans;
    }

    return prev2;
}
// relation : f(n)= (n-1)* (f(n-1)+f(n-2))