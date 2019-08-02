#include<bits/stdc++.h>
using namespace std;
# define ll long long 
ll prime_sieve[1000000];
ll prime_segment[1000000];
void sieve(ll n2)
{
	for(ll i=3;i*i<=n2;i=i+2)
		prime_sieve[i]=1;
	prime_sieve[2]=1;
	for(ll i=3;(i*(i*(i*i)))<=n2;i=i+2)
	{
		if(prime_sieve[i])
		{
			for(ll j=2*i;j*j<=n2;j=j+i)
				prime_sieve[j]=0;
		}
	}
}
void segmented_sieve(ll n1,ll n2)
{
	fill_n(prime_segment,1000000,1);
	sieve(n2);
	for(ll i=2;i*i<=n2;i++)
	{
		if(prime_sieve[i])
		{
			for(ll j=n1;j<=n2;j++)
			{
				if(j==i)
					continue;
				else if(j%i==0)
					prime_segment[j-n1]=0;
			}
		}
	}
}
int main()
{
	ll n1,n2;
	cin>>n1>>n2;
	segmented_sieve(n1,n2);
	ll i;
	if(n1==1)
		i=1;
	else
		i=0;
	for(;i<=n2-n1;i++)
	{
		if(prime_segment[i])
			cout<<n1+i<<" ";
	}
}