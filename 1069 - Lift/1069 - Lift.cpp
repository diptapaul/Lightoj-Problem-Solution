#include<stdio.h>

int main()
{
    int i, j, k, l, m, n;

    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        scanf("%d %d", &m, &k);

        l=abs(k-m)*4+m*4;
        k=l+3+5+3+3+5;

        printf("Case %d: %d\n", i, k);
    }

    return 0;
}
