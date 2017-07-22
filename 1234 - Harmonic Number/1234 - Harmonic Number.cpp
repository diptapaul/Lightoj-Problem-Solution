#include <bits/stdc++.h>
using namespace std;
const int mx = 1e8 + 5;

double har[mx / 100 + 5];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int i, j, k, n, tc, cs = 1;
    double sum = 0, ans;
    har[0] = 0.0;

    for(i = 1; i < mx; i++)
    {
        sum += 1.0 / i;
        if(i % 100 == 0) har[i / 100] = sum;
    }

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        ans = har[n / 100];
        for(i = (n / 100) * 100 + 1; i <= n; i++) ans += 1.0 / i;
        printf("Case %d: %.9f\n", cs++, ans);
    }

    return 0;
}
