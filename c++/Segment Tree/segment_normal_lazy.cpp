#include<bits/stdc++.h>
using namespace std;
# define ll long long
ll tree[80000];
ll lazy[80000];

ll query(ll ts,ll te ,ll qs,ll qe ,ll index)
{
	    ///Complete Overlap
	if(qs<=ts and qe>=te)
		return tree[index];
	    //No Overlap
	else if (qe<ts ||qs>te)
		return LONG_MAX;
    //Partial Overlap - Call both sides and update the current ans 
	else
	{
		ll mid=(ts+te)/2;
		return min(query(ts,mid,qs,qe,2*index),query(mid+1,te,qs,qe,2*index+1));
	}
}


ll query_lazy(ll ts,ll te,ll qs,ll qe,index)
{
	    // First step - resolve the Lazy value

	if(lazy[index]!=0)
	{
		tree[index]+=lazy[index];
		// if not a leaf node
		if(ts!=te)
		{
			lazy[2*index]+=lazy[index];
			lazy[2*index+1]+=lazy[index];
		}
		lazy[index]=0;
	}
	    //No Overlap 

	if(qe<ts||qs>te)
		return INT_MAX;
	//complete overlap
	if(qs<=ts and qe>=te)
		return tree[index];
	// partial overlap
	ll mid=(ts+te)/2;
	return min(query_lazy(ts,mid,qs,qe,2*index),query_lazy(mid+1,te,qs,qe,2*index+1));
}


void build(ll a[],ll start,ll end,ll index)
{	
	if(start==end)
	{
		tree[index]=a[start];
		return ;
	}
	//Rec case
	else
	{
		ll mid=(start+end)/2;
		build(a,start,mid,2*index);
		build(a,mid+1,end,2*index+1);
		tree[index]=min(tree[2*index],tree[2*index+1]);
		return ;
	}

}
void update(ll ts,ll te,ll point,ll val,ll index)
{
	// leaf node
	if(point==ts and point==te)
		{
			tree[index]=val;
			return ;
		}
	// Left anf right call
	if(point>=ts and point<=te)
	{
		ll mid=(ts+te)/2;
		update( ts,mid,point,val,2*index);
		update(mid+1,te,point,val,2*index+1);
		tree[index]=min(tree[2*index],tree[2*index+1]);
		return ;
	}
}
void update_Range(ll ts,ll te,ll us,ll ue,ll val,ll index)
{
	    //Out of bounds 

	if(us>te||ue<ts)
		return;
	    // Leaf Node 

	if(ts==te)
		{
			tree[index]=+val;
			return;
		}
	 // Left and Right  Call Otherwise 
	ll mid=(ts+te)/2;
	update_Range(ts,mid,us,ue,val,2*index);
	update_Range(mid+1,te,us,ue,val,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;

}
void update_Range_Lazy(ll ts,ll te,ll us,ll ue,ll val,ll index)
{
	//First Step - Never we go down if you have lazy value at node, first resolve it 
	if(lazy[index]!=0)
	{
		tree[index]+=lazy[index];
		//if not a leaf node 
		if(ts!=te)
		{
			lazy[2*index]=lazy[index];
			lazy[2*index+1]=lazy[index];
		}
		lazy[index]=0;
	}
	// Out of Bounds 
	if(us>te||ue<ts)
		return;
	    // Complete Overlap- Beeche Raste Mei

	if(us<=ts and ue>=te)
	{
		tree[index]+=val;
		        // Pass the lazy value to children 

		if(ts!=te)
		{
			lazy[2*index]+=inc;
			lazy[2*index+1]+=inc;
		}
		return;
	}
	ll mid=(ts+te)/2;
	update_Range_Lazy(ts,mid,us,ue,val,2*index);
	update_Range_Lazy(mid+1,te,us,ue,val,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}
int main()
{
	ll n;
	cin>>n;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
		cin>>arr[i];
	build(arr,1,n,1);
	/*for(ll i=1;i<=2*n+1;i++)
		cout<<tree[i]<<" ";*/
	ll upd,ind;
	cin>>ind>>upd;
	update(1,n,ind,upd,1);
	for(ll i=1;i<=2*n+1;i++)
	cout<<tree[i]<<" ";
	ll l,r;
	cin>>l>>r;
	cout<<query(1,n,l,r,1);

}