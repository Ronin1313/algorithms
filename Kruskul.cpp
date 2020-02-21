#include<bits/stdc++.h>
using namespace std;
int size[200001];
int p[200001];
void make_set(int v){
	p[v]=v;
	size[v]=1;
}
int find_set(int v){
	if(p[v]==v)return v;
	return p[v]=find_set(p[v]);
}
void union_sets(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(size[a]<size[b])swap(a,b);
		p[b]=a;
		size[a]+=size[b];
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	make_set(i);
	vector<pair<int,pair<int,int> > >g;
	for(int i=0;i<m;i++){
		int u,v;
		int cost;
		cin>>u>>v>>cost;
		g.push_back({cost,{u,v}});
	}
	sort(g.begin(),g.end());
	vector<pair<int,pair<int,int> > >G;
	for(int i=0;i<g.size();i++){
		int v=g[i].second.first,u=g[i].second.second,cost=g[i].first;
		if(find_set(v)!=find_set(u))G.push_back({cost,{u,v}}),union_sets(u,v);
	}
	int cnt=0;
	for(int i=0;i<G.size();i++)cnt+=G[i].first;
	cout<<cnt<<endl;
	for(int i=0;i<G.size();i++)
	cout<<G[i].second.first<<' '<<G[i].second.second<<endl;
}
