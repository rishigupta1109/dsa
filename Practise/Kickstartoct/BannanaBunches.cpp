#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int i=1;i<=t;i++){
    int N,K;
    cin>>N>>K;
    priority_queue<pair<int,int>> pq;
    for(int j=0;j<N;j++){
        int element;
        cin>>element;
       pq.push({element,i});
    }
    bool contagious=true;
    int count=0;
    int check[N]={0};
    int indices[N]={0};
    for(int k=0;k<N;k++){
        int value=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
        if(count+value<=K){
           if(idx!=0&&idx!=N-1&&check[idx-1]==0&&check[idx+1]==0){
               count+=value;
               check[idx]++;
               indices[idx]++;
           }
        }
        

    }
   
} 
}