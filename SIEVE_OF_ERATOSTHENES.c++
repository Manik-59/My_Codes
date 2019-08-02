#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    ll i,j;
    bool prime[1000000];
    fill_n(prime,1000000,true);
    for(i=2;i*i<1000000;i++)
    {
        if(prime[i]==true)
        {
            for(j=i*i;j<1000000;j+=i)
                prime[j]=false;
        }
    }
    while(t--)
    {
        ll n,i;
        cin>>n;
        for(i=2;i<=n;i++)
        {
            if(prime[i]==true)
                cout<<i<<" ";
        }
        cout<<endl;
    }
}
