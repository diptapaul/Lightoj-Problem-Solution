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

/**
            তোমরা কেউ কি দিতে পার প্রেমিকার ভালবাসা
            দেবে কি কেউ জীবনের ঊষ্ণতার সত্য আশা
            ভালবাসার আগে নিজেকে নিও বাজিয়ে
            আমার মনের মত… নিও সাজিয়ে
            আমি বড় অসহায়… অন্য পথে
            একটি নাটকই দেখি মহাকালের মঞ্চে

            ও আমায় ভালবাসেনি...অসীম এ ভালবাসা ও বোঝেনি
            ও আমায় ভালবাসে নি...অতল এ ভালবাসা তলিয়ে দেখেনি

            তোমরা কেউ কি করবে আমার জন্য অপেক্ষা
            ভালবাসবে শুধুই আমায়, করবে প্রতিজ্ঞা ।।
            ভালবাসার আগে নিজেকে নিও বাজিয়ে
            আমার মনের মত… নিও সাজিয়ে
            আমি বড় অসহায়… অন্য পথে
            একটি নাটকই দেখি মহাকালের মঞ্চে

            ও আমায় ভালবাসেনি...অসীম এ ভালবাসা ও বোঝেনি
            ও আমায় ভালবাসে নি...অতল এ ভালবাসা তলিয়ে দেখেনি

            এত ভিড়েও আজও আমি একা...মনে শুধু যে শূন্যতা
            আধারে যত ছড়াই আলো...শুধু আধারে মিলায়
            ও যে কোথায় হারাল...ব্যাথা কাকে যে শুধাই
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

typedef unsigned long long int          ull;
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

const ull Mx = 5e6 + 5;

bool mark[Mx] = {0};
ull phi[Mx];

void sievephi()
{
    mark[1] = 1;
    for(ll i = 1; i < Mx; i++)
    {
        phi[i] = i;
        if(!(i & 1)) mark[i] = 1, phi[i] /= 2;
    }
    mark[2] = 0;

    for(ll i = 3; i < Mx; i+=2)
    {
        if(!mark[i])
        {
            phi[i] = phi[i] - 1;
            for(ll j = 2 * i; j < Mx; j += i)
            {
                mark[j] = 1;
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
    for(ull i = 2; i < Mx; i++) phi[i] *= phi[i], phi[i] += phi[i - 1];
}

int main()
{
    #ifdef O_Amay_bhalobase_Ni
          freopen("B.txt", "r", stdin);
          freopen("Bout.txt", "w", stdout);
    #endif // O_Amay_bhalobase_Ni

    sievephi();

    ull i, tc, j, k, l, m, n, cs = 1, ans;

    si1(tc);

    while(tc-- && scanf("%llu %llu", &n, &m) == 2)
    {
        printf("Case %llu: %llu\n", cs++, phi[m] - phi[n - 1]);
    }


    return 0;
}
