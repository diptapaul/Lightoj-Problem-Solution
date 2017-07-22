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
int par[105], ans, vis[105];
map <string, int> mp;
vector <int> g1[105];

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
        freopen("out.txt", "w+", stdout);
    #endif /// O_Amay_bhalobase_Ni

    int n, i, j, tc, cost, cs = 1, t, u, m, v, w, id;
    string s1, s2;
    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        id = 0;
        g.clear();
        mp.clear();
        for(i = 0; i < 105; i++) par[i] = i, g1[i].clear(), vis[i] = 0;
        for(i = 0; i < n ; i++)
        {
            cin >> s1 >> s2 >> cost;
            if(mp.find(s1) == mp.end()) mp[s1] = id++;
            if(mp.find(s2) == mp.end()) mp[s2] = id++;
            edge e;
            e.u = mp[s1], e.v = mp[s2], e.w = cost;
            g.push_back(e);
        }
        sort(g.begin(), g.end());
        kruskal(id);
        m = 0;
        dfs(0);
        for(i = 1; i < id; i++)
        {
            if(!vis[i]) m = 1;
        }
        if(m) printf("Case %d: Impossible\n", cs++);
        else printf("Case %d: %d\n", cs++, ans);
    }

    return 0;
}
