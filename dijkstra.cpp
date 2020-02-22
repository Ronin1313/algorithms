#include<bits/stdc++.h>
using namespace std;
vector<int>d(100000+1,1e9+1);
int p[100000+1];
vector<pair<int,int> >g[100001];
void Dijkstra(int st){
	d[st]=0;
	set<pair<int,int> >s;
	s.insert({d[st],st});
	while(!s.empty()){
		int v=s.begin()->second;
		s.erase(s.begin());
		for(int i=0;i<g[v].size();i++){
			int to=g[v][i].first,len=g[v][i].second;
			if(d[to]>d[v]+len){
				s.erase({d[to],to});
				d[to]=d[v]+len;
				p[to]=v;
				s.insert({d[to],to});
			}
		}
	}
}
int main(){
	int n;cin>>n;
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		int cost;
		cin>>cost;
		g[v].push_back({u,cost});
		g[u].push_back({v,cost});
	}
	int s,f;
	cin>>s>>f;
	Dijkstra(s);
	cout<<d[f]<<endl;
	int j=f;
	vector<int>ans;
	while(j!=s){
		ans.push_back(j);
		j=p[j];
	}
	ans.push_back(s);
	for(int i=0;i<ans.size();i++)
		cout<<a[i]<<' ';
}
