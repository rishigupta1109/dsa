#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    unsigned long long int arr[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    unsigned long long int max=arr[0];
    for(int i=1;i<n;i++){
       if(arr[i]>max) {
           max=arr[i];
       }
    }
    unsigned long long int x=0;
    unsigned long long int answer=-1;
    while(pow(2,x)<max) x++;
    for( unsigned long long int i=0;i<=x*16;i++){
        unsigned long long int a=(arr[0]+i);
        for(int j=1;j<n;j++){
            a^=(arr[j]+i);
        }
        if(a==0){
            answer=i;
            break;
        }   }
   
    cout<<answer<<endl;
      }
} 
