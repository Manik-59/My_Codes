#include<bits/stdc++.h>
using namespace std;
# define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		string s,s1;
		cin>>s>>s1;
		ll dp[n+1][m+1];
		for(ll i=0;i<=n;i++)
			for(ll j=0;j<=m;j++)
				dp[i][j]=0;
		for(ll j=1;j<=m;j++)
			{
				if(s1[j-1]==s[0])
				dp[1][j]=1;
				else
					dp[1][j]+=dp[1][j-1];
			}
		for(ll i=1;i<=n;i++)
			{
				if(s[i-1]==s1[0])
				dp[i][1]=1;
				else
					dp[i][1]+=dp[i-1][1];
			}
		for(ll i=2;i<=n;i++)
			for(ll j=2;j<=m;j++)
			{
				if(s[i-1]==s1[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		cout<<dp[n][m]<<endl;
	}

}