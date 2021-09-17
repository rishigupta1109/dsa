#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
vector<int> answer;
while(T--){
    int N;
    cin>>N;
  
   
        map<int,int> m;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(m.find(x)==m.end()){
            m[x]=1;
        }
        else{
            m[x]=m[x]+1;
        }
    }
    int max=0;
    for(auto x:m){
        if(x.second>max){
            max=x.second;
        }
    }
    int ans=(N-max);
    if(max==1){
        ans=N-2;
    }
    
    if(N==2||N==1){
        ans=0;
    }
    answer.push_back(ans);
   
} 
for(int i=0;i<answer.size();i++){
    cout<<answer[i]<<endl;
}
}