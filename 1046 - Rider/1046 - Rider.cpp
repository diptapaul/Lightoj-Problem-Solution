#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y, z;
    point(){}
    point(int a, int b, int c) {
        x = a, y = b, z = c;
    }
};

vector < point > rider;
int vis[11][11], dis[105][11][11], n, m, che[11][11], rider_checker[11][11];
char ch[11][11];
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void bfs(int x, int y, int z, int rider_number) {
    queue <point> que;
    vis[x][y] = 1;
    che[x][y]++;
    que.push(point(x, y, z));
    while(!que.empty()) {
        point cur = que.front();
        que.pop();

        for(int i=0; i<8; i++) {
            int ddx = cur.x + dx[i];
            int ddy = cur.y + dy[i];
            if(ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && !vis[ddx][ddy]) {
                if(!cur.z) {
                    cur.z = z;
                }
                vis[ddx][ddy] = 1;
                che[ddx][ddy]++;
                if(cur.z == z) {
                    dis[rider_number][ddx][ddy] = dis[rider_number][cur.x][cur.y] + 1;
                } else {
                    dis[rider_number][ddx][ddy] = dis[rider_number][cur.x][cur.y];
                }
                que.push(point(ddx, ddy, cur.z-1));
            }
        }
    }
}

int main() {

    int tc, cs = 1, ans, tot;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &m) == 2) {
        memset(che, 0, sizeof che);
        memset(dis, 0, sizeof dis);
        rider.clear();
        for(int i=0; i<n; i++) {
            getchar();
            for(int j=0; j<m; j++) {
                scanf("%c", &ch[i][j]);
                if(ch[i][j] != '.') {
                    rider.push_back(point(i, j, ch[i][j]-'0'));
                }
            }
        }
        for(int i=0; i<rider.size(); i++) {
            memset(vis, 0, sizeof vis);
            bfs(rider[i].x, rider[i].y, rider[i].z, i);
        }

        ans = 1e9;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(che[i][j] == rider.size()) {
                    int mx = 0;
                    for(int k=0; k<rider.size(); k++) {
                        mx += dis[k][i][j];
                    }
                    ans = min(ans, mx);
                }
            }
        }
        if(ans == 1e9) ans = -1;
        printf("Case %d: %d\n", cs++, ans);
    }

    return 0;
}
