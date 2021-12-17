#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    int ones=0;
    int zeeroes=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            ones++;
        }
        else{
            zeeroes++;
        }
    }
    return ones>zeeroes;
}
void solve(int n,string output=""){
    if(output.size()==n){
        cout<<output<<" ";
        return;
    }
    string o1=output+"1";
    string o2=output+"0";
    solve(n,o1);
    if(check(output)){
        solve(n,o2);
    }
}

int main(){
int n;
cin>>n;
solve(n); 
}