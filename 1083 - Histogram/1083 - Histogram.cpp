#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;

int arr[mx], tree[mx * 3], n;

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = b;
        return;
    }
    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left | 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    if(arr[tree[left]] < arr[tree[right]]) tree[node] = tree[left];
    else tree[node] = tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(e < i || b > j) return -1;
    if(b >= i && e <= j) return tree[node];
    int mid = (b + e) / 2;
    int left = node * 2;
    int right = left | 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    if(arr[p1] < arr[p2]) return p1;
    return p2;
}

long long int value_his(int i, int j)
{
    if(i > j) return 0;
    if(i == j) return arr[i];
    int minind = query(1, 1, n, i, j);
    int mor = max(value_his(i, minind - 1), value_his(minind + 1, j));
    return max(mor, arr[minind] * (j - i + 1));
}

int main()
{
    int i, j, k, l, tc, cs = 1;

    scanf("%d", &tc);
    while(tc-- && scanf("%d", &n) == 1)
    {
        for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
        init(1, 1, n);
        printf("Case %d: %lld\n", cs++, value_his(1, n));
    }

    return 0;
}
