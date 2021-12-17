#include<bits/stdc++.h>
using namespace std;
void solve(int o,int c,string output=""){
    if(o==0&c==0){
        cout<<output<<" ";
        return;
    }
    string o1=output+"(";
    string o2=output+")";
    if(o==c){
        solve(o-1,c,o1);
        return;
    }
    else if(o!=0&&c!=0){
        solve(o-1,c,o1);
        solve(o,c-1,o2);
    }
    else if(o==0){
         solve(o,c-1,o2);
    }
    else{
         solve(o-1,c,o1);
    }
}
int main(){
int n;
cin>>n;
solve(n,n); 
}