#include<bits/stdc++.h>
using namespace std;
class graph{
    private:
    int** adj;
    int nodes;
    public:
    graph(int nodes){
        this->nodes=nodes;
        adj=new int*[nodes+1];
        for(int i=0;i<=nodes;i++){
            adj[i]=new int[nodes+1]{0};
        }
    }
    void printmatrix(){
        for(int i=0;i<=nodes;i++){
            for(int j=0;j<=nodes;j++) cout<<adj[i][j]<<" ";
            cout<<endl;
        }
    }
    void setNodes(int edges){
        for(int i=1;i<=edges;i++){
            int x,y;
            cin>>x>>y;
            adj[x][y]=1;
            adj[y][x]=1;
        }
        
    }
    void bfsTraversal(){
        if(!nodes) {cout<<"no nodes are present";return ;}
        int visited[nodes+1]={0};
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    cout<<x<<" ";
                    visited[x]=1;
                    for(int j=0;j<=nodes;j++){
                        if(adj[x][j]&&!visited[j]){
                             visited[j]=1;
                            q.push(j);
                        }
                    }
                   
                }
            }
        }
    }
    void dfsHelper(int value,int visited[]){
        cout<<value<<" ";
        visited[value]=1;
        for(int j=0;j<=nodes;j++){
            if(adj[value][j]&&!visited[j]){
                dfsHelper(j,visited);
            }
        }
    }
    void dfsTraversal(){
        int visited[nodes+1]={0};
        for(int i=1;i<=nodes;i++){
            if(!visited[i]){
                dfsHelper(i,visited);
            }
        }
    }
  
};
int main(){
    graph g(7);
    g.setNodes(6);
    g.dfsTraversal();
    // g.bfsTraversal();
}