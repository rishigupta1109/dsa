#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    if(N%2==0){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<-1<<" ";
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j){
                    cout<<-1<<" ";
                }
                else{
                    cout<<1<<" ";
                }
            }
            cout<<endl;
        }
    }
} 
}