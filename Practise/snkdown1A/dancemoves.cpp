#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int x,y;
    cin>>x>>y;
    int z=abs(x-y);
    int steps=0;
    if(z%2==0&&x<y){
        steps=z/2;
    }
    else if(z%2!=0&&x<y){
        steps=z/2+z%2+1;
    }
    else if(x==y){
        steps=0;
    }
    else{
        steps=z;
    }
    cout<<steps<<endl;
} 
}