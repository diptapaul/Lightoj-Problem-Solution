#include <bits/stdc++.h>
using namespace std;

const int Mx = 1e4 + 10;
bool mark[10005];
int prime[1235], nprime = 0;
string lcm;

void sieve()
{
    mark[2] = 1;
    mark[1] = 0;

    for(long long int i = 3; i < Mx; i += 2) mark[i] = 1;
    long long int sq = sqrt(Mx) + 10;

    for(int i = 3; i < sq; i += 2)
    {
        if(mark[i])
        {
            for(int j = i * i; j < Mx; j += 2 * i) mark[j] = 0;
        }
    }
    for(int i = 2; i < Mx; i++)
    {
        if(mark[i]) prime[nprime++] = i;
    }
}

void multiply(int mul)
{
    int car = 0;
    for(int i = 0; i < lcm.size(); i++)
    {
        car += (lcm[i] - '0') * mul;
        lcm[i] = (car % 10) + '0';
        car /= 10;
    }
    while(car)
    {
        lcm += (car % 10) + '0';
        car /= 10;
    }
}

int main()
{
    sieve();

    int tc, cs = 1, i, j, k, l, n, arr[1005], f;
    int fact[1235];

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        lcm = "1";
        for(i = 0; i < n; i++) scanf("%d", &arr[i]);
        memset(fact, 0, sizeof fact);

        for(i = 0; i < n; i++)
        {
            k = sqrt(arr[i]);
            for(j = 0; prime[j] <= k; j++)
            {
                l = 1;
                while(arr[i] % prime[j] == 0)
                {
                    l *= prime[j];
                    arr[i] /= prime[j];
                }
                fact[j] = max(fact[j], l);
            }
            if(arr[i] > 1)
            {
                f = upper_bound(prime, prime + nprime, arr[i]) - prime;
                fact[f - 1] = max(fact[f-1], arr[i]);
            }
        }
        for(i = 0; i < nprime; i++)
        {
            if(fact[i] > 1) multiply(fact[i]);
        }

        printf("Case %d: ", cs++);
        reverse(lcm.begin(), lcm.end());
        cout << lcm << endl;
    }

    return 0;
}
