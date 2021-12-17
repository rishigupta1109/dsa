#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    vector<int> z,o;
    int size=1;
    char flag=s[0];
    s=s+(s[s.length()-1]=='0'?'1':'0');
    for(int i=1;i<s.length();i++){
        if(s[i]==flag){
            size++;
        }
        else{
            if(flag=='0') z.push_back(size);
            else o.push_back(size);
            flag=s[i];
            size=1;
        }
    }
    int operationOnO=0;
    int operationOnz=0;
    for(auto x:o){
        if(x==1){
            operationOnO++;
        }
        else{
            operationOnO+=2;
        }
    }
    
    for(auto x:z){
        if(x==1){
            operationOnz++;
        }
        else{
            operationOnz+=2;
        }
    }
    cout<<(operationOnO>operationOnz?operationOnz:operationOnO)<<endl;

} 
}