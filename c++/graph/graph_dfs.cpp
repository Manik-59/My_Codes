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
void DFS_all(ll source)
{
	visit[source]=true;
	cout<<source<<" ";
	for(auto i:graph[source])
		if(visit[i]==false)
			DFS_all(i);
}
void DFS(ll source,ll node)
{
	for(ll i=0;i<node;i++)
		if(visit[i]==false)
			DFS_all(i);
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
	DFS(source,node);
}