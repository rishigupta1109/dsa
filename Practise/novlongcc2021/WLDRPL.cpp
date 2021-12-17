#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    s=' '+s;
    int Q;
    cin>>Q;
    int L[Q],R[Q];
    for(int i=0;i<Q;i++){
        cin>>L[i];
        cin>>R[i];
    }
    for(int k=0;k<Q;k++){      
        stack<pair<char,char>> brackets;
        stack<char> opt;
        for(int j=L[k];j<=R[k];j++){
            if(s[j]=='('&&opt.empty()){
                brackets.push({'(','+'});
            }
            else if(s[j]=='('){
                brackets.push({'(',opt.top()});
            }
            else if(s[j]==')'){
                brackets.pop();
            }
            else if(s[j]=='?'){}
            else{
                if(brackets.empty()||brackets.top().second=='+'){
                    opt.push(s[j]);
                }else{
                    if(s[j]=='+'){opt.push('-');}
                    else{opt.push('+');}
                }
            }
        }
        int ans=1;
        
            while(!opt.empty()){
                char c=opt.top();
                opt.pop();
                if(c=='+') ans++;
            }
            cout<<ans<<" ";
        

    }
    cout<<endl;

} 
}