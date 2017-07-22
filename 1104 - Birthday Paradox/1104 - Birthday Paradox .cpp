#include<stdio.h>

int main()
{
    int i,k=1,l,n,cas;

    scanf("%d", &cas);

    while(cas--){
    scanf("%d", &n);
    float j=1;
    for(i=1;i<=n;i++){
        j=j*(n-i)/n;
        if(j<=0.5){
          printf("Case %d: %d\n",k++,i);
          break;
        }
    }
    }

    return 0;
}
