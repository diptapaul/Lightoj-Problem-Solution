#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
int tree[mx * 3], arr[mx], res;

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node];
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int val)
{
    if(i > e || i < b) return;
    if(b >= i && e <= i)
    {
        tree[node] += val;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);
    tree[node] = tree[left] + tree[right];
}

void update1(int node, int b, int e, int i)
{
    if(i > e || i < b) return;
    if(b >= i && e <= i)
    {
        res = tree[node];
        tree[node] = 0;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    update1(left, b, mid, i);
    update1(right, mid + 1, e, i);
    tree[node] = tree[left] + tree[right];
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int i, j, tc, cs = 1, n, q, k, l;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &q) == 2)
    {
        for(i = 0; i < mx * 3; i++) tree[i] = 0;
        for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
        init(1, 1, n);
        printf("Case %d:\n", cs++);
        for(i = 0; i < q; i++)
        {
            scanf("%d", &j);
            if(j == 3)
            {
                scanf("%d %d", &l, &k);
                printf("%d\n", query(1, 1, n, l + 1, k + 1));
            }
            else if(j == 1)
            {
                scanf("%d", &l);
                update1(1, 1, n, l + 1);
                printf("%d\n", res);
            }
            else
            {
                scanf("%d %d", &l, &k);
                update(1, 1, n, l + 1, k);
            }
        }
    }

    return 0;
}
