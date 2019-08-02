#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
         int n;
         cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int dp[k+1][n];
        for(int i=0;i<k+1;i++)
        dp[i][0]=0;
         for(int i=0;i<n;i++)
         dp[0][i]=0;
         for(int i=1;i<=k;i++)
         {
            for(int j=1;j<n;j++)
             {
                int best=0;
                 for(int k=0;k<j;k++)
                {
                    best=max(best,(arr[j]-arr[k]+dp[i-1][k]));
                }
                dp[i][j]=max(best,dp[i][j-1]);
            }
        }
        cout<<dp[k][n-1]<<endl;
    }
}