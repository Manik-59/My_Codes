#include<bits/stdc++.h>
using namespace std;
#define ll long long
int diff[2501][2501];
int min_diff(int arr[],int size,int ind,int sum=0,int sum2=0)
{
    if(ind==size)
    {
         diff[sum][sum2]=diff[sum2][sum]=abs(sum-sum2);
         return diff[sum][sum2];
    }
    if(diff[sum][sum2]!=-1)
        return diff[sum][sum2];
    else
    {
        int x=min_diff(arr,size,ind+1,sum+arr[ind],sum2);
        int y=min_diff( arr,size,ind+1,sum,sum2+arr[ind]);
        diff[sum][sum2]=diff[sum2][sum]=min(x,y);
        return diff[sum][sum2]; 

    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<2501;i++)
            for(ll j=0;j<2501;j++)
                diff[i][j]=-1;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<min_diff(arr,n,0,0,0)<<endl;
    }
}