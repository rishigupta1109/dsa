#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        pq.push({element,i});
    }
    unordered_map<int,int> m;
    int A[n];
    for(int i=0;i<n;i++){
        int value=pq.top().first;
        int idx=pq.top().second;
        pq.pop();
       
        for(int j=value-1;j>=0;j--){
            if(m.find(j)==m.end()){
                m[j]++;
                value+=j;
               break;
            }
        }
        A[idx]=value;
        
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
} 
}