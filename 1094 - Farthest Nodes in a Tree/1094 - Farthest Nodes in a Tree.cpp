#include <bits/stdc++.h>
using namespace std;

vector < pair <int, int> > g[30005];
int vis[30005], maxi, farthest_node;

void dfs(int u, int cost) {
    vis[u] = 1;

    if(cost > maxi) {
        maxi = cost;
        farthest_node = u;
    }

    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i].first;
        int cos = g[u][i].second;
        if(!vis[v]) {
            dfs(v, cost + cos);
        }
    }
}

int main() {

    //freopen("in.txt", "r", stdin);

    int tc, cs = 1, n, u, v, w;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1) {
        maxi = -1;
        for(int i=0; i<=n; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        n--;
        while(n-- && scanf("%d %d %d", &u, &v, &w) == 3) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(0, 0);
        maxi = -1;
        memset(vis, 0, sizeof vis);
        dfs(farthest_node, 0);
        printf("Case %d: %d\n", cs++, maxi);
    }

    return 0;
}
