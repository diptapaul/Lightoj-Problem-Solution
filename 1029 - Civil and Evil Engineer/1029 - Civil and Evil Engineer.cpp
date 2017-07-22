#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};
struct edge1{
    int u, v, w;
};

bool operator < (edge a, edge b)
{
    return a.w < b.w;
}
bool operator < (edge1 c, edge1 d)
{
    return c.w > d.w;
}

vector <edge> g;
vector <edge1> g1;
int par[105], ans;

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
            par[u] = v;
        }
        if(cou == n) break;
    }
}

void kruskal1(int n)
{
    for(int i = 0; i < 105; i++) par[i] = i;
    int cou = 0;
    for(int i = 0; i < g1.size(); i++)
    {
        int u = Find(g1[i].u);
        int v = Find(g1[i].v);

        if(u != v)
        {
            cou++;
            ans += g1[i].w;
            par[u] = v;
        }
        if(cou == n) break;
    }
}

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("in.txt", "r", stdin);
    #endif /// O_Amay_bhalobase_Ni

    int n, i, j, tc, cs = 1, t, u, m, v, w;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        g.clear();
        g1.clear();
        for(i = 0; i < 105; i++) par[i] = i;
        for(i = 0; ; i++)
        {
            scanf("%d %d %d",&u, &v, &w);
            if(u + v + w == 0) break;
            edge e;
            e.u = u, e.v = v, e.w = w;
            edge1 e1;
            e1.u = u, e1.v = v, e1.w = w;
            g.push_back(e);
            g1.push_back(e1);
        }
        sort(g.begin(), g.end());
        sort(g1.begin(), g1.end());
        kruskal(n);
        kruskal1(n);
        if(ans % 2 == 0) printf("Case %d: %d\n", cs++, ans / 2);
        else printf("Case %d: %d/2\n", cs++, ans);
    }

    return 0;
}
