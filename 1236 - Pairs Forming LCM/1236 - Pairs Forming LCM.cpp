#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7 + 100;
bool mark[mx];
int nprime = 1, arr[664700];

void sieve()
{
    arr[0] = 2;
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
    for(int i = 2; i < mx; i++)
    {
        if(mark[i]) arr[nprime++] = i;
    }
}

int main()
{
#ifdef O_Amay_bhalobase_Ni
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w+", stdout);

#endif /// O_Amay_bhalobase_Ni



    sieve();
    long long n, tc, k, cs = 1, i, j, ans;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld", &n) == 1)
    {
        ans = 1;
        for(i = 0; ( long long )arr[i] * ( long long ) arr[i] <= n; i++)
        {
            j = 0;
            while(n % arr[i] == 0)
            {
                n /= arr[i];
                j++;
            }
            if(j > 0) ans *= 2 * j + 1;
        }
        if(n > 1)
        {
            ans *= 3;
        }
        printf("Case %lld: %lld\n", cs++, ans / 2 + 1);
    }

    return 0;
}
