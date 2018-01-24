#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
int tree[mx * 3];
char s[mx];

void update(int node, int L, int R, int l, int r)
{
    if(r < L || l > R) return;
    if(L >= l && R <= r)
    {
        tree[node] += 1;
        return;
    }

    int mid = (L + R) / 2;
    update(node * 2, L, mid, l, r);
    update(node * 2 + 1, mid + 1, R, l, r);
}

int query(int node, int L, int R, int pos)
{
    if(pos < L || pos > R) return 0;
    if(L == R) return tree[node];

    int mid = (L + R) / 2;
    return tree[node] + query(node * 2, L, mid, pos) + query(node * 2 + 1, mid + 1, R, pos);
}

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        //freopen("input.txt", "r", stdin);
    #endif /// O_Amay_bhalobase_Ni

    int i, j, k, tc, q, l, r, n, cs = 1;
    char ch;

    scanf("%d", &tc);
    while(tc--)
    {
        getchar();
        gets(s);
        for(i = 0; i < mx * 3; i ++) tree[i] = 0;
        n = strlen(s);
        for(i = 0; i < n; i++) if(s[i] == '1') update(1, 1, n, i + 1, i + 1);
        //init(1, 1, n);
        scanf("%d", &q);
        printf("Case %d:\n", cs++);
        for(i = 0; i < q; i++)
        {
            getchar();
            scanf("%c", &ch);
            if(ch == 'I')
            {
                scanf("%d %d", &l, &r);
                update(1, 1, n, l, r);
            }
            else
            {
                scanf("%d", &l);
                printf("%d\n", (query(1, 1, n, l) & 1));
            }
        }
    }

    return 0;
}
