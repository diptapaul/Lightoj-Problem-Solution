#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w+", stdout);
    #endif /// O_Amay_bhalobase_Ni

    int n, tc, cs = 1, i, j, arr[105], ans, pos[105];

    scanf("%d", &tc);

    while(tc-- && scanf("%d", &n) == 1)
    {
        for(i = 1; i <= n; i++) scanf("%d", &arr[i]), pos[arr[i]] = i;
        j = 0;
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            if(arr[i] != i)
            {
                arr[pos[i]] = arr[i];
                swap(arr[pos[i]], arr[i]);
                pos[arr[i]] = pos[i];
                ans++;
            }
        }
        printf("Case %d: %d\n", cs++, ans);
    }

    return 0;
}
