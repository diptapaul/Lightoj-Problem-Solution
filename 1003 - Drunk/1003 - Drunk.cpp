#include <bits/stdc++.h>
using namespace std;

vector <int> g[10005];
int vis[10005];
bool c;
void dfs(int i)
{
    vis[i] = 1;
    for(int j = 0; j < g[i].size(); j++)
    {
        int v = g[i][j];
        if(!vis[v]) dfs(v);
        else if(vis[v] == 1)
        {
            c = 1;
        }
    }
    vis[i] = 2;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int tc, n, id, cs = 1, i, j, k, l;
    string s1, s2;
    map <string, int> mp;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        memset(vis, 0, sizeof vis);
        for(i = 0; i < 10004; i++) g[i].clear();
        mp.clear();
        id = 1;
        for(i = 0; i < n; i++)
        {
            cin >> s1 >> s2;
            if(mp.find(s1) == mp.end()) mp[s1] = id++;
            if(mp.find(s2) == mp.end()) mp[s2] = id++;

            g[mp[s1]].push_back(mp[s2]);
        }
        c = 0;
        for(i = 1; i < id; i++)
        {
            if(!vis[i]) dfs(i);
        }
        if(!c) printf("Case %d: Yes\n", cs++);
        else printf("Case %d: No\n", cs++);
    }

    return 0;
}
