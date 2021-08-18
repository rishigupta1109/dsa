#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int M,N,Q;
    cin>>N>>M>>Q;
    map<int,int> conductor;
    string Answer="Consistent";
    while(Q--){
        int x;
        char ch;
        cin>>ch;
        cin>>x;
        if(ch=='+'&&(conductor.find(x)==conductor.end())){
            conductor[x]=1;
        }
        else if(ch=='-'&&(conductor.find(x)!=conductor.end())){
             conductor.erase(x);
        }
        else{
            Answer="Inconsistent";
        }
        if(conductor.size()>M){
             Answer="Inconsistent";
        }
    }
        
        cout<<Answer<<endl;
} 
}