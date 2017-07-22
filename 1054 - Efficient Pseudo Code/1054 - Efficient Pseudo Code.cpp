#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mx = 50005;
const ll mod = 1e9 + 7;

ll bigmod(ll x, ll y, ll m)
{
    if(!y) return 1;
    ll b = bigmod(x, y / 2, m) % m;
    b = ((b % m) * (b % m)) % m;
    if(y & 1) b = ((b % m) * (x % m)) % m;
    return (b + m) % m;
}

ll arr[5200], nprime = 1;
bool mark[mx];
map <ll, ll> fact;

void sieve()
{
    arr[0] = 2;
    mark[2] = 1;
    mark[1] = 0;
    for(long long int i = 3; i < mx; i += 2) mark[i] = 1;
    long long int sq = sqrt(mx) + 10;
    for(int i = 3; i < sq; i += 2)
    {
        if(mark[i])
        {
            for(int j = i * i; j < mx; j += 2 * i) mark[j] = 0;
        }
    }
    for(long long int i = 2; i < mx; i++)
    {
        if(mark[i]) arr[nprime++] = i;
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS

    sieve();
    ll tc, n, m, j, k, l, cs = 1, i, ans;
    vector <ll> v;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld %lld", &n, &m) == 2)
    {
//        cout << n << " " << m << endl;
        v.clear();
        for(i = 0; arr[i] * arr[i] <= n; i++)
        {
//            cout << n << endl;
            k = 0;
            while(n % arr[i] == 0)
            {
                n /= arr[i];
                k++;
            }
            if(k) fact[arr[i]] = k * m + 1, v.push_back(arr[i]);
        }
        if(n > 1) fact[n] = m + 1, v.push_back(n);
        l = 1;
        ans = 1;
        for(i = 0; i < v.size(); i++)
        {
            l = ((bigmod(v[i], fact[v[i]], mod)) - 1) % mod;
            l = (l * bigmod(v[i] - 1, mod - 2, mod)) % mod;
            ans *= l;
            ans %= mod;
        }
        printf("Case %lld: %lld\n", cs++, (ans + mod) % mod);
    }


    return 0;
}
