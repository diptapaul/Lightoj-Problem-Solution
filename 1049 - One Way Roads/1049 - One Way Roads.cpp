#include <bits/stdc++.h>
using namespace std;

int main() {

//    #ifdef ONLINE_JUDGE
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w+", stdout);
//    #endif /// ONLINE_JUDGE

    int tc, cs = 1, n, a, b, c, incoming[105], outgoing[105], ans, ans1;

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1) {
        ans = ans1 = 0;
        memset(incoming, 0, sizeof incoming);
        memset(outgoing, 0, sizeof outgoing);
        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &a, &b, &c);
            if(!outgoing[a] && !incoming[b]) {
                incoming[b] = 1;
                outgoing[a] = 1;
                ans += c;
            }
            else{
                outgoing[b] = 1;
                incoming[a] = 1;
                ans1 += c;
            }
        }
        printf("Case %d: %d\n", cs++, min(ans, ans1));
    }

    return 0;
}
