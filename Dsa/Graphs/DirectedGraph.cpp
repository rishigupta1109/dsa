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
        }
    }
    bool dfsCycledetector(int i,vector<int> &visitedGod,vector<int> &visited){
        visitedGod[i]=1;
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(!visited[adj[i][j]]){
                if(dfsCycledetector(adj[i][j],visitedGod,visited)){
                    return true;
                }
            }
            else if(visited[adj[i][j]]&&visitedGod[adj[i][j]]){
                return true;
            }
            
        }
        return false;
    }
    bool dfsHasCycle(){
        vector<int> visitedGod(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            if(!visitedGod[i]){
                vector<int> visited(nodes+1,0);
                visitedGod[i]=1;
                visited[i]=1;
                if(dfsCycledetector(i,visitedGod,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    void DFStopologicalOrderFinder(int i,vector<int> &v,stack<int> &s){
        v[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(!v[adj[i][j]]){
                DFStopologicalOrderFinder(adj[i][j],v,s);
            }
        }
        s.push(i);
    }
    stack<int> topologicalOrderusingDFS(){
        stack<int> s;
        vector<int> visited(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                DFStopologicalOrderFinder(i,visited,s);
            }
        }
        return s;
    }
    void topologicalOrderusingBFS(){
        vector<int> indegree(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cout<<x<<" ";
            for(auto y:adj[x]){
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                }
            }
        }
    }
    bool hasCycleusingBFS(){
        vector<int> indegree(nodes+1,0);
        vector<int> topologicalsort;
        for(int i=1;i<=nodes;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            topologicalsort.push_back(node);
            q.pop();
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(topologicalsort.size()==nodes){
            return false;
        }
        // cout<<topologicalsort.size();
        for(auto x:topologicalsort){
            cout<<x<<" ";
        }
        return true;
        
    }
    void dfs(int i,int visited[],vector<int> v[]){
        visited[i]=1;
        cout<<i<<" ";
        for(auto x:v[i]){
            if(!visited[x]){
                dfs(x,visited,v);
            }
        }
    }
    void KosarajusSCC(){
        stack<int> s=this->topologicalOrderusingDFS();
        vector<int> v[nodes+1];
        for(int i=1;i<nodes+1;i++){
            for(auto x:adj[i]){
                v[x].push_back(i);
            }
        }
        int visited[nodes+1]={0};
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                dfs(i,visited,v);
                cout<<endl;
            }
        }
    }
    
};
int main(){
  graph* g=new graph(5);
  g->setNodes(5);
// //cout<<g->dfsHasCycle();
// // g->topologicalOrderusingDFS();
// // g->topologicalOrderusingBFS();
// cout<<g->hasCycleusingBFS();
g->KosarajusSCC();
}