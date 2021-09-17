#include<bits/stdc++.h>
using namespace std;

int main(){
signed long long int T;
cin>>T;
while(T--){
    signed long long int N,K;
    cin>>N>>K;
    signed long long int Array[N];
    for(int i=0;i<N;i++){
        cin>>Array[i];
    }
    signed long long int breaker=-1;
    for(int i=0;i<K;i++){
       signed long long int temp[N]={0};
       bool allgood=true;
       bool allbad=true;
        for(int j=0;j<N;j++){
            if(Array[j]>0){
                if(j==0){
                    temp[j+1]++;
                    temp[N-1]++;
                }
                else if(j==(N-1)){
                    temp[j-1]++;
                    temp[0]++;
                }
                else{
                     temp[j+1]++;
                      temp[j-1]++;
                }
                allbad=false;
            }
            else{
                allgood=false;
            }
        }
        if(allgood){
            breaker=i;
                break;
        }
        else if(allbad){
            break;
        }
        else{
            for(int j=0;j<N;j++){
                Array[j]+=temp[j];
            }
        }
      
    }
    signed long long int sum=0;
    if(breaker!=-1){
            for(int j=0;j<N;j++){   
                Array[j]+=2*(K-breaker);
                sum=sum+Array[j];
            }
    }
    else{
            for(int i=0;i<N;i++){
                sum=sum+Array[i];
            }
    }
    
    cout<<sum<<endl;
} 

}