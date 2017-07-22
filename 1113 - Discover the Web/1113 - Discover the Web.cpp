#include<iostream>
#include<stack>
#include<string>
#include<cstdio>


using namespace std;

int main()
{
    int i, j, k, l, m, n, o, p;

    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        stack <string> a;
        stack <string> d;
        string b, c, r;
        string str="http://www.lightoj.com/";

        printf("Case %d:\n", i);

        while(cin>>b && b!="QUIT"){

            if(b=="BACK"){
                if(a.empty()){
                    printf("Ignored\n");
                }

                else{
                    d.push(str);
                    str=a.top();
                    a.pop();
                    cout<<str<<endl;
                }

            }

            else if(b=="FORWARD"){
                if(d.empty()){
                    printf("Ignored\n");
                }
                else{
                    a.push(str);
                    str=d.top();
                    d.pop();
                    cout<<str<<endl;
                }
            }
            else{
                a.push(str);
                cin>>str;
                cout<<str<<endl;
            while(d.size())
                d.pop();
            }
        }

    }

    return 0;
}
