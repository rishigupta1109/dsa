#include<bits/stdc++.h>
using namespace std;
string makeanumber(int n){
    string s;
    s.push_back('1');
    for(int i=1;i<=n-2;i++){
        s.push_back('0');
    }
    s.push_back('5');
    return s;
}
int main(){
unsigned long long int t;
cin>>t;
while(t--){
    unsigned long long int n;
    cin>>n;
    if(n==1){
        cout<<3<<endl;
    }
    else{
        cout<<makeanumber(n)<<endl;
    }
} 
}