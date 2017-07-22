#include <bits/stdc++.h>
using namespace std;

vector <int> g[1005];
int vis[1005], dis[1005];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39};
int bfs(int s, int t) {
    queue <int> que;
    memset(vis, 0, sizeof vis);
    que.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        if(cur == t) {
            return dis[cur];
        }
        for(int i=0; i<g[cur].size(); i++) {
            int v = cur + g[cur][i];
            if(v <= t && !vis[v]) {
                vis[v] = 1;
                dis[v] = dis[cur] + 1;
                que.push(v);
            }
        }
    }
    return -1;
}

int main() {

    //freopen("in.txt", "r", stdin);

    for(int i=4; i<=1005; i++) {
        int fac = i;
        for(int j=0; prime[j]*prime[j] <= fac; j++) {
            if(fac % prime[j] == 0) {
                while(fac%prime[j]==0) {
                    fac /= prime[j];
                }
                g[i].push_back(prime[j]);
            }
        }
        if(fac > 2 && fac < i) g[i].push_back(fac);
    }

    int tc, s, t, cs = 1;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &s, &t) == 2) {
        printf("Case %d: %d\n", cs++, bfs(s, t));
    }

    return 0;
}
