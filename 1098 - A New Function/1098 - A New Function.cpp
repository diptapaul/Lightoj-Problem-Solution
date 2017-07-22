#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    long long int tc, cs = 1, i, j, l, k, n;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld", &n) == 1)
    {
        k = 0;
        for(i = 2; i * i <= n; i++)
        {
            j = n / i;
            k += (j * (j + 1)) / 2 - ((i - 1) * i) / 2;
            k += (j - i) * i;
        }
        printf("Case %lld: %lld\n", cs++, k);
    }

    return 0;
}
