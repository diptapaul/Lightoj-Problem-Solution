#include <bits/stdc++.h>
using namespace std;

vector <int> g[100005];
int child[100005], vis[100005];
long long toto;

void dfs(int u) {
    vis[u] = 1;
    long long int ans = 0;
    for(int i=0; i<g[u].size(); i++) {
        int v = g[u][i];
        if(!vis[v]) {
            dfs(v);
            toto += (ans * (child[v] + 1));
            ans += child[v] + 1;
            child[u] += child[v];
        }
    }
}

int main() {

    int tc, n, u, v, cs = 1;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1) {
        toto = 0;
        for(int i=0; i<=n; i++) {
            g[i].clear();
            vis[i] = child[i] = 0;
        }
        for(int i=0; i<n-1; i++) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            child[u]++;
        }
        dfs(1);
        printf("Case %d: %d %lld\n", cs++, n-1, toto);
    }

    return 0;
}
