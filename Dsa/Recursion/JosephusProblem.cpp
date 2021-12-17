#include<bits/stdc++.h>
using namespace std;
string fill(int n){
    string str;
    for(int i=1;i<=n;i++){
        char temp=i+'0';
        str.push_back(temp);
    }
    return str;
}
void solve(int n,int k,int s,string o){
    if(o.length()==1){
        int x=o[0]-'0';
        cout<<x;
        return;
    }
    int x=(k%o.size())+s-1;
    if(x>=o.size()){
        x=x%o.size();
    }
    o.erase(x,1);
    if(x>=o.size()){
        x=x%o.size();
    }
    solve(n,k,x,o);
}
int main(){
int n,k;
cin>>n>>k;
solve(n,k,0,fill(n)); 
}