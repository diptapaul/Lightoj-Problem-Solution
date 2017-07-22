#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

bool operator < (edge a, edge b)
{
    return a.w < b.w;
}

vector <edge> g;
vector < pair <int, int> > g1[505];
int par[505], vis[505], res[505], ans;

int Find(int u)
{
    return (par[u] == u) ? u : Find(par[u]);
}

void kruskal(int n)
{
    ans = 0;
    int cou = 0;
    for(int i = 0; i < g.size(); i++)
    {
        int u = Find(g[i].u);
        int v = Find(g[i].v);

        if(u != v)
        {
            cou++;
            ans += g[i].w;
            //cout << g[i].u << " " << g[i].v << endl;
            //cout << g[i].w << endl;
            g1[g[i].u].push_back({g[i].v, g[i].w});
            g1[g[i].v].push_back({g[i].u, g[i].w});
            //cout << g1[g[i].u][0].first << " " << g1[g[i].u][0].second << endl;
            par[u] = v;
        }
        if(cou == n - 1) break;
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < g1[u].size(); i++)
    {
        int v = g1[u][i].first;
        //res[v] = max(res[v], g1[u][i].second);
        //cout << u << " " << v << " " << res[v] << endl;
        if(!vis[v])
        {
            res[v] = max(res[u], g1[u][i].second);
            dfs(v);
        }
    }
}

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("in.txt", "r", stdin);
    #endif /// O_Amay_bhalobase_Ni

    int n, i, j, tc, cs = 1, t, u, m, v, w;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &m) == 2)
    {
        g.clear();
        for(i = 0; i < 505; i++) par[i] = i, g1[i].clear(), vis[i] = 0, res[i] = -1;
        for(i = 0; i < m; i++)
        {
            edge e;
            scanf("%d %d %d",&e.u, &e.v, &e.w);
            g.push_back(e);
        }
        sort(g.begin(), g.end());
        kruskal(n);
        scanf("%d", &t);
        res[t] = 0;
        dfs(t);
        printf("Case %d:\n", cs++);
        for(i = 0; i < n; i++)
        {
            if(res[i] == -1) printf("Impossible\n");
            else printf("%d\n", res[i]);
        }

//        for(i = 0; i < n; i++){
//            cout << "alksdjf" << endl;
//            for(j = 0; j < g1[i].size(); j++) cout << i << " " << g1[i][j].first << " " << g1[i][j].second << endl;
//        }
        //cout << ans << endl;
    }

    return 0;
}
