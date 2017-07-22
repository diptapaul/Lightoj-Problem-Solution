#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

#define F           first
#define S           second
#define pb          push_back
#define P           push

const int mx = 5e4 + 5;
vi g[mx], gt[mx], topsort;
int vis[mx];
set <int> st;

void dfs( int u ) {
    vis[u] = 1;
    for( int i=0; i<g[u].size(); i++ ) {
        int v = g[u][i];
        if( !vis[v] ) {
            dfs(v);
        }
    }
    topsort.pb(u);
}

void dfs2( int u ) {
    vis[u] = 1;
    st.insert(u);
    for( int i=0; i<gt[u].size(); i++ ) {
        int v = gt[u][i];
        if( !vis[v] ) {
            dfs2(v);
        }
    }
}

int main() {
    #ifdef LU_Serious
        freopen( "in.txt", "r", stdin );
        //freopen( "out.txt", "w+", stdout );
    #endif  /// LU_Serious

    int n, tc, cs = 1, u, v, ma, j, ss;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1) {
        topsort.clear();
        for( int i=0; i<n+2; i++ ) g[i].clear(), gt[i].clear(), vis[i] = 0;
        for( int i=0; i<n; i++ ) {
            scanf("%d %d", &u, &v);
            g[u].pb(v);
            gt[v].pb(u);
        }

        for( int i=1; i<=n; i++ ) {
            if( !vis[i] ) {
                dfs(i);
            }
        }
//        for(auto it: topsort) cout << it << " ";
//        cout << endl << endl;
        memset(vis, 0, sizeof vis);
        ma = -1;
        j = 0;
        for( int i=topsort.size()-1 ; i>=0; i-- ) {
//        cout << topsort[i] << endl;
            if( !vis[topsort[i]] ) {
//                cout << topsort[i] << endl;
                st.clear();
                dfs2(topsort[i]);
                ss = st.size();
//                cout << ss << endl;
                if( ss > ma ) {
                    ma = ss;
                    j = topsort[i];
                }
                else if( ss == ma && topsort[i] < j ) {
                    j = topsort[i];
                }
            }
        }
        memset(vis, 0, sizeof vis);
        for( int i=0 ; i<topsort.size(); i++ ) {
            if( !vis[topsort[i]] ) {
                st.clear();
                dfs2(topsort[i]);
                ss = st.size();
                if( ss > ma ) {
                    ma = ss;
                    j = topsort[i];
                }

                else if( ss == ma && topsort[i] < j ) {
                    j = topsort[i];
                }
            }
        }
        printf("Case %d: %d\n", cs++, j);
    }

    return 0;
}
