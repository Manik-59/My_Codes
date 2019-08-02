#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define pd push_back
using namespace std;
vector<vector<ll>>graph;
vector<bool>visit;
void add_edge(ll a,ll b)
{
	graph[a].push_back(b);
}
void BFS(ll source,ll des)
{
	queue<ll>q;
	int distance[100]={0};
	int parent[100]={0},y;
	q.push(source);
	distance[source]=0;
	visit[source]=true;
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		for(auto i:graph[x])
		{
			
			if(visit[i]==false)
				{
					q.push(i);
					distance[i]=distance[x]+1;
					parent[i]=x;
					visit[i]=true;
				}

		}
	}
	
	cout<<"MINIMUM DISTANCE"<<distance[des]<<endl;
	cout<<"PATH";
	y=des;
	while(y!=source)
	{
		cout<<y<<"-------";
		y=parent[y];
	}
	cout<<source;
}
int main()
{
	int snake_ladder[101]={0};
	int ladder,snake,i,j;
	cin>>ladder>>snake;
	for(i=0;i<ladder;i++)
	{
		ll x,y;
		cin>>x>>y;
		snake_ladder[x]=y-x;
	}
	for(i=0;i<snake;i++)
	{
		ll x,y;
		cin>>x>>y;
		snake_ladder[x]=y-x;
	}
	
	visit.assign(101,false);
	graph.assign(101,vector<ll>());
	for(i=1;i<94;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(snake_ladder[i]==0)
			add_edge(i,(i+j+snake_ladder[i+j]));
		}
	}
	for(i=94;i<100;i++)
	{
		for(j=1;j<101-i;j++)
			{
				if(snake_ladder[i]==0)
				add_edge(i,(i+j+snake_ladder[i+j]));
			}
	}
	int source,des;
	cin>>source>>des;
	BFS(source,des);
}