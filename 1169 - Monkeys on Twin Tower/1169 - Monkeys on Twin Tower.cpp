#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n, cs = 1, tc, a1[2][1005], t1[2][1005], dp[2][1005], vis[1005][1005];

int rec(int i, int j)
{
    if(j > n - 1) return 0;
    if(vis[i][j] == cs) return dp[i][j];
    vis[i][j] = cs;
    int ret = a1[i][j];
    ret += min(rec(i, j + 1), rec(!i, j + 1) + t1[i][j]);
    return dp[i][j] = ret;
}

int main()
{
    #ifdef O_Amay_Bhalobaseni
       freopen("in.txt", "r", stdin);
       //freopen("in11.txt", "w+", stdout);
    #endif /// O_Amay_Bhalobaseni
    int i;
    scanf("%d", &tc);

    while(tc-- && ~scanf("%d", &n))
    {
        for(i = 0; i < n; i++) scanf("%d", &a1[0][i]);
        for(i = 0; i < n; i++) scanf("%d", &a1[1][i]);
        for(i = 0; i < n - 1; i++) scanf("%d", &t1[0][i]);
        for(i = 0; i < n - 1; i++) scanf("%d", &t1[1][i]);

        printf("Case %d: %d\n", cs, min(rec(0, 0), rec(1, 0)));
        cs++;
    }

    return 0;
}
