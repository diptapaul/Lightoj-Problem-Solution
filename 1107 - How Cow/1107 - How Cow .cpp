#include<stdio.h>

int main()
{
    int i, j, k, l, m, n, o, p;
    int x1, x2, y1, y2, x, y;

    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        scanf("%d", &m);

        for(j=1; j<=m; j++){
            scanf("%d %d", &x, &y);
            if(j==1)
                printf("Case %d:\n", i);

            if(x>x1 && x<x2 && y>y1 && y<y2)
                printf("Yes\n");

            else
                printf("No\n");
        }
    }

    return 0;
}
