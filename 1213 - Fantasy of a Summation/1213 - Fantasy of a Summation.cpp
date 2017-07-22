#include <bits/stdc++.h>
using namespace std;

int mod_pow(int n, int k, int mod)
{
    if(!k) return 1;
    int x = mod_pow(n, k / 2, mod) % mod;
    x = (x * x) % mod;
    if(k & 1) x = (x * n) % mod;
    return x;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int tc, cs = 1, i, j, l, k, n, mod, ans;

    scanf("%lld", &tc);

    while(tc-- && scanf("%d %d %d", &n, &k, &mod) == 3)
    {
        l = mod_pow(n, k - 1, mod);
        k %= mod;
        l *= k;
        l %= mod;
        ans = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &j);
            j %= mod;
            ans += (l * j) % mod;
            ans %= mod;
        }
        printf("Case %d: %d\n", cs++, ans);
    }


    return 0;
}
