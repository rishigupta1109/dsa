#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    
        int z=(N*(N+1))/2;
        if(z%2==0){
            cout<<N<<endl;
           
        }
        else{
            cout<<N-1<<endl;
        }
    
} 
}