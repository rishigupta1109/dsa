#include<bits/stdc++.h>
using namespace std;
class graph{
    private:
        vector<int>* adj;
        int nodes;
    public:
    graph(int n){
        nodes=n;
        adj=new vector<int>[nodes+1];
    }
    void print(){
        for(int i=0;i<=nodes;i++){
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void setNodes(int edges){
        if(!nodes){cout<<"no nodes present"; return;}
        for(int i=1;i<=edges;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    void bfsTraversal(){
        vector<int> visited(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    cout<<x<<" ";
                    visited[x]=1;
                    for(auto m:adj[x]){
                        if(!visited[m]){
                            q.push(m);
                            visited[m]=1;
                        }
                    }
                }
            }
        }
    }
    void dfsHelper(int value,vector<int> &visited){
        cout<<value<<" ";
        visited[value]=1;
        for(int i=0;i<adj[value].size();i++){
            if(!visited[adj[value][i]])
            dfsHelper(adj[value][i],visited);
        }
    }
    void dfsTraversal(){
        vector<int> visited(nodes+1,0);
        for(int i=1;i<=nodes;i++){
             if(!visited[i]){
                 dfsHelper(i,visited);
             }
        }
    }
    bool cycleDetectionUsingBFS(){
        vector<int> visited(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                queue<pair<int,int>> q;
                q.push({i,-1});
                while(!q.empty()){
                    int element=q.front().first;
                    int parent=q.front().second;
                    q.pop();
                    visited[element]=1;
                    for(auto m:adj[element]){
                        if(!visited[m]){
                            visited[m]=1;
                            q.push({m,element});
                        }
                        else if(m!=parent){
                            cout<<m<<" "<<parent<<endl;
                            return  true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool DFScycleDetectionHelper(int element,int parent,vector<int> &visited){
        visited[element]=1;
        for(auto m:adj[element]){
            if(!visited[m]){
                if(DFScycleDetectionHelper(m,element,visited)){
                    return true;
                }
            }
            else if(m!=parent){
                return true;
            }
        }
        return false;
    }
    bool cycleDetetctionusingDFS(){
        vector<int> visited(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
               if(DFScycleDetectionHelper(i,-1,visited)){
                   return true;
               }
            }
        }
        return false;
    }
    bool isBipartiteUsingBFS(){
        vector<int> color(nodes+1,-1);
        for(int i=1;i<=nodes;i++){
            bool x=false;
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=x;
                while(!q.empty()){
                    int y=q.front();
                    q.pop();
                    for(int k=0;k<adj[y].size();k++){
                        if(color[adj[y][k]]==-1){
                            color[adj[y][k]]=!color[y];
                            q.push(adj[y][k]);
                        }
                        else if(color[adj[y][k]]==color[y]){
                            return false;
                        }
                    }
                }

            }
        }
        return true;

    }
    bool bipartiteDFSHelper(int i,vector<int> &color,bool x){
        color[i]=x;
        for(int j=0;j<adj[i].size();j++){
            if(color[adj[i][j]]==-1){
                if( !bipartiteDFSHelper(adj[i][j],color,!x)){
                    return false;
                }
            }
            else if(color[adj[i][j]]==color[i]){
                return false;
            }
        }
        return true;
    }
    bool isBipartiteusingDFS(){
        vector<int> color(nodes+1,-1);
        bool a=false;
        for(int i=1;i<=nodes;i++){
            if(color[i]==-1){
                if(!bipartiteDFSHelper(i,color,a)){
                    return false;
                }
            }
        }
     
        return true;
    }
    
    void shortestPath(int src){
        vector<int> dist(nodes+1,INT_MAX);
        dist[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(dist[x]>dist[node]+1){
                    dist[x]=dist[node]+1;
                    q.push(x);
                }
            }
        }        
        for(int i=1;i<=nodes;i++){
            cout<<dist[i]<<" ";
        }
    }
    void bridgesHelper(int node,int parent,vector<int> &tIn,vector<int> &low,vector<int> &vis,int &timer){
        tIn[node]=low[node]=timer++;
        vis[node]=1;
        for(auto child:adj[node]){
            if(parent==child){continue;}
            if(!vis[child]){
                bridgesHelper(child,node,tIn,low,vis,timer);
                low[node]=min(low[node],low[child]);
                if(low[child]>tIn[node]){
                    cout<<node<<" "<<child<<endl;
                }
            }
            else{
                low[node]=min(low[node],tIn[child]);
            }
        }
    }
    void bridges(){
        vector<int> tIn(nodes+1,-1);
        vector<int> low(nodes+1,-1);
        vector<int> vis(nodes+1,0);
        int timer=0;
        for(int i=1;i<=nodes;i++){
            if(!vis[i]){
                bridgesHelper(i,-1,tIn,low,vis,timer);
            }
        }

    }
    void articulationHelper(int node,int parent,vector<int> &tIn,vector<int> &low,
    vector<int> &vis,int &timer,vector<int> &articulation)
    {
         tIn[node]=low[node]=timer++;
        vis[node]=1;
        int c=0;
        for(auto child:adj[node]){
            if(parent==child){continue;}
            if(!vis[child]){
                articulationHelper(child,node,tIn,low,vis,timer,articulation);
                low[node]=min(low[node],low[child]);
                if(low[child]>=tIn[node]&&parent!=-1){
                    articulation[node]=1;
                }
                c++;
            }
            else{
                low[node]=min(low[node],tIn[child]);
            }
        }
        if(parent==-1&&c>1){
             articulation[node]=1;
        }
    }
    void articulationPt(){
         vector<int> tIn(nodes+1,-1);
        vector<int> low(nodes+1,-1);
        vector<int> vis(nodes+1,0);
        vector<int> articulation(nodes+1,0);
        int timer=0;
        
        for(int i=1;i<=nodes;i++){
            if(!vis[i]){
                articulationHelper(i,-1,tIn,low,vis,timer,articulation);
            }
        }
        for(int i=0;i<articulation.size();i++){
            if(articulation[i])cout<<i<<" ";
        }
    }
};
int main(){
    graph g(12);
    g.setNodes(14);
    // g.print();
    // g.bfsTraversal();
    // g.dfsTraversal();
    
    // cout<<endl<<g.cycleDetectionUsingBFS();
    // cout<<endl<<g.cycleDetetctionusingDFS();
    // cout<<endl<<g.isBipartiteUsingBFS();
    // cout<<endl<<g.isBipartiteusingDFS();
    // g.shortestPath(1);
    // g.bridges();
    g.articulationPt();


}