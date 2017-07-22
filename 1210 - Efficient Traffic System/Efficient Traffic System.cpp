#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

#define F           first
#define S           second
#define pb          push_back
#define P           push


const int mx = 2e4 + 10;
vi g[mx], gt[mx], topsort;
int vis[mx], ans, scc[mx], in[mx], out[mx];

void dfs(int u) {
    vis[u] = 1;
    for( int i=0; i<g[u].size(); i++ ) {
        if( !vis[g[u][i]] ) {
            dfs(g[u][i]);
        }
    }
    topsort.pb(u);
}

void dfs2(int u) {
    vis[u] = 1;
    scc[u] = ans;
    for( int i=0; i<gt[u].size(); i++ ) {
        if( !vis[gt[u][i]] ) {
            dfs2(gt[u][i]);
        }
    }
}

void dfs3(int u) {
    vis[u] = 1;
    for( int i=0; i<g[u].size(); i++ ) {
        int v = g[u][i];
        if(scc[u] != scc[v]) {
            in[scc[v]] = 1;
            out[scc[u]] = 1;
        }
        if( !vis[v] ) {
            dfs3(v);
        }
    }
}

int main() {
    #ifdef LU_Serious
        freopen( "in.txt", "r", stdin );
        //freopen( "out.txt", "w+", stdout );
    #endif  /// LU_Serious

    int n, m, i, j, k, l, tc, cs = 1, u, v;

    scanf("%d", &tc);
    while(tc-- && scanf("%d %d", &n, &m) == 2) {
        topsort.clear();
        for( i=0; i<n+2; i++ ) g[i].clear(), gt[i].clear(), vis[i] = 0, in[i] = 0, out[i] = 0;

        for( i=0; i<m; i++ ) {
            scanf("%d %d", &u, &v);
            g[u].pb(v);
            gt[v].pb(u);
        }
        for( i=1; i<=n; i++ ) {
            if( !vis[i] ) {
                dfs(i);
            }
        }
        ans = 0;
        memset( vis, 0, sizeof vis );
        for( i=topsort.size()-1; i>=0; i-- ) {
            if( !vis[topsort[i]] ) {
                ans++;
                dfs2(topsort[i]);
            }
        }
        memset( vis, 0, sizeof vis );
        for( i=1; i<=n; i++ ) {
            if( !vis[i] ) {
                dfs3(i);
            }
        }
        j = k = 0;
        for( i=1; i<=ans && ans > 1; i++ ) {
            if( !in[i] ) j++;
            if( !out[i] ) k++;
        }
        printf("Case %d: %d\n", cs++, max(j, k));
    }

    return 0;
}
