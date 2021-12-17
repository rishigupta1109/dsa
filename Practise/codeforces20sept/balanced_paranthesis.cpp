#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int o,int c,vector<string> &v,int n, string output){
    if(v.size()==n){
        return;
    }
    if(o==0&&c==0){
        v.push_back(output);
        return;
    }
    string op1=output+"(";
    string op2=output+")";
     
    if(o==c){
        solve(o-1,c,v,n,op1);
    }
    else if(o==0){
         solve(o,c-1,v,n,op2);
    }
    else if(c==0){
        solve(o-1,c,v,n,op1);
    }
    else{
        solve(o-1,c,v,n,op1);
        solve(o,c-1,v,n,op2);
    }
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<string> v;
    solve(n,n,v,n,"");
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }
} 
}