#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned ll
#define epb emplace_back
#define pb push_back
using namespace std;

struct Edge{
    int u,v,cap;
    int flow=0;
    Edge(int u,int v,int cap):u(u),v(v),cap(cap){}
    int res_cap(){
        return cap-flow;
    }
    void augment(int nf){
        flow+=nf;
    }
};

struct Dinitz{
    int n,s,t;
    vector<Edge>edges;
    vector<vector<int> >g;
    vector<int>level;
    vector<int>ptr;

    Dinitz(int n,int s,int t):n(n),s(s),t(t){
        g.resize(n+1);
        level.assign(n+1,-1);
        ptr.assign(n+1,0);
    }
    int eind=0;

    void add(int u,int v,int cap){
        edges.epb(u,v,cap);
        edges.epb(v,u,0);
        g[u].pb(eind++);
        g[v].pb(eind++);
    }

    bool BFS(){
        fill(level.begin(),level.end(),-1);
        level[s]=0;

        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(auto i:g[v]){
                Edge &E=edges[i];
                if(E.res_cap()&&level[E.v]==-1)level[E.v]=level[v]+1,q.push(E.v);
            }
        }
        return level[t]!=-1;
    }

    int dfs(int v,int flow){
        if(v==t)return flow;
        for(int &i=ptr[v];i<g[v].size();i++){
            int ind=g[v][i];
            Edge &E=edges[ind];
            Edge &E_rev=edges[ind^1];
            if(E.res_cap()&&level[E.v]==level[v]+1){
                int new_flow=dfs(E.v,min(flow,E.res_cap()));
                if(new_flow){
                    E.augment(new_flow);
                    E_rev.augment(-new_flow);
                    return new_flow;
                }
            }
        }
        return 0;
    }

    int max_flow(){
        int mxf=0;
        while(true){
             fill(ptr.begin(),ptr.end(),0);
            if(!BFS())break;
            while(int k=dfs(s,INT_MAX))mxf+=k;
        }
        return mxf;
    }

};

void solve(){
    int n;cin>>n;
    int m;cin>>m;
    int s,t;cin>>s>>t;
    Dinitz solver(n,s,t);
    for(int i=1;i<=m;i++){
        int u,v,cap;
        cin>>u>>v>>cap;
        solver.add(u,v,cap);
    }
    cout<<solver.max_flow();
}

int main(){
    solve();

    return 0;
}
