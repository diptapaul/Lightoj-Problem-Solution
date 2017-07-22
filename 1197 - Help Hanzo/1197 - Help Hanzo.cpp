#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 100;
bool mark[mx];
int nprime = 1, arr[9700];

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
    for(int i = 3; i < mx; i++)
    {
        if(mark[i]) arr[nprime++] = i;
    }
}

int segmented_sieve(int a, int b)
{
    if(b < 2) return 0;
    if(a < 2) a = 2;
    int prime = 0;
    memset(mark, 1, sizeof mark);
    for(int i = 0; i < nprime && arr[i] * arr[i] <= b; i++)
    {
        long long int j = a / arr[i];
        if(a % arr[i] != 0) j++;
        j *= arr[i];
        if(j == arr[i]) j += arr[i];
        for(; j <= b; j += arr[i])
        {
            mark[j - a] = 0;
        }
    }
    for(long long int i = a; i <= b; i++) if(mark[i - a]) prime++;
    if(a == 1) prime--;
    return prime;
}

int main()
{
#ifdef O_Amay_bhalobase_Ni
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w+", stdout);

#endif /// O_Amay_bhalobase_Ni



    sieve();
    int n, tc, k, cs = 1, i, j, ans, a, b;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &a, &b) == 2)
    {
        printf("Case %d: %d\n", cs++, segmented_sieve(a, b));
    }

    return 0;
}
