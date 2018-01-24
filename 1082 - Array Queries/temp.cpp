#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
int tree[mx * 3], arr[mx];

int init(int node, int L, int R)
{
    if(L == R)
    {
        tree[node] = arr[L];
        return tree[node];
    }
    int mid = (L + R) / 2;
    return tree[node] = min(init(node * 2, L, mid), init(node * 2 + 1, mid + 1, R));
}

int query(int node, int L, int R, int l, int r)
{
    if(r < L || l > R) return 1<<30;
    if(L >= l && R <= r) return tree[node];
    int mid = (L + R) / 2;
    return min(query(node * 2, L, mid, l, r), query(node * 2 + 1, mid + 1, R, l, r));
}

int main()
{
    int tc, i, j, k, l, n, q, r, cs = 1;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &q) == 2)
    {
        //for(i = 0; i < mx * 3; i++) tree[i] = 0;
        for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
        init(1, 1, n);
        printf("Case %d:\n", cs++);
        for(i = 1; i <= q; i++)
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }

    return 0;
}
