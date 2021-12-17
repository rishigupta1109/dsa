#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
struct node{
    int wt;
    int u;
    int v;
    node(int x,int y,int z){
        wt=x;u=y;v=z;
    }
};
class graph{
    private:
        vector<pair<int,int>>* adj;
        int nodes;
    public:
    graph(int n){
        nodes=n;
        adj=new vector<pair<int,int>>[nodes+1];
    }
    void print(){
        for(int i=0;i<=nodes;i++){
            cout<<i<<"===";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j].first<<"->"<<adj[i][j].second<<" ";
            }
            cout<<endl;
        }
    }
    void setNodes(int edges){
        if(!nodes){cout<<"no nodes present"; return;}
        for(int i=1;i<=edges;i++){
            int x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back({y,z});
        }
    }
    void shortestPath(int source){
          vector<int> indegree(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            for(auto x:adj[i]){
                indegree[x.first]++;
            }
        }
        queue<int> q;
        queue<int> ts;
        for(int i=1;i<=nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ts.push(x);
            for(auto y:adj[x]){
                indegree[y.first]--;
                if(indegree[y.first]==0){
                    q.push(y.first);
                }
            }
        }
        vector<int> distance(nodes+1,INT_MAX);
        distance[source]=0;
        while(!ts.empty()){
            int node=ts.front();
            ts.pop();
            if(distance[node]!=INT_MAX){
                for(auto n:adj[node]){
                    if(distance[n.first]>distance[node]+n.second){
                        distance[n.first]=distance[node]+n.second;
                    }
                }
            }
        }
        cout<<endl;
        for(auto m:distance){
            cout<<m<<" ";
        }
        
    }
    void shortestPathByBellmanFord(int edges){
        vector<node> v;
        for(int i=0;i<edges;i++){
            int x,y,z;
            cin>>x>>y>>z;
            node n(z,x,y);
            v.push_back(n);
        }
        vector<int> dist(nodes+1,INT_MAX);
        dist[1]=0;
        for(int i=1;i<nodes;i++){
            for(auto x:v){
                if(dist[x.v]>dist[x.u]+x.wt){
                    dist[x.v]=dist[x.u]+x.wt;
                }
            }
        }
        bool flag=true;
        for(auto x:v){
                if(dist[x.v]>dist[x.u]+x.wt){
                    flag=false;
                }
        }
        if(flag){
            for(auto x:dist){
                cout<<x<<" ";
            }
        }
        else{
            cout<<"negative cycle";
        }
    }
    
};
int main(){
 graph g(5);
//  g.setNodes(6);
//  g.print();
// g.shortestPath(2);
g.shortestPathByBellmanFord(6);
}