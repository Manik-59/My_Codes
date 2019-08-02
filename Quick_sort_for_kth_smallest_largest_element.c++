#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k;
void swap(ll *a,ll *b)
{
    ll t;
    t=*a;
    *a=*b;
    *b=t;
}
ll partition(ll arr[],ll low,ll high)
{
    ll pivot=arr[high];
    ll i=low-1;
    for(ll j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
}
void quicksort(ll brr[],ll low,ll high)
{
    if(low<high)
    {
        ll pi;
        pi=partition(brr,low,high);
        if(pi==k-1)
        return;
        if(k-1<pi)
        quicksort(brr,low,pi-1);
        else if(k-1>pi)
        quicksort(brr,pi+1,high);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[i];
        cin>>k;
        quicksort(arr,0,n-1);
       for(ll i =0;i<n;i++)
        cout<<arr[i]<<" ";
      cout<<arr[k-1]<<endl;
    }
}
