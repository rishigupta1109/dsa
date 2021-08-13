#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
vector <int> answer;
vector<int> inputs;
while(t--){
    int n;
    cin>>n;
    inputs.push_back(n);
}

for(int i=0;i<inputs.size();i++){
    long int n=inputs[i];
    long int count=0;
    count=n-1;
    for(long int a=2;a<=n;a++){
        for(long int b=1;b<=n;b++){
            long int c=a%b;
            if(a==b||c==0){
               
            }
            else{
                if(b%c==0)
               {  ++count;}
            }
        }
    }
    answer.push_back(count);
} 
for(int i=0;i<answer.size();i++){
    cout<<answer[i]<<endl;
}
}