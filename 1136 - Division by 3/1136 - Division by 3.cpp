#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b, c, d, tc, e, f;

    cin >> tc;

    for(int i = 1; i <= tc; i++)
    {
        d = 0;
        cin >> a >> b;
        c = a; d = b;

        if(a % 3 != 1)
            a%3==2 ? a += 2 : a += 1;
        if(b % 3 != 1)
            b%3==2 ? b -= 1 : b -= 2;

        f = (d - c) - (b - a) / 3;
        cout << "Case " << i << ": " << f << endl;
    }

    re
