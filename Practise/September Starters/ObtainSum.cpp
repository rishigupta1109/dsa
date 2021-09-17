#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int N,S;
    cin>>N>>S;
    int Sum=(N*(N+1))/2;
    if((Sum-S)>N||(Sum-S)<=0){
        cout<<-1<<endl;
    }
    else{
        cout<<Sum-S<<endl;
    }
} 
}