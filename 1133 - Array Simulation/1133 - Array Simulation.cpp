#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int S(int v[105],int m, int n)
{
    for(int i=0; i<m; i++)
        v[i]=v[i]+n;
}

int M(int v[105],int m, int n)
{
    for(int i=0; i<m; i++)
        v[i]=v[i]*n;
}

int D(int v[105],int m, int n)
{
    for(int i=0; i<m; i++)
        v[i]=v[i]/n;
}

int R(int v[105],int m)
{
    int a[105], j, i;

    for(i=m-1,j=0; i>=0; j++,i--)
        a[j]=v[i];
    for(j=0; j<m; j++)
        v[j]=a[j];
}

int P(int v[105],int m, int n)
{
    int j=v[m];
    v[m]=v[n];
    v[n]=j;
}

int main()
{
    int v[105];
    int m, n, i, j, k, l, o, p, cas;
    char ch;

    scanf("%d", &cas);

    for(i=1; i<=cas; i++)
    {
        scanf("%d %d", &n, &m);

        for(j=0; j<n; j++)
            scanf("%d", &v[j]);
        for(j=0; j<m; j++){
                getchar();
            scanf("%c", &ch);

            if(ch=='S'){
                scanf("%d", &k);
                S(v, n, k);
            }

            else if(ch=='M'){
                scanf("%d", &k);
                M(v, n, k);
            }

            else if(ch=='D'){
                scanf("%d", &k);
                D(v, n, k);
            }

            else if(ch=='R'){
                R(v, n);
            }

            else{
                scanf("%d %d", &o, &p);
                P(v, o, p);
            }
        }
        printf("Case %d:\n", i);
        for(j=0; j<n-1; j++)
            printf("%d ", v[j]);
            printf("%d\n", v[n-1]);
    }
    return 0;
}
