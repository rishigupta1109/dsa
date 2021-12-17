#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        int N,D,C,M;
        cin>>N>>D>>C>>M;
        string s;
        cin>>s;
        bool dogFed=true;
        for(int i=0;i<N;i++){
            if(s[i]=='C'){
                if(C==0){
                    for(int k=i+1;k<N;k++){
                        if(s[k]=='D'){
                            dogFed=false;
                        }
                    }
                    break;
                }
                C--;
                D+=M;
            }
            else{
                if(D==0){dogFed=false; break;}
                D--;
            }
        }
        if(dogFed){
            cout<<"Case #"<<j<<": YES";
        }
        else{
              cout<<"Case #"<<j<<": NO";
        }
        cout<<endl;
    }
}