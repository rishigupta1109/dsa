#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
vector<int> ans;
for(int g=0;g<T;g++){
    int N=0;
    cin>>N;
    vector<pair<int,int>> v(N,make_pair(0,0));
    char s1[N+1];
    char* s2=new char[N+1];
   
   for(int i=0;i<N;i++){
       cin>>s1[i];
   }
   for(int i=0;i<N;i++){
       cin>>s2[i];
 
   }
    for(int k=0;k<N;k++){ 
        v[k].first=(int)s1[k]-(int)'0';
         v[k].second=(int)s2[k]-(int)'0';
    }
    
    int teams=0;
    vector<int> specials;
    map<int,int> teamed;
    for(int l=0;l<N;l++){
        if(v[l].first==1&&v[l].second==1){
            specials.push_back(l);
        }
        else if(v[l].first==1&&v[l].second==0){
            for(int j=0;j<N;j++){
                 if(v[j].first!=1&&v[j].second==1&&teamed.find(j)==teamed.end()){
                     teamed[j]=l;
                     break;
                 }
            }
        }

    }
    teams=teamed.size();
   
    int y=N-(teams*2)-specials.size();
    if(y>=specials.size()){teams=teams+specials.size();}
    else{
        teams=teams+y;
        int z=specials.size()-y;
        teams=teams+z/2;
    }
    ans.push_back(teams);

}
for(auto &i:ans){
    cout<<i<<endl;
}
}