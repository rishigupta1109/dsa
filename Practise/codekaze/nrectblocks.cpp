#include<bits/stdc++.h>
using namespace std;
void swap(pair<int,int> &p){
    int temp=p.first;
    p.first=p.second;
    p.second=temp;
}
int main(){
int n;
cin>>n;
vector<pair<int,int>> v;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
} 
string ans="YES";
if(v[0].first<v[0].second){
    swap(v[0]);
}
for(int i=1;i<n;i++){
    int x=v[i].first;
    int y=v[i].second;
    if(x>v[i-1].first&&y>v[i-1].first){
        ans="NO";
        break;
    }
    else if(y<v[i-1].first){
        swap(v[i]);
    }

}
cout<<ans;
}