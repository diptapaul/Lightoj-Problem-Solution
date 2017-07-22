#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8 + 7;
int a[105];
int siz, amount;
int dp[105][10005];

int coin_change ()
{
    for(int i = 0; i <= siz; i++) dp[i][0] = 1;
    for(int i = 1; i <= amount; i++) dp[0][i] = 0;

    for(int i = 1; i <= siz; i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(a[i-1] <= j)
            {
                dp[i][j] = (dp[i-1][j] % mod) + (dp[i][j - a[i-1]] % mod);
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] % mod);
            }
        }
    }
    return dp[siz][amount] % mod;
}

int main()
{
    int tc, cs = 1;

    scanf("%d", &tc);

    while(tc-- && ~scanf("%d %d", &siz, &amount))
    {
        for(int i = 0; i < siz; i++) scanf("%d", &a[i]);
        printf("Case %d: %d\n", cs++, coin_change());
    }

    return 0;
}
