#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque <int> a;
    int i, j, k, tc, n, siz, l, r;
    string b;

    cin >> tc;

    for(i = 1; i <= tc; i++)
    {
        cout << "Case " << i << ":\n";
        a.clear();
        l = r = 0;
        cin >> siz >> n;
        while(n--)
        {
            cin >> b;
            if(b[4] == 'L')
            {
                cin >> k;
                if(l + r == siz)
                    cout << "The queue is full" << endl;
                else{
                    a.push_front(k);
                    cout << "Pushed in left: " << k << endl;
                    l++;
                }
            }
            else if(b[4] == 'R')
            {
                cin >> k;
                if(l + r == siz)
                    cout << "The queue is full" << endl;
                else{
                    a.push_back(k);
                    cout << "Pushed in right: " << k << endl;
                    r++;
                }
            }
            else if(b[3] == 'L')
            {
                if(a.empty())
                    cout << "The queue is empty" << endl;
                else{
                    cout << "Popped from left: " << a.front() << endl;
                    a.pop_front();
                    l--;
                }
            }
            else if(b[3] == 'R')
            {
                if(a.empty())
                    cout << "The queue is empty" << endl;
                else{
                    cout << "Popped from right: " << a.back() << endl;
                    a.pop_back();
                    r--;
                }
            }

        }
    }

    return 0;
}
