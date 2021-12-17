#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int N,K;
    cin>>N>>K;
    if(N==K){
        for(int i=1;i<=N;i++){
            cout<<i<<" ";
        }
    }
    else if(K==N-1){
        cout<<-1;
    }
    else{
        for(int i=1;i<=K;i++){
            cout<<i<<" ";
        }
        cout<<N<<" ";
        for(int i=K+1;i<N;i++){
            cout<<i<<" ";
        }
    }
    cout<<endl;
} 
}