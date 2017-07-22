#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef pagla_baba
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w+", stdout);
    #endif /// pagla_baba
    int n, m, tc, i, cs = 0;

    scanf("%d", &tc);

    while(tc-- && ~scanf("%d %d", &n, &m))
    {
        printf("Case %d: ", ++cs);
        if(n == 1 or m == 1) printf("%d\n", n * m);
        else if(n == 2 or m == 2) printf("%d\n", ((((n * m) / 2) % 2 == 1) ? ((n * m) / 2 + 1) : ((((((n * m) / 2) / 2) % 2) == 0) ? (n * m) / 2 : (n * m) / 2 + 2)));
        else printf("%d\n", (n * m) / 2 + (n * m) % 2);
    }

    return 0;
}
