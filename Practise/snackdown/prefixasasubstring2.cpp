#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string S1,S2,X;
    cin>>S1>>S2>>X;
    unsigned long long int answer=1;
    string P="",Q="";
    unsigned long long int maxPidx=S1.length(),maxQidx=S2.length();
    for( unsigned long long int i=0;i<S1.length();i++){
        P+=S1[i];
         unsigned long long int finder=X.find(P);
        if(finder>=X.length()){
            maxPidx=i;
            break;
        }
        answer++;
    }
    for( unsigned long long int i=0;i<S2.length();i++){
        Q+=S2[i];
         unsigned long long int finder=X.find(Q);
        if(finder>=X.length()){
            maxQidx=i;
            break;
        }
        answer++;
    }
   
    P="",Q="";
    for( unsigned long long int i=0;i<maxPidx;i++){
        P+=S1[i];
        for(int j=0;j<maxQidx;j++){
            Q+=S2[j];
            string R=P+Q;
            int finder=X.find(R);
            if(finder>=X.length()){
                Q="";
                break;
            }
            answer++;
        }
    }
    cout<<answer;
    if(t!=0)cout<<endl;
} 
}