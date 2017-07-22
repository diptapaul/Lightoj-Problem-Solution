#include<stdio.h>

int main()
{
    long long int i, l, m, n, w, p;

    scanf("%lld", &p);

    for(i=1; i<=p; i++)
    {
        scanf("%lld", &w);

        if(w%2==1)
            printf("Case %lld: Impossible\n", i);

        else{
            l=1;

            while(w%2==0){
                l*=2;
                w/=2;
            }
            printf("Case %lld: %lld %lld\n",i, w, l);
        }
    }

    return 0;
}
