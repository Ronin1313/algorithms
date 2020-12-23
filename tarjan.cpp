#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define epb emplace_back
using namespace std;

vector<vector<int> >g(1000001);
vector<bool>used(1000001,false);
vector<int>t_in(1000001);
vector<int>low(1000001);
int timer=0;
vector<pii>bridges;

void dfs(int v,int e=-1){
    used[v]=true;
    low[v]=t_in[v]=timer++;
    for(auto to:g[v]){
        if(to==e)continue;
        if(used[to]){
            low[v]=min(low[v],low[to]);
            continue;
        }
        dfs(to,v);
        if(low[to]>t_in[v]){
            bridges.epb(v,to);

        }
        low[v]=min(low[v],low[to]);
    }
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(!used[i])dfs(i);
    }
    for(auto ans:bridges){
        cout<<ans.f<<' '<<ans.s<<"\n";
    }
}

int main(){
    solve();
    return 0;
}
