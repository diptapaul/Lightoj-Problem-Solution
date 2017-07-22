#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t, count=0, n;
    scanf("%d",&t);

    for(int j=1; j<=t; j++){
            scanf("%d", &n);
            count=0;
    for(int i = 0; n; ++i )
    {
        count += n & 1;
        n >>= 1;
    }

    if(count%2==0)
    printf("Case %d: even\n",j);

    else
        printf("Case %d: odd\n",j);
    }
    return 0;
}
