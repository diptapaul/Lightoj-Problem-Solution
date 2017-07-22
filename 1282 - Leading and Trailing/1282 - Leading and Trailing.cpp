#include <bits/stdc++.h>
using namespace std;

int bigmod(int n, int k, int mod)
{
    if(!k) return 1;
    long long int x = bigmod(n, k / 2, mod) % mod;
    x = (x * x) % mod;
    if(k & 1) x = (x * n) % mod;
    return x;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int n, k, tc, cs = 1, ans, ans1;
    double d;
    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &k) == 2)
    {
        ans = bigmod(n, k, 1000);
        d = (k * log10(n * 1.0));
        d -= (int) d;
        ans1 = pow(10, d) * 100;
        printf("Case %d: %d %.3d\n", cs++, ans1, ans);
    }

    return 0;
}
