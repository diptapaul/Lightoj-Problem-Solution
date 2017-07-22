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
int par[55], ans, vis[55];
vector <int> g1[55];

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
            g1[g[i].u].push_back(g[i].v);
            g1[g[i].v].push_back(g[i].u);
            par[u] = v;
        }
        if(cou == n - 1) break;
    }
}

void dfs(int i)
{
    vis[i] = 1;
    for(int j = 0; j < g1[i].size(); j++)
    {
        int v = g1[i][j];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w+", stdout);
    #endif /// O_Amay_bhalobase_Ni

    int n, i, j, tc, cost, cs = 1, t, u, m, v, w, id, sum, k;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        sum = 0;
        g.clear();
        for(i = 0; i < 55; i++) par[i] = i, g1[i].clear(), vis[i] = 0;
        for(i = 1; i <= n ; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &k);
                if(k)
                {
                    sum += k;
                    edge e;
                    e.u = i, e.v = j, e.w = k;
                    g.push_back(e);
                }
            }
        }
        sort(g.begin(), g.end());
        kruskal(n);
        m = 0;
        dfs(1);
        for(i = 1; i <= n; i++)
        {
            if(!vis[i]) m = 1;
        }
        if(m) printf("Case %d: -1\n", cs++);
        else printf("Case %d: %d\n", cs++, sum - ans);
    }

    return 0;
}
