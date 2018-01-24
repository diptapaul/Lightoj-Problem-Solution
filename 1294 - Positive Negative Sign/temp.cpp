#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef O_Amay_bhalobase_Ni
        //freopen("input.txt", "r", stdin);
    #endif // O_Amay_bhalobase_Ni

    long long int n, m, tc, cs = 1;

    cin >> tc;

    while(tc-- && cin >> n >> m)
    {
        cout << "Case " << cs++ << ": " << (n / (2 * m)) * (m * m) << endl;
    }


    return 0;
}
