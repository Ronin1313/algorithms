#include<bits/stdc++.h>
using namespace std;
vector<int>g[100001];
int d[100001];
int p[100001];
void dfs(int v,int e){
	if(e!=-1)d[v]=d[e]+1;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]!=e)
		dfs(g[v][i],v);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int v,u;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(1,-1);
	int mx=-1,mx1;
	for(int i=1;i<=n;i++)
	if(d[i]>mx)mx=d[i],mx1=i,d[i]=0;
	dfs(mx1,-1);
	int mx2;
	mx=-1;
	for(int i=1;i<=n;i++){
		if(d[i]>mx)mx=d[i],mx2=i,d[i]=0;
	}
	cout<<mx1<<' '<<mx2;
}
