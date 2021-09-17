#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int Array[3];
    int D,E;
    for(int i=0;i<3;i++){
        cin>>Array[i];
    }
    cin>>D>>E;
    sort(Array,Array+3);
    int carryBag=-1;
    for(int i=2;i>=0;i--){
            if(Array[i]<=E){
                carryBag=i;
                break;
            }
    }
    if(carryBag==-1){
        cout<<"NO"<<endl;
        
    }
    else{
        int sum=0;
        for(int i=0;i<3;i++){
            if(i!=carryBag){
                sum += Array[i];
            }
        }
        if(sum<=D){
            cout<<"Yes"<<endl;
        }
        else{
           cout<<"NO"<<endl; 
        }
    }

}   
}