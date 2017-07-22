#include <bits/stdc++.h>
using namespace std;

int forbidden[26][26][26], hel, vis[26][26][26];

int plu(int ch) {
    if(ch == 25) {
        return 0;
    }
    ch++;
    return ch;
}

int minu(int ch) {
    if(ch == 0) {
        return 25;
    }
    ch--;
    return ch;
}

struct point{
    int x, y, z;
    point(){};
	point(int a, int b, int c) {
	    x = a;
	    y = b;
	    z = c;
    }
};

int bfs(string sta, string en) {
    queue < point > que;
    int dis[26][26][26];
    string a, b, c, d, e, f;
    point poi;
    poi.x = sta[0]-'a';
    poi.y = sta[1]-'a';
    poi.z = sta[2]-'a';
    if(vis[poi.x][poi.y][poi.z]) {
        return -1;
    }
    que.push(poi);
    dis[poi.x][poi.y][poi.z] = 0;
    vis[poi.x][poi.y][poi.z] = 1;
    point end_point;
    end_point.x = en[0] - 'a';
    end_point.y = en[1] - 'a';
    end_point.z = en[2] - 'a';

    while(!que.empty()) {
        point po = que.front();
        que.pop();
        if(po.x == end_point.x && po.y == end_point.y && po.z == end_point.z) {
            return dis[po.x][po.y][po.z];
        }
        point qo = po;
        po.x = plu(qo.x);
        if(!vis[po.x][qo.y][qo.z]) {
            vis[po.x][qo.y][qo.z] = 1;
            que.push(point(po.x, qo.y, qo.z));
            dis[po.x][qo.y][qo.z] = dis[qo.x][qo.y][qo.z] + 1;
        }
        po.x = minu(qo.x);
        if(!vis[po.x][qo.y][qo.z]) {
            vis[po.x][qo.y][qo.z] = 1;
            que.push(point(po.x, qo.y, qo.z));
            dis[po.x][qo.y][qo.z] = dis[qo.x][qo.y][qo.z] + 1;
        }
        po.y = plu(qo.y);
        if(!vis[qo.x][po.y][qo.z]) {
            vis[qo.x][po.y][qo.z] = 1;
            que.push(point(qo.x, po.y, qo.z));
            dis[qo.x][po.y][qo.z] = dis[qo.x][qo.y][qo.z] + 1;
        }
        po.y = minu(qo.y);
        if(!vis[qo.x][po.y][qo.z]) {
            vis[qo.x][po.y][qo.z] = 1;
            que.push(point(qo.x, po.y, qo.z));
            dis[qo.x][po.y][qo.z] = dis[qo.x][qo.y][qo.z] + 1;
        }
        po.z = plu(qo.z);
        if(!vis[qo.x][qo.y][po.z]) {
            vis[qo.x][qo.y][po.z] = 1;
            que.push(point(qo.x, qo.y, po.z));
            dis[qo.x][qo.y][po.z] = dis[qo.x][qo.y][qo.z] + 1;
        }
        po.z = minu(qo.z);
        if(!vis[qo.x][qo.y][po.z]) {
            vis[qo.x][qo.y][po.z] = 1;
            que.push(point(qo.x, qo.y, po.z));
            dis[qo.x][qo.y][po.z] = dis[qo.x][qo.y][qo.z] + 1;
        }
    }
    return -1;
}

int main() {

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int n, tc, cs = 1;
    string start, en, a, b, c, d;

    cin >> tc;

    while(tc-- && cin >> start >> en >> n) {
        hel = 1;
        memset(forbidden, 0, sizeof forbidden);
        memset(vis, 0, sizeof vis);

        while(n--) {
            cin >> a >> b >> c;
            for(int i=0; i<a.size(); i++) {
                for(int j=0; j<b.size(); j++) {
                    for(int k=0; k<c.size(); k++) {
                        vis[a[i]-'a'][b[j]-'a'][c[k]-'a'] = 1;
                    }
                }
            }
        }
        printf("Case %d: %d\n",cs++, bfs(start, en));
    }

    return 0;
}
