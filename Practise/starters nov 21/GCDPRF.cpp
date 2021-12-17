#include<bits/stdc++.h>
using namespace std;
int gcd(int array[],int i,int j){
    if(i==j) return array[j];
    int nextnum=gcd(array,i+1,j);
    for(int k=min(array[i],nextnum);k>=2;k--){
        if((array[i]%k)==0&&(nextnum%k)==0){
            return k;
        }
    }
    return -1;
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int B[n];
    bool flag=true;
    for(int i=n-1;i>=0;i--){
        int x=gcd(array,0,i);
        if(x==-1){
            flag=false;
            break;
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
    else{
        for(auto Y:array){
            cout<<Y<<" ";
        }
        cout<<endl;
    }
} 
}