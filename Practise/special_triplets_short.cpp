#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int t;
cin>>t;
//   scanf("%d",&t);
// vector <int> answer;
int answer[t];
int last_n=0;
int count=0; 
// vector<int> inputs;
// int inputs[t];


for(int a=0;a<t;a++){
     int n;

    //  scanf("%d",&n);
    cin>>n;
     int count_start;
    if(n==1){
         count_start=0;
    }
    else{
         count_start=2*n-3;     
    }

    if(n<last_n){
        if(count==0){    
    for( int i=4;i<=n;i++){
        for( int j=2;j<=n;j++){
           if(j%i!=0&&(i%j==0||(i%(j%i)==0&&(j%i)!=1))){
                ++count;
                // cout<<count<<i<<j<<endl; 
           } 
           if((i-1)%j==0&&(i-1)!=j&&j<i){
               ++count;
            }
           
           
        }
    }}
    else{
        int tobesubs=0;
          for( int i=n+1;i<=last_n;i++){
        for( int j=2;j<=last_n;j++){
           if(j%i!=0&&(i%j==0||(i%(j%i)==0&&(j%i)!=1))){
                ++tobesubs;
                // cout<<count<<i<<j<<endl; 
           } 
           if((i-1)%j==0&&(i-1)!=j&&j<i){
               ++tobesubs;
            } 
        }
    }
    for(int i=4;i<=n;i++){
        for( int j=n+1;j<=last_n;j++){
           if(j%i!=0&&(i%j==0||(i%(j%i)==0&&(j%i)!=1))){
                ++tobesubs;
                // cout<<count<<i<<j<<endl; 
           } 
           if((i-1)%j==0&&(i-1)!=j&&j<i){
               ++tobesubs;
            } 
        }
    }
    count=count-tobesubs;
    }
   }
   else if(n==last_n){

   }
   else{
       for( int i=last_n+1;i<=n;i++){
        for( int j=2;j<=n;j++){
           if(j%i!=0&&(i%j==0||(i%(j%i)==0&&(j%i)!=1))){
                ++count;
                // cout<<count<<i<<j<<endl; 
           } 
           if((i-1)%j==0&&(i-1)!=j&&j<i){
               ++count;
            } 
        }
    }
    for(int i=4;i<=last_n;i++){
        for( int j=last_n+1;j<=n;j++){
           if(j%i!=0&&(i%j==0||(i%(j%i)==0&&(j%i)!=1))){
                ++count;
                // cout<<count<<i<<j<<endl; 
           } 
           if((i-1)%j==0&&(i-1)!=j&&j<i){
               ++count;
            } 
        }
    }
   }
   
    last_n=n;
    answer[a]=(count+count_start);

} 
for(int i=0;i<t;i++){
    cout<<answer[i]<<"\n";
    // printf("%d \n",answer[i]);
    
}
}