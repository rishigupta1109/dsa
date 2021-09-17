#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    
    int N;
    cin>>N;
    int array[N];
    priority_queue <pair<int,int>> pq;
    for(int i=0;i<N;i++){
        cin>>array[i];
        pq.push({array[i],i});
    }
    int moves=0;
    bool impossible=false;
    for(int i=0;i<N-1;){
        pair<int,int> max={INT_MIN,-1};
        int M;
        while(true){
            if(pq.top().second>i){
                break;
            }
            pq.pop();
        }
        M=pq.top().second;
        
        for(int j=i+1;j<=M;j++){
            if(array[j]>array[i]){
                cout<<-1<<endl;
                impossible=true;
                break;
            }
            else{
                if(array[j]>=max.first){
                    max.first=array[j];
                    max.second=j;
                }
            }
        }
        if(impossible){
          
            break;
        }
        moves++;
        i=max.second;
        
    }
   
    if(impossible){
        continue;
    }
     cout<<moves<<endl;
} 
}