#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[n+1];
	vector<int>d(n+1,1e9+1);
	d[0]=-1e9;
	for(int i=1;i<=n;i++){
	
	cin>>a[i];
	
	}
	int p[n+1];
	for(int i=1;i<=n;i++){
		if(lower_bound(d.begin(),d.end(),a[i])!=d.end()){
			int j=lower_bound(d.begin(),d.end(),a[i])-d.begin();
			d[j]=a[i];
			p[a[i]]=d[j-1];
		}
		
	}
	
	
	int ind;
	for(int i=1;i<=n;i++){
		if(d[i]!=1e9+1) ind=i;
		
	}
	for(int i=1;i<=n;i++)cout<<p[a[i]]<<endl;
	int j=d[ind];
    while(j!=-1e9){
    	cout<<j<<' ';
    	j=p[j];
	}
	
}
