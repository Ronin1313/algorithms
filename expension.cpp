#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>vec;
void solution(int i,int m=n){
    vec.push_back(i);
    if(m==i){
 		for(int p=0;p<vec.size();p++){
        	if(vec.size()!=p+1)
        	cout<<vec[p]<<'+';
        	else cout<<vec[p]<<endl;
    	}
	}
	int j=m-i;
	for(int k=i;k<=j;k++){
  		solution(k,j);
	}
 	vec.pop_back();
}
int main(){
    cin>>n;
for(int i=1;i<=n/2;i++)
    solution(i,n);
return 0;
}
