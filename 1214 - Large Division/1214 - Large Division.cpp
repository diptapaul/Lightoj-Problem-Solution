/**
  _____    _           _               _____                    _
 |  __ \  (_)         | |             |  __ \                  | |
 | |  | |  _   _ __   | |_    __ _    | |__) |   __ _   _   _  | |
 | |  | | | | | '_ \  | __|  / _` |   |  ___/   / _` | | | | | | |
 | |__| | | | | |_) | | |_  | (_| |   | |      | (_| | | |_| | | |
 |_____/  |_| | .__/   \__|  \__,_|   |_|       \__,_|  \__,_| |_|
              | |
              |_|
*/

#include <bits/stdc++.h>


using namespace std;

#define read                            freopen("in.txt", "r", stdin)
#define pb                              push_back
#define f                               first
#define s                               second
#define EPS                             1e-9
#define sf                              scanf
#define pf                              printf
#define si1(x)                          scanf("%d",&x)
#define si2(x,y)                        scanf("%d %d",&x,&y)
#define si3(x,y,z)                      scanf("%d %d %d",&x,&y,&z)
#define sd1(x)                          scanf("%lf",&x)
#define sd2(x,y)                        scanf("%lf %lf",&x,&y)
#define sd3(x,y,z)                      scanf("%lf %lf %lf",&x,&y,&z)
#define sl1(x)                          scanf("%lld",&x)
#define sl2(x,y)                        scanf("%lld %lld",&x,&y)
#define sl3(x,y,z)                      scanf("%lld %lld %lld",&x,&y,&z)
#define sz(x)                           (int)(x).size()
#define all(x)                          (x).begin(), (x).end()
#define rall(x)                         (x).rbegin(), (x).rend()
#define ms(x,a)                         memset(x,a,sizeof(x))
#define rep(i,a,b)                      for(int i=(a); i<(b); i++)
#define repc(i,x)                       for(int i=0; i<(sz(x)); i++)
#define repit(it,x)                     for(__typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define mod                             1e9 + 7;
#define nn                              "\n"

typedef long long int                   ll;
typedef pair<int,int>                   pii;
typedef vector<int>                     vi;
typedef vector<ll>                      vl;
typedef vector<string>                  vs;
typedef vector<char>                    vc;
typedef vector<bool>                    vb;
typedef vector<pii>                     vii;
typedef map<string,int>                 msi;
typedef map<int,int>                    mii;
typedef map<char,int>                   mci;
typedef map<int,string>                 mis;

template<typename T> T Abs(T x)
{
    return x>0 ? x : -x ;
}
template<typename T> T const& Max(T const& a, T const& b)
{
    return a>b ? a : b ;
}
template<typename T> T const& Min(T const& a, T const& b)
{
    return a<b ? a : b ;
}
template<typename T> inline T gcd(T a, T b)
{
    return (b ? gcd(b,a%b) : a) ;
}
template<typename T> T sqaa(T a)
{
    return a*a ;
}


///******************** SOLUTION ********************\\\


int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("in.txt", "r", stdin);
    #endif // O_Amay_bhalobase_Ni

    ll i, j, k, l, b, ans;
    string a;

    sl1(l);

    for(k = 1; k <= l; k++)
    {
        cin >> a;
        sl1(b);
        ans = 0;
        for(i = 0; i < a.size(); i++)
        {
            if(a[i] == '-') continue;
            ans = (ans * 10 + (a[i] - '0')) % b;
        }
        if(!ans) printf("Case %d: divisible\n", k);
        else printf("Case %d: not divisible\n", k);
    }

    return 0;
}
