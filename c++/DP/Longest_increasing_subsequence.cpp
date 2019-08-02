#include<bits/stdc++.h>
using namespace std;
# define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,n1;
		cin>>n>>n1;
		string s,s1;
		cin>>s>>s1;
		ll dp[n][m];
		for(ll i=0;i<n;i++)
			for(ll j=0;j<m;j++)
				dp[i][j]=0;
		for(ll j=0;j<m;j++)
			{
				if(s1[j]==s[0])
				dp[0][j]=1;
				else
					dp[0][j]+=dp[0][j-1];
			}
		for(ll i=0;i<n;i++)
			{
				if(s[i]==s1[0])
				dp[i][0]=1;
				else
					dp[i][0]+=dp[i][0];
			}
		for(ll i=1;i<m;i++)
			for(ll j=1;j<m;j++)
			{
				if(s[i]==s1[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=dp[i-1][j];
			}
		cout<<dp[n-1][m-1]<<endl;
	}

}