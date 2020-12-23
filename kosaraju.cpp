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
vector<vector<int> >g_rev(1000001);
vector<bool>used(1000001,false);
stack<int>st;

void dfs(int v){
    used[v]=true;
    for(auto to:g[v]){
        if(!used[to])dfs(to);
    }
    st.push(v);
}

void DFS(int v){
    used[v]=true;
    for(auto to:g_rev[v]){
        if(!used[to])DFS(to);
    }
    cout<<v<<' ';
}

void solve(){
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g_rev[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(!used[i])dfs(i);
    }
    fill(used.begin(),used.end(),false);
    while(!st.empty()){
        int v=st.top();
        st.pop();
        if(!used[v]){
            DFS(v);
            cout<<"\n";
        }

    }
}



int main(){
    solve();
}
