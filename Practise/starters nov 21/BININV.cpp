#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s[n];
        vector<pair<int,int>> v(n,{0,m});
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]==1){
                    v[i].first++;
                }
                if(s[i][j]==0&&v[i].second>j){
                    v[i].second=j;
                }
            }
        }
        list<pair<int,int>> l(v.begin(),v.end());
        l.sort();
        sort(v.begin(),v.end());
        string s="";
        while(l.size()!=0){
            pair<int,int>x=l.front();
            
        }
    }
}