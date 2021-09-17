#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    vector<int> s;
    unordered_set<int> s1;
    unordered_set<int> s2;
    for(int i=0;i<2;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    for(int i=0;i<2;i++){
        int x;
        cin>>x;
        s1.insert(x);
    }
    for(int i=0;i<2;i++){
        int x;
        cin>>x;
        s2.insert(x);
    }
    bool inS1=true;
    for(int i=0;i<2;i++){
        if(s1.find(s[i])==s1.end()){
            inS1=false;
            break;
        }
    }
    if(inS1){
        cout<<1<<endl;
        continue;
    }
    bool inS2=true;
    for(int i=0;i<2;i++){
        if(s2.find(s[i])==s2.end()){
            inS2=false;
            break;
        }
    }
    if(inS2){
        cout<<2<<endl;
        continue;
    }
    cout<<0<<endl;
} 
}