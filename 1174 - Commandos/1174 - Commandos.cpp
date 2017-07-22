#include <bits/stdc++.h>
using namespace std;

vector <int> g[105];
int vis[105], dis[2][105];

void bfs(int src, int num) {
    queue <int> que;
    que.push(src);
    vis[src] = 1;
    dis[num][src] = 0;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        for(int i=0; i<g[cur].size(); i++) {
            int v = g[cur][i];
            if(!vis[v]) {
                vis[v] = 1;
                dis[num][v] = dis[num][cur] + 1;
                que.push(v);
            }
        }
    }
}

int main() {

//    freopen("in.txt", "r", stdin);

    int tc, cs=1, n, r, u, v, src, sink, ans;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n,&r) == 2) {
        for(int i=0; i<=n; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        for(int i=0; i<r; i++) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%d %d", &src, &sink);
        bfs(src, 0);
        memset(vis, 0, sizeof vis);
        bfs(sink, 1);
        ans = -1;
        for(int i=0; i<n; i++) {
            ans = max(ans, dis[0][i]+dis[1][i]);
        }
        printf("Case %d: %d\n", cs++, ans);
    }

    return 0;
}
