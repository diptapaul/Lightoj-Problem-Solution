#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;

struct inf{
    long long int pro, sum;
}tree[mx * 3];

long long int query(int node, int b, int e, int i, int j, long long int carry)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node].sum + carry * (e - b + 1);
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    long long int p1 = query(left, b, mid, i, j, carry + tree[node].pro);
    long long int p2 = query(right, mid + 1, e, i, j, carry + tree[node].pro);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int j, int val)
{
    if(i > e || j < b) return;
    if(b >= i && e <= j)
    {
        tree[node].sum += (e - b + 1) * val;
        tree[node].pro += val;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].pro;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w+", stdout);

    int i, j, tc, cs = 1, n, q, k, l, v;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &q) == 2)
    {
        for(i = 0; i < mx * 3; i++) tree[i].sum = tree[i].pro = 0;
        printf("Case %d:\n", cs++);
        for(i = 0; i < q; i++)
        {
            scanf("%d", &j);
            if(j)
            {
                scanf("%d %d", &l, &k);
                printf("%lld\n", query(1, 1, n, l + 1, k + 1, 0));
            }
            else
            {
                scanf("%d %d %d", &l, &k, &v);
                update(1, 1, n, l + 1, k + 1, v);
            }
        }
    }

    return 0;
}
