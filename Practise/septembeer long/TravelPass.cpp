#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int N,A,B;
    string s;
    cin>>N>>A>>B;
    cin>>s;
    unordered_map<int,int> m;
    for(int i=0;i<N;i++){
        
        m[(int)s[i]]++;
    }
  
    int answer=(A*m[48])+(B*m[49]);
    cout<<answer<<endl;

} 
}