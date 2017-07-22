#include <bits/stdc++.h>
using namespace std;
int main() {

    long long int n, k, ans, tc, cs=1, kk;

    scanf("%lld", &tc);

    while(tc-- && scanf("%lld %lld", &n, &k) == 2) {
        ans = 1;
        kk = k;
        if(k > n) {
            printf("Case %lld: 0\n", cs++);
        }
        else {
            for(int i=1; i<=kk; i++) {
                //cout << n-k+1 << " ";
                ans *= (n-k+1) * (n-k+1);
                //cout << ans << " ";
                ans /= i;
                //cout << ans << endl;
                k--;
            }
            printf("Case %lld: %lld\n", cs++, ans);
        }
    }

    return 0;
}
