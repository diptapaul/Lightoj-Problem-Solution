#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y, z;

    point(){}
    point(int a, int b, int c) {
        x = a, y = b, z = c;
    }
};

char ch[205][205];
vector < pair <int, int> > fire, fire2;
int vis[205][205], dis[205][205], r, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int bfs(int x, int y) {
    queue < point > que;
    int coun = 1;

    que.push(point(x, y, coun));
    vis[x][y] = 1;
    dis[x][y] = 1;

    while(!que.empty()) {
        point cur = que.front();
        que.pop();

        if((cur.x == 0 || cur.x == r-1 || cur.y == 0 || cur.y == c-1)) {
            return dis[cur.x][cur.y];
        }

        if(coun == cur.z){
            coun++;
            fire2.clear();
            for(int i=0; i<fire.size(); i++) {
                for(int j=0; j<4; j++) {
                    int dxx = fire[i].first + dx[j];
                    int dyy = fire[i].second + dy[j];
                    if(dxx >= 0 && dxx < r && dyy >= 0 && dyy < c && ch[dxx][dyy] != '#' && ch[dxx][dyy] != 'F') {
                        ch[dxx][dyy] = 'F';
                        fire2.push_back({dxx, dyy});
                    }
                }
            }
            fire = fire2;
        }

        for(int i=0; i<4; i++) {
            int dxx = cur.x + (dx[i]);
            int dyy = cur.y + (dy[i]);

            if(dxx >= 0 && dxx < r && dyy >= 0 && dyy < c && !vis[dxx][dyy] && ch[dxx][dyy] == '.') {
                vis[dxx][dyy] = 1;
                dis[dxx][dyy] = dis[cur.x][cur.y] + 1;
                que.push(point(dxx, dyy, cur.z+1));
            }
        }
    }
    return -1;
}


int main() {

//    freopen("in.txt", "r", stdin);

    int tc, cs = 1, x, y, ans;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &r, &c) == 2) {
        memset(vis, 0, sizeof vis);
        fire.clear();
        for(int i=0; i<r; i++) {
            getchar();
            for(int j=0; j<c; j++) {
                scanf("%c", &ch[i][j]);
                if(ch[i][j] == 'F') {
                    fire.push_back({i, j});
                }
                if(ch[i][j] == 'J') {
                    x = i, y = j;
                }
            }
        }
        ans = bfs(x, y);
        if(ans == -1) {
            printf("Case %d: IMPOSSIBLE\n", cs++);
        }
        else {
            printf("Case %d: %d\n", cs++, ans);
        }
    }

    return 0;
}
