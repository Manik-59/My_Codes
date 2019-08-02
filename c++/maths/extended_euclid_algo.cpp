#include<bits/stdc++.h>
using namespace std;
# define ll long long
ll x,y,GCD; 
void extended_euclid_algo(ll a,ll b)
{
	if(b==0)
	{
		x=1;   // by solving on pen paper for smaller input we can check it always come 1 and 0
		y=0;
		GCD=a;
		return ;
	}
	else
	{
		extended_euclid_algo(b,a%b);
		ll cx=y;
		ll cy=x-(a/b)*y;
		x=cx;
		y=cy;
		return;
	}
}

int main()
{
	ll a,b;
	cin>>a>>b;
	extended_euclid_algo(a,b);	
	cout<<x<<"  "<<y;
}