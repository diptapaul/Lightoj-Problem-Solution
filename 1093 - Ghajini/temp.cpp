#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 4;
int arr[mx];

int range_min_query(int n, int d)
{
    deque <int> slide;
    for(int i = 1; i <= n; i++)
    {
        while(!slide.empty() && slide.front() >= arr[i]) slide.pop_front();
        slide.push_front(i);
        while(!slide.empty() && slide.back() <= i - d) slide.pop_back();

        if(i > d)
        {
            printf("%d ", arr[slide.back()]);
        }
    }
    cout << endl;
    return 0;
}

int main()
{
    #ifdef O_Amay_bhalobase_Ni
        freopen("input.txt", "r", stdin);
    #endif // O_Amay_bhalobase_Ni

    int i, j, k, l, n, d, tc;

    scanf("%d", &tc);

    while(tc-- && scanf("%d %d", &n, &d) == 2)
    {
        for(i = 1; i <= n; i++) scanf("%d", &arr[i]);
        range_min_query(n, d);
    }


    return 0;
}
