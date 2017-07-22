#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    long long int x, y, x1, y1, cs = 1, tc;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld %lld %lld %lld", &x, &y, &x1, &y1) == 4)
    {
        printf("Case %lld: %lld\n", cs++, 1 + __gcd(abs(x1 - x), abs(y1 - y)));
    }

    return 0;
}
