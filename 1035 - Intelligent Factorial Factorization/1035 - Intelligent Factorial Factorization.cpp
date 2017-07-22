#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("u.txt", "w", stdout);
    int i, j, k, l, tc, m, n, b;
    int prime[] = {2, 3, 5, 7, 11};

    cin >> tc;

    for(i = 1; i <= tc; i++)
    {
        cin >> k;

        cout << "Case " << i << ": " << k << " = ";

        int fact[101] = {0};
        memset(fact, 0, sizeof(fact));

        for(j = 2; j <= k; j++)
        {
            l = sqrt(j);
            //cout << "l = " << l << endl;
            b = j;
            //cout << "b = " << b << endl;

            for(m = 0; prime[m] <= l; m++)
            {
                if(b % prime[m] == 0)
                {
                    while(b % prime[m] == 0)
                    {
                        //cout << prime[m] << endl;
                        fact[prime[m]]++;
                        b /= prime[m];
                    }
                    //cout << b << endl;
                }
            }
            if(b > 1){
                fact[b]++;
                //cout << "ty" << endl;
            }
        }

        for(j = 100; fact[j] <= 0; j--);

        for(l = 0; l < j; l++)
        {
            if(fact[l] != 0)
            {
                cout << l << " (" << fact[l] << ") * ";
            }
        }
        cout << j << " (" << fact[j] << ")" << endl;
    }

    return 0;
}
