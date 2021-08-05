#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  int z=0;
   int o=0;
   int t=0;
   for(int i=0;i<n;i++){
       if(a[i]==0){
           z++;
       }
       else if(a[i]==1){
           o++;
       }
       else{
           t++;
       }
       
   }
   for(int i=0;i<n;i++){
       if(z!=0){
           a[i]=0;
           --z;
       }
       else if(o!=0){
           a[i]=1;
           --o;
       }
       else{
           a[i]=2;
           --t;
       }
   }
   
}
       