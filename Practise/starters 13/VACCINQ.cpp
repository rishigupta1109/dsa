#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int N,P,X,Y;
    cin>>N>>P>>X>>Y;
    int Q[N];
    for(int i=0;i<N;i++){
        cin>>Q[i];
    }
    int time=0;
    for(int i=0;i<P;i++){
        if(Q[i]){
            time+=Y;
        }
        else{
            time+=X;
        }
    }
    cout<<time<<endl;
} 
}