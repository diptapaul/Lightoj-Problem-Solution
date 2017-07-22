#include <bits/stdc++.h>
using namespace std;

long long int modinv(long long int a, long long int b, long long int m)
{
    if(!b) return 1;
    long long int x = modinv(a, b / 2, m);
    x = (x * x) % m;
    if(b & 1) x = (x * a) % m;
    return x;
}

int main()
{
    long long int tc, cs = 1, i, j, k, l, ni[15], b[15], n, N, pr[15], r[15], res;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld", &n) == 1)
    {
        res = 0;
        N = 1;
        for(i = 0; i < n; i++) scanf("%lld %lld", &pr[i], &r[i]), N *= pr[i];
        for(i = 0; i < n; i++) res += r[i] * (N / pr[i]) * modinv(N / pr[i], pr[i] - 2, pr[i]);
        printf("Case %lld: %lld\n", cs++, res % N);
    }

    return 0;
}
