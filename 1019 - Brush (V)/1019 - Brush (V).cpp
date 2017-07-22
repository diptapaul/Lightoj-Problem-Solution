#include <bits/stdc++.h>
#define pii pair <int, int>
typedef long long int ll;
using namespace std;

priority_queue < pii, vector <pii>, greater<pii> > pq;
vector < int > gra[105];
int cost[105][105], edg, n, dis[105];

int main() {
    #ifdef LU_Serious
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif  /// LU_Serious

    int i, j, u, v, t, m, c, cs = 1;

    scanf("%d", &t);
    while( t-- && scanf("%d %d", &n, &edg)==2 ) {
        for( i=1;i<=n;i++ ) dis[i] = 1 << 30, gra[i].clear();
        for( i=1;i<=n;i++ ) for( j=1;j<=n;j++ ) cost[i][j] = 1 << 30;
        for( i=0; i<edg; i++ ) {
            scanf("%d %d %d", &u, &v, &c);
            gra[u].push_back(v);
            gra[v].push_back(u);
            cost[u][v] = cost[v][u] = min( c, cost[u][v] );
        }
        dis[1] = 0;
        pq.push({0, 1});

        while(!pq.empty()) {
            pii p = pq.top();
            pq.pop();
            u = p.second;
            for( i=0;i<gra[u].size();i++ ) {
                v = gra[u][i];
                if( dis[u] + cost[u][v] < dis[v]) {
                    dis[v] = dis[u] + cost[u][v];
                    pq.push({dis[v], v});
                }
            }
        }
        if( dis[n]==1<<30 ) printf("Case %d: Impossible\n", cs++);
        else printf("Case %d: %d\n", cs++, dis[n]);
    }

    return 0;
}
