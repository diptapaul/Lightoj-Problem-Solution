#include <bits/stdc++.h>
using namespace std;

int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Check(int N, int pos) { return N & (1 << pos); }

int arr[17][17], n, dp[1 << 16 + 2];

int bitmask_dp(int mask, int row)
{
    if(mask == (1 << n) - 1) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        if(!Check(mask, i))
        {
            int price = arr[row][i];
            int ret = price + bitmask_dp(Set(mask, i), row + 1);
            if(ret > ans) ans = ret;
        }
    }
    return dp[mask] = ans;
}

int main()
{
    int i, j, k, l, tc;

    scanf("%d", &tc);
    for(k = 1; k <= tc; k++)
    {
        scanf("%d", &n);

        for(i = 0; i <= 1 << n; i++) dp[i] = -1;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("Case %d: %d\n", k, bitmask_dp(0, 0));
    }

    return 0;
}
