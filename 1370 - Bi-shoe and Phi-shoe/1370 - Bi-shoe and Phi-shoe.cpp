#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 100;
bitset <mx> mark;

void sieve()
{
    mark[2] = 1;
    mark[1] = 0;
    for(int i = 3; i < mx; i += 2) mark[i] = 1;
    int sq = sqrt(mx) + 10;
    for(int i = 3; i < sq; i += 2)
    {
        if(mark[i])
        {
            for(int j = i * i; j < mx; j += 2 * i) mark[j] = 0;
        }
    }
}

int main()
{
#ifdef O_Amay_bhalobase_Ni
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w+", stdout);

#endif /// O_Amay_bhalobase_Ni



    sieve();
    int n, tc, k, cs = 1, i, j, a, b;
    long long int ans;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        ans = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            for(j = a + 1; j < mx; j++)
            {
                if(mark[j])
                {
                    ans += j;
                    break;
                }
            }
        }
        printf("Case %d: %lld Xukha\n", cs++, ans);
    }

    return 0;
}
