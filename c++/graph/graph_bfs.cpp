#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define pd push_back
using namespace std;
vector<vector<ll>>graph;
vector<bool>visit;
void add_edge(ll a,ll b,bool bidirec)
{
	graph[a].push_back(b);
	if(bidirec)
		graph[b].push_back(a);
}
void BFS(ll source)
{
	queue<ll>q;
	q.push(source);
	visit[source]=true;
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		visit[x]=true;
		cout<<x<<" ";
		for(auto i:graph[x])
		{
			//cout<<i<<endl;
			if(visit[i]==false)
				{
					q.push(i);
					visit[i]=true;
				}
		}
	}
}
int main()
{
	ll node,edge;
	cin>>node>>edge;
	bool bidirec=true;
	visit.assign(node+1,false);
	graph.assign(node+1,vector<ll>());
	for(ll i=0;i<edge;i++)
	{
		ll a,b;
		cin>>a>>b;
		add_edge(a,b,bidirec);
	}
	ll source;
	cin>>source;
	BFS(source);
}