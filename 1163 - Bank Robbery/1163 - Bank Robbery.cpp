#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    long long int ab, a, cs = 1, tc;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld", &ab) == 1)
    {
        a = ab + ab / 9;
        if(ab % 9 == 0) printf("Case %lld: %lld %lld\n",cs++, a - 1, a);
        else printf("Case %lld: %lld\n",cs++, a);
    }

    return 0;
}
