#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef O_Amay_bhalobase_Ni
    //freopen("in.txt", "r", stdin);
#endif /// O_Amay_bhalobase_Ni

    long long cs = 1, tc, n, i, j, ans;

    cin >> tc;

    while(tc-- && cin >> n)
    {
        j = sqrt(n);
        ans = 0;

        for(i = 1; i <= j; i++) ans += n / i;
        for(i = 1; i <= j; i++) ans += (n / i - n / (i + 1)) * i;

        if(n / j == j) ans -= j;

        printf("Case %lld: %lld\n", cs++, ans);
    }

    return 0;
}
