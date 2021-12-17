#include<bits/stdc++.h>
using namespace std;
void swap(string &s,int x,int y){
    char temp=s[x];
    s[x]=s[y];
    s[y]=temp;
}
bool check(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!='0'){
            return true;
        }
    }
    return false;
}
int main(){
int T;
cin>>T;
while(T--){
    int N;
    string s;
    cin>>N>>s;
    int count=0;
    while(check(s)){
        if(s[N-1]!='0'){
            count+=(s[N-1]-'0');
            s[N-1]='0';
        }
        else{
            for(int i=0;i<s.length();i++){
                if(s[i]!='0'){
                    swap(s,i,N-1);
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count<<endl;
} 
}