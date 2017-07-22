#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 10;
bool mark[mx];
int nprime = 1, arr[78505];

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

map <long long, long long> mp, mp1;
map <long long, long long> :: iterator it;

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("in.txt", "r", stdin);
    #endif /// O_Amay_bhalobase_Ni

    long long int a, b, l, c, i, j, k, t, ans, cs = 1, ll;

    sieve();
    cin >> t;

    while(t-- && cin >> a >> b >> l)
    {
        ll = l;
        printf("Case %lld: ", cs++);
        ans = 1;
        mp.clear();
        mp1.clear();
        j = ( a * b ) / (__gcd(a, b));
        if( j == l ) cout << 1 << endl;
        else if( l % j != 0) cout << "impossible\n";
        else
        {
            for(i = 0; arr[i] * arr[i] <= l; i++)
            {
                while(l % arr[i] == 0)
                {
                    l /= arr[i];
                    mp[arr[i]]++;
                }
            }
            if(l > 1) mp[l]++;

            for(i = 0; arr[i] * arr[i] <= j; i++)
            {
                while(j % arr[i] == 0)
                {
                    j /= arr[i];
                    mp1[arr[i]]++;
                }
            }
            if(j > 1) mp1[j]++;

            for(it = mp.begin(); it != mp.end(); it++)
            {
                if(mp1[it->first] < mp[it->first])
                {
                    ans *= powl(it->first, mp[it->first]);
                }
            }
            j = ( a * b ) / (__gcd(a, b));
            k = (j * ans) / (__gcd(j, ans));
            cout << ans << endl;
        }

    }

    return 0;
}
