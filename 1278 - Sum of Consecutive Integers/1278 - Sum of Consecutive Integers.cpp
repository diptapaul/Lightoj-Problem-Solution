#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7 + 100;
bool mark[mx];
int nprime = 1, arr[664600];

void sieve()
{
    arr[0] = 2;
    mark[2] = 1;
    mark[1] = 0;
    for(int i = 3; i < mx; i += 2) mark[i] = 1;
    int sq = sqrt(mx) + 10;
    for(int i = 3; i < sq; i += 2)
    {
        if(mark[i])
        {
            for(int j = i * i; j < mx; j += 2 * i) mark[j] = 0;
        }
    }
    for(int i = 2; i < mx; i++)
    {
        if(mark[i]) arr[nprime++] = i;
    }
}

map <int, int> mp;
map <int, int> :: iterator it;

int main()
{
#ifdef O_Amay_bhalobase_Ni
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w+", stdout);

#endif /// O_Amay_bhalobase_Ni

    sieve();

    long long n, tc, cs = 1, i, j, ans;
    bool b;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld", &n) == 1)
    {
        mp.clear();
        ans = 1;
        b = 0;
        if(n & 1) b = 1;


        for(i = 0; (long long) arr[i] * (long long) arr[i] <= n; i++)
        {
            //cout << n << endl;
            while(n % arr[i] == 0)
            {
                n /= arr[i];
                mp[arr[i]]++;
            }
        }
        if(n > 1) mp[n]++;

        for(it = mp.begin(); it != mp.end(); it++)
        {
            ans *= (mp[it->first] + 1);
        }
        if(b) ans -= 1;
        else
        {
            j = ans;
            ans /= mp[2] + 1;
            ans *= mp[2];
            ans = j - ans - 1;
        }
        printf("Case %lld: %lld\n", cs++, ans );
    }

    return 0;
}
