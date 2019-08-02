#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define mod  1000000000
vector<ll>b,c;
vector<vector<ll>>T;
vector<vector<ll>> multiply(vector<vector<ll>>A,vector<vector<ll>>B)
{
    vector<vector<ll>>result(A.size(),vector<ll>(A.size()));
    ll x=A.size();
    for(ll i=0;i<x;i++)
    {
        
        for(ll j=0;j<x;j++)
        {
            ll fac=0;
            for(ll k=0;k<x;k++)
            {
                fac=(fac+((B[i][k]*A[k][j]))%mod)%mod;
            }
            result[i][j]=fac;
        }
    }
    return result;
}
vector<vector<ll>> power(vector<vector<ll>>A,ll n)
{
    if(n==1 or n==0)
        return A;
        else
        {
            if(n%2==0)
            {
                vector<vector<ll>>X=power(A,n/2);
                return (multiply(X,X));
            }
            else
            {
                vector<vector<ll>>X=power(A,n/2);
               return (multiply(multiply(A,X),X));
            }
        }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll k,i,n,j;
        cin>>k;
        b.assign(k,0);
        c.assign(k,0);
        for(i=0;i<k;i++)
        cin>>b[i];
        for(i=0;i<k;i++)
        cin>>c[i];
        cin>>n;
        if(n<=k)
        cout<<b[n-1]<<endl;
        else
        {
            
            T.assign(k,vector<ll>(k));
            for(i=0;i<k-1;i++)
            {
                for(j=0;j<k;j++)
                {
                    if(i==j-1)
                        T[i][j]=1;
                    else
                        T[i][j]=0;
                }
            }
            for(i=k-1;i<k;i++)
            {
                for(j=0;j<k;j++)
                {
                    T[i][j]=c[k-j-1];
                }
            }
            T=power(T,n-1);
            ll sum=0;
            for(i=0;i<k;i++)
            {
                sum=(sum+(T[0][i]*b[i])%mod)%mod;
            }
            cout<<sum<<endl;
            T.clear();
            b.clear();
            c.clear();
        }

    }
} 