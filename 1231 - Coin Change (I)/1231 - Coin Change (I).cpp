#include <bits/stdc++.h>
using namespace std;

int coin[51], tim[51], make, dp[51][1005], n, u;
int MOD = 100000007;

int call(int i, int j)
{
    if(i > n)
    {
        if(j == 0)
            return 1;
        else
            return 0;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret1 = 0;

    for(int t = 1; t <= tim[i]; t++)
    {
        if(j - coin[i]*t >= 0)
            ret1 += call(i + 1, j - coin[i]*t) % MOD;
        else
            break;
    }

    ret1 += call(i + 1, j) % MOD;

    return dp[i][j] = ret1 % MOD;
}

int main()
{
    int j, tc, i, k;

    cin >> tc;

    for(i = 1; i <= tc; i++)
    {
        u = 0;
        memset(dp, -1, sizeof(dp));
        cin >> n >> make;

        for(k = 1; k <= n; k++)
            cin >> coin[k];

        for(k = 1; k <= n; k++)
            cin >> tim[k];

        j = call(1, make) % MOD;

        cout << "Case " << i << ": " << j  << endl;
    }

    return 0;
}
