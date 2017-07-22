#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector <int> g[10005], topsort;
int vis[10005], fl;

void dfs(int u) {
    vis[u] = 1;
    for( int i = 0; i < g[u].size(); i++ ) {
        int v = g[u][i];
        if(!vis[v]) dfs(v);
    }
    if(fl) topsort.push_back(u);
}

int main() {
    #ifdef LU_Serious
        freopen( "in.txt", "r", stdin );
        //freopen( "out.txt", "w+", stdout );
    #endif  /// LU_Serious

    int i, ans, n, m, a, b, tc, cs = 1;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &m) == 2) {
        topsort.clear();
        for( i = 1; i <= n; i++ ) {
            vis[i] = 0;
            g[i].clear();
        }
        for( i = 0; i < m; i++ ) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
        }
        fl = 1;
        ans = 0;
        for(i = 1; i <= n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        fl = 0;
        memset(vis, 0, sizeof vis);

        for( i = topsort.size() - 1; i >= 0; i-- ) {
            if(!vis[topsort[i]]) {
                ans++;
                dfs(topsort[i]);
            }
        }

        printf("Case %d: %d\n", cs++, ans);
    }


    return 0;
}
