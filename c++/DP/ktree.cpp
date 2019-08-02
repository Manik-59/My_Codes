#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define mod 1000000007
int d;
ll count1=0;
bool chk=false;
void fun(int arr[],int n,int k,int sum)
{
	if(sum==n)
	{
		if(chk==true)
		{
			count1=(count1%mod+1)%mod;
			
		}
	}
	else if(sum<n)
	{
		for(int i=0;i<k;i++)
		{
			if(sum+arr[i]>n)
				break;
			if(arr[i]>=d)
				chk=true;
			fun(arr,n,k,sum+arr[i]);
		}
		chk=false;
	}
}
int main()
{
	int n,k;
	cin>>n>>k>>d;
	int arr[k];
	for( int i=0;i<k;i++)
		arr[i]=i+1;
	fun(arr,n,k,0);
	cout<<count1;

}