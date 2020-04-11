#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pii pair<int,int>
#define pb push_back

using namespace std;
int cnt;
string substract(string s,string m){
    string t="",k="";
    int dif=s.size()-m.size();
    for(int i=1;i<=dif;i++)k+='0';k+=m;
    reverse(s.begin(),s.end());
    reverse(k.begin(),k.end());
    string ans="";
    for(int i=0;i<s.size();i++){
        int a=s[i]-'0';
        int b=k[i]-'0';
        a+=cnt;
        cnt=0;
        int c;
        if(a<b){
            c=a+10-b+cnt;
            cnt--;
        }
        else c=a-b;

        char ci=c+'0';
        ans+=ci;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}



string mult(string s,int b){
      cnt=0;
      reverse(s.begin(),s.end());
      string ans="";
      for(int i=0;i<s.size();i++){
        int a=s[i]-'0';
        int c=a*b+cnt;
        cnt=c/10;
        char k=(c%10)+'0';
        ans+=k;
      }
      while(cnt>0){
        ans+=cnt%10+'0';
        cnt/=10;
      }
      reverse(ans.begin(),ans.end());
      return ans;
}

bool comp(string a,string b){
    if(a.size()<b.size()){
        string t=a;
        a="";
        for(int i=1;i<=(b.size()-t.size());i++)a+='0';a+=t;
    }

    if(a.size()>b.size()){
        string t=b;
        b="";
        for(int i=1;i<=(a.size()-t.size());i++)b+='0';b+=t;
    }

    if(a<b)return false;
    if(a>=b)return true;
}

pair<string,string>sqroot(string a){
     string t=a;if(a.size()%2==1)a="0",a+=t;

     string ans="",nasht="",cur="";
     for(int i=0;i<a.size();i+=2){
        string h="";h+=a[i];h+=a[i+1];
        for(int k=9;k>=0;k--){
            string cur1=cur;
            string nasht1=nasht;nasht1+=h;
            char c=k+'0';
            cur1+=c;
            cur1=mult(cur1,k);
            if(comp(nasht1,cur1)){
                ans+=c;
                nasht=substract(nasht1,cur1);
                cur=cur1;
                cur=mult(ans,2);
                break;
            }
        }
     }
     return {ans,nasht};
}
bool comp1(string a,string b){
    if(a.size()<b.size()){
        string t=a;
        a="";
        for(int i=1;i<=(b.size()-t.size());i++)a+='0';a+=t;
    }

    if(a.size()>b.size()){
        string t=b;
        b="";
        for(int i=1;i<=(a.size()-t.size());i++)b+='0';b+=t;
    }

    if(a<=b)return false;
    if(a>b)return true;
}

int main(){

    string l,r;cin>>l>>r;
    string x=sqroot(l).ff,mod=sqroot(l).ss;

    if(!comp1(mod,x))x=substract(x,"1");

    string y=sqroot(r).ff,mod1=sqroot(r).ss;
    if(!comp(mod1,y))y=substract(y,"1");
    cout<<substract(y,x);
}


