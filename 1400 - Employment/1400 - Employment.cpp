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

const int mx = 105;

int coun, n, arr[mx * 2][mx], fre, prefer[mx];
bool freemen[mx];

bool check( int women, int partner, int freem ) {
    for( int i=1; i<=n; i++ ) {
        if( arr[women][i] == freem ) return true;
        if( arr[women][i] == partner ) return false;
    }
}

void stable_marriage() {
    memset(freemen, 0, sizeof freemen);
    memset(prefer, -1, sizeof prefer);
    coun = n;

    while(coun > 0) {
        for( int i=1; i<=n; i++ ) {
            if( !freemen[i] ) {
                fre = i;
                break;
            }
        }
        for( int i=1; i<=n; i++ ) {
            int w = arr[fre][i];
            if( prefer[w - n] == -1 ) {
                prefer[w-n] = fre;
                freemen[fre] = 1;
                coun--;
                break;
            }
            else {
                int par = prefer[w-n];
                if( check(w, par, fre) ) {
                    prefer[w-n] = fre;
                    freemen[par] = 0;
                    freemen[fre] = 1;
                    break;
                }
            }
        }
    }
}

int main() {
    #ifdef LU_Serious
        freopen( "in.txt", "r", stdin );
        //freopen( "out.txt", "w+", stdout );
    #endif  /// LU_Serious

    int tc, cs = 1, i, j;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1) {
        for( i=1; i<=n; i++ ) {
            for( j=1; j<=n; j++ ) {
                scanf("%d", &arr[i][j]);
            }
        }
        for( i=n+1; i<=2*n; i++ ) {
            for( j=1; j<=n; j++ ) {
                scanf("%d", &arr[i][j]);
            }
        }
        stable_marriage();
        printf("Case %d: ", cs++);
        printf("(%d %d)", prefer[1], 1 + n);
        for( i=2; i<=n; i++ ) {
            printf(" (%d %d)", prefer[i], i + n);
        }
        printf("\n");
    }

    return 0;
}
