#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    map<unsigned long long int,int> m;
    for(int i=0;i<n;i++){
        unsigned long long int element;
        cin>>element;
        if(m[element]){
            m.erase(element);
        }
        else{
            m[element]++;
        }
    }
    unsigned long long int max=m.begin()->first;
    for(auto n:m){
        if(n.first>max){
            max=n.first;
        }
    }
    int x=0;
    int answer=-1;
    int l=m.begin()->first;
    if(m.size()==1&&l!=0){
        cout<<-1<<endl;
    }
    else{
  
    while(pow(2,x)<max) x++;
     for( unsigned long long int i=0;i<=10*x;i++){
        unsigned long long int a=0;
       for(auto n:m){
            a^=(n.first+i);
       }
        if(a==0){
            answer=i;
            break;
        }   
    }
    cout<<answer<<endl;
          
    }
} 
}