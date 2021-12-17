#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>* adj,int &maxht,int ht,int p,vector<int> visited){
    if(i==p){
        return ;
    }
    visited[i]=1;
    if(ht>maxht){
        maxht=ht;
    }
    for(int j=0;j<adj[i].size();j++){
        if(!visited[adj[i][j]])
          dfs(adj[i][j],adj,maxht,ht+1,i,visited);
    }
    return;
}
int main(){
int n;
cin>>n;
 vector<int> adj[n+1];

for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
} 
for(int i=1;i<=n;i++){
    int maxht=0;
    for(int j=0;j<adj[i].size();j++){
        vector<int> visited(n+1,0);
        visited[i]=1;
        dfs(adj[i][j],adj,maxht,1,i,visited);
    }
    cout<<maxht<<" ";
}
}