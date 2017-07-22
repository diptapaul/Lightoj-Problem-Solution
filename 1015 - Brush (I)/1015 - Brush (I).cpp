#include<stdio.h>

int main()
{
    int i, j, k, l, m, n, o, p;

    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        scanf("%d", &m);

        k=0;

        while(m--)
        {
            scanf("%d", &l);

            if(l<0)
                continue;
            else
                k+=l;
        }

        printf("Case %d: %d\n", i, k);
    }

    return 0;
}
