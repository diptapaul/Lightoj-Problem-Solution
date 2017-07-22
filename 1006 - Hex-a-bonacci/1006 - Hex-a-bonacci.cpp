#include <bits/stdc++.h>
using namespace std;

long long int a, b, c, d, e, f;

int main() {
    long long int n, caseno = 0, cases;
    long long int dp[10005];

    scanf("%lld", &cases);
    while( cases-- )
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
        dp[3] = d;
        dp[4] = e;
        dp[5] = f;

        for(int i = 6; i <= n; i++)
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % 10000007;
        printf("Case %lld: %lld\n", ++caseno, dp[n] % 10000007);
    }
    return 0;
}
