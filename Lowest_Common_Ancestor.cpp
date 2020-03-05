#include<bits/stdc++.h>
using namespace std;
int a[100001][21];
int p[100001];
int d[100001];
int n;
vector<int>g[100001];
void dfs(int v,int e=-1){
	p[v]=e;
	if(e!=-1)d[v]=d[e]+1;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]!=e)dfs(g[v][i],v);
	}
}
void prepare(){
	dfs(1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=20;j++){
			if(j==0)a[i][j]=p[i];
			else a[i][j]=-1;
		}
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			
			a[i][j]=a[a[i][j-1]][j-1];
		}
	}
}
int lca(int v,int u){
	if(d[v]>d[u])
	swap(u,v);
	int k=d[u]-d[v];
	while(k!=0){
		int t=log2(k);
		u=a[u][t];
		k-=(1<<t);
	}
	if(v==u)return v;
	for(int j=20;j>=0;j--){
		if(a[u][j]!=a[v][j])
		u=a[u][j],v=a[v][j];
	}
	return p[v];
}
int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	prepare();
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<20;j++)
//		cout<<a[i][j]<<' ';
//		cout<<endl;
//	}
	int q;cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v);
	}
}
