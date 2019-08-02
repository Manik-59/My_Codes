#include<bits/stdc++.h>
using namespace std;
# define ll long long
ll dp[10000][10000]={0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,i,j;
		cin>>n;
		ll length[n+1],price[n+1];
		for(i=1;i<=n;i++)
			cin>>length[i];
		for(i=1;i<=n;i++)
			cin>>price[i];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(length[i]>j)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=max(price[i]+max(dp[i-1][j-length[i]],dp[i][j-length[i]]),dp[i-1][j]);
			}
		}
		cout<<dp[n][4]<<endl;
		cout<<dp[n][n]<<endl;
	}
}