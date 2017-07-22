#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string secret(string a)
{
    string nam = "";
    int siz = a.size();
    for(int i = 0; i < siz; i++)
    {
        if(a[i] >= 'A' && a[i] <= 'z')
        {
            if(a[i] >= 'a' && a[i] <= 'z')
                a[i] = a[i]-32;
            nam += a[i];
        }
    }
    sort(nam.begin(), nam.end());
    return nam;
}
int main()
{
    int n;
    string nam1, nam2;

    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        getline(cin, nam1);
        getline(cin, nam2);
        nam1 = secret(nam1);
        nam2 = secret(nam2);
        cout << "Case " << i << ": ";

        if(nam1 == nam2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
