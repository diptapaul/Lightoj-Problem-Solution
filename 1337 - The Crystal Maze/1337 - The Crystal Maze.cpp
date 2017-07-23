#include <bits/stdc++.h>
using namespace std;

int m, n, vis[505][505], res[505][505], coun = 0;
vector <int> vec;
char ch[505][505];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int x, int y) {
    int mx = 0;
    if(ch[x][y] == 'C') {
        mx++;
    }
    queue < pair <int, int> > que;
    que.push({x, y});
    vis[x][y] = 1;
    res[x][y] = coun;
    while(!que.empty()) {
        pair <int, int> cur = que.front();
        que.pop();

        for(int i=0; i<4; i++) {
            int ddx = cur.first + dx[i];
            int ddy = cur.second + dy[i];
            if(ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && !vis[ddx][ddy] && ch[ddx][ddy] != '#') {
                res[ddx][ddy] = coun;
                if(ch[ddx][ddy] == 'C') {
                    mx++;
                }
                vis[ddx][ddy] = 1;
                que.push({ddx, ddy});
            }
        }
    }
    return mx;
}

int main() {
    map <int, int> mp;
    int cs = 1, tc, q, u, v, ans;

    scanf("%d", &tc);
    while(tc-- && scanf("%d %d %d", &n, &m, &q) == 3) {
        vec.clear();
        coun = -1;
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++) {
            getchar();
            scanf("%s", &ch[i]);
        }
        printf("Case %d:\n", cs++);
        for(int i=0; i<q; i++) {
            scanf("%d %d", &u, &v);
            u--, v--;

            if(!vis[u][v]) {
                coun++;
                vec.push_back(bfs(u, v));
            }
            ans = vec[res[u][v]];
            mp.clear();
            mp[res[u][v]] = 1;
            for(int j=0; j<4; j++) {
                int ddx = u + dx[j];
                int ddy = v + dy[j];
                if(ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && ch[ddx][ddy] != '#' && res[ddx][ddy] != coun && mp.find(res[ddx][ddy]) == mp.end()) {
                    mp[res[ddx][ddy]] = 1;
                    ans += vec[res[ddx][ddy]];
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
