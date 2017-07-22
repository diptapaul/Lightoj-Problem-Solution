#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll tc, cs = 1, n, arr[205][205], vis[205][205], dp[205][205], len[205];

ll rec(ll i, ll j)
{
    if(i > 2 * n - 1 or j < 1 or j > len[i]) return 0;
    if(vis[i][j] == cs) return dp[i][j];
    vis[i][j] = cs;
    int kk = i >= n ? -1 : 1;
    ll ret = max(rec(i + 1, j), rec(i + 1, j + kk)) + arr[i][j];
    return dp[i][j] = ret;
}
int main()
{
    #ifdef O_Amay_Bhalobaseni
       freopen("in.txt", "r", stdin);
    #endif /// O_Amay_Bhalobaseni
    ll i , j, k;
    scanf("%lld", &tc);

    while(tc-- && ~scanf("%lld", &n))
    {
        k = 1;
        for(i = 1; i <= 2 * n - 1; i++)
        {
            len[i] = k;
            for(j = 1; j <= k; j++) scanf("%lld", &arr[i][j]);
            if(i >= n) k--;
            else k++;
        }

        printf("Case %lld: %lld\n", cs, rec(1, 1));
        cs++;
    }

    return 0;
}
