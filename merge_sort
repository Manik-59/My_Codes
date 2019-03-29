#include<bits/stdc++.h>
using namespace std;
#define ll long long
void merge(ll arr[],ll l,ll mid,ll r)
{
    ll nl=mid-l+1,nr=r-mid,i,k=l,j;
    ll left[nl],right[nr];
    
    for(i=0;i<nl;i++)
        left[i]=arr[l+i];
    
    for(i=0;i<nr;i++)
        right[i]=arr[mid+1+i];
        
    i=0,j=0,k=l;
    while(i<nl&&j<nr)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<nl)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        arr[k]=right[j];
        k++;
        j++;
    }
}
void mergesort(ll arr[],ll l,ll r)
{
    if(l<r)
    {
        ll mid =l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll arr[n];
        for(i=0;i<n;i++)
        cin>>arr[i];
        mergesort(arr,0,n-1);
        for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
