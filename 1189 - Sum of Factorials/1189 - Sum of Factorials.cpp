#include <bits/stdc++.h>

using namespace std;

#define read                            freopen("in.txt", "r", stdin)
#define pb                              push_back
#define F                               first
#define S                               second
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

typedef long long int                   LL;
typedef pair<int,int>                   PII;
typedef vector<int>                     VI;
typedef vector<LL>                      VL;
typedef vector<string>                  VS;
typedef vector<char>                    VC;
typedef vector<bool>                    VB;
typedef vector<PII>                     VII;
typedef map<string,int>                 MSI;
typedef map<int,int>                    MII;
typedef map<char,int>                   MCI;
typedef map<int,string>                 MIS;

template<typename T> T Abs(T x) { return x>0 ? x : -x ; }
template<typename T> T const& Max(T const& a, T const& b) { return a>b ? a : b ; }
template<typename T> T const& Min(T const& a, T const& b) { return a<b ? a : b ; }
template<typename T> inline T gcd(T a, T b) { return (b ? gcd(b,a%b) : a) ; }
template<typename T> T sqaa(T a){ return a*a ; }


/*LL modPow(LL a,LL pow,LL mod){
    if(!pow) return 1;
    else
        if(pow&1) return ( a * modPow(a,pow-1,mod) ) % mod;
        else{
            LL ret = modPow(a,pow>>1,mod)  % mod;
            return (ret * ret) % mod;
        }
}

LL modINV(LL a,LL M){
    return modPow(a,M-2,M);
}*/

LL coin[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

int main()
{
    #ifdef LU_SERIOUS
        //freopen("B.txt", "r", stdin);
        //freopen("x.txt", "w+", stdout);
    #endif // LU_SERIOUS

    int tc;
    vector <int> v(25);

    sf("%d", &tc);

    rep(i, 0, tc)
    {
        LL n, j, k;
        v.clear();
        sf("%lld", &n);

        for(j = 0; coin[j] <= n; j++);
        j--;

        while(1)
        {
            if(n - coin[j] >= 0){
                v.pb(j);
                n -= coin[j];
            }
            j--;
            if(j < 0)
                break;
        }
        pf("Case %d: ", i+1);
        if(n)
            pf("impossible\n");
        else
        {
            for(int k = sz(v) - 1; k > 0; k--)
                pf("%d!+", v[k]);
            pf("%d!\n", v[0]);
        }
    }


    return 0;
}
