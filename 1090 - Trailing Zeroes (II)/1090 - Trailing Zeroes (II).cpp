#include <bits/stdc++.h>
using namespace std;

long long int counzero(long long int n, long long int d)
{
    long long int res = 0;

    while(n)
    {
        res += n / d;
        n /= d;
    }
    return res;
}

long long int counzer(long long int n, long long int d)
{
    long long int res = 0;

    while(n % d == 0)
    {
        res++;
        n /= d;
    }
    return res;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    long long int tc, cs = 1, n, r, p, q, zero, cou, fiv, two;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld %lld %lld %lld", &n, &r, &p, &q) == 4)
    {
        fiv = counzero(n, 5) - (counzero(r, 5) + counzero(n - r, 5)) + q * counzer(p, 5);
        two = counzero(n, 2) - (counzero(r, 2) + counzero(n - r, 2)) + q * counzer(p, 2);
        zero = min(fiv, two);
        printf("Case %lld: %lld\n", cs++, zero);
    }

    return 0;
}
