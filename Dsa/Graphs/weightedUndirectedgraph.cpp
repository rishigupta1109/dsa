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
int comp(node a,node b){
    return a.wt<b.wt;
}
class disjointset{
    private:
        int* rank;
        int* parent;
    public:
        disjointset(int nodes){
            rank =new int[nodes+1]{0};
            parent =new int[nodes+1];
            for(int i=0;i<=nodes;i++){
                parent[i]=i;
            }
        }
        int findParent(int i){
            if(parent[i]==i){
                return i;
            }
            return parent[i]=findParent(parent[i]);
        }
        void unnion(int x,int y){
            int a=findParent(x);
            int b=findParent(y);
            if(a!=b){
                if(rank[a]>rank[b]){
                    parent[b]=a;
                }
                else if(rank[b]>rank[a]){
                    parent[a]=b;
                }
                else{
                    parent[a]=b;
                    rank[b]++;
                }
            }
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
            adj[y].push_back({x,z});
        }
    }
    void shortestPathDijikstrasalgo(int source){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> distance(nodes+1,INT_MAX);
        distance[source]=0;
        pq.push({0,source});
        while(!pq.empty()){
            pi node=pq.top();
            pq.pop();
            int x=node.first;
            int y=node.second;
            for(auto n:adj[y]){
                if(x+n.second<distance[n.first]){
                    distance[n.first]=x+n.second;
                    pq.push({distance[n.first],n.first});
                }
            }
        }
        for(auto x:distance){
            cout<<x<<" ";
        }
    }
    void minimumSpanningTreePrims(int source){
        vector<int> key(nodes+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> present(nodes+1,false);
        vector<int> parent(nodes+1,-1);
        pq.push({0,source});
        key[source]=0;
        for(int i=0;i<nodes-1;i++){
            pair<int,int> p=pq.top();
            pq.pop();
            present[p.second]=true;
            for(auto x:adj[p.second]){
                if(!present[x.first]&&key[x.first]>x.second){
                    key[x.first]=x.second;
                    parent[x.first]=p.second;
                    pq.push({x.second,x.first});
                }
            }
        }
        for(int i=1;i<=nodes;i++){
            if(parent[i]!=-1)
            cout<<i<<"->"<<parent[i]<<endl;
        }
    }
    void minimumSpanningTreeKruskals(int nodes,int edges){
  
        vector<node> v;
        disjointset ds(nodes);
        for(int i=0;i<edges;i++){
            int x,y,z;
            cin>>x>>y>>z;    
            
            node n(z,x,y);
            v.push_back(n);
        }
        sort(v.begin(),v.end(),comp);
        for(auto n:v){
            if(ds.findParent(n.u)!=ds.findParent(n.v)){
                cout<<n.u<<"->"<<n.v<<endl;
                ds.unnion(n.u,n.v);
            }
        }
    }
};
int main(){
 graph g(6);
    
//  g.setNodes(9);
//  g.print();
// g.shortestPathDijikstrasalgo(1);
// g.minimumSpanningTreePrims(5);
g.minimumSpanningTreeKruskals(6,9);
}