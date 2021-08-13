#include<bits/stdc++.h>
using namespace std;
int main(){
long int t;
cin>>t;
vector <int> answer;
while(t--){
    long int n;
    cin>>n;
    int count=2*n-3;     
      
    for(int i=4;i<=n;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                ++count;
                
            }
            if(i%j==2&&j%2==0){
                 ++count;
            }
            if(i%j==3&&j%3==0){
                   ++count;
            }
        }
    }
   
   
    for(int i=5;i<=n;i++){
        for(int j=2;j<i;j++){
            if((i-1)%j==0&&(i-1)!=j){
               ++count;
            }
        }
    }
    answer.push_back(count);

} 
for(int i=0;i<answer.size();i++){
    cout<<answer[i]<<endl;
}
}