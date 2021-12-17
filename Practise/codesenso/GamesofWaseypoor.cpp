#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    int n;
    cin>>n;
    cin>>s;
    char flag=s[0];
    int blocks=1;
    for(int i=0;i<s.length();i++){
        if(flag!=s[i]){
            flag=s[i];
            blocks++;
        }
    }
    int player=1;
    while(blocks!=0){
        if(blocks==2||blocks==1){
            blocks--;
            player++;
        }
        else{
            if((blocks-2)%2==0){
                blocks=blocks-2;
                player++;
            }
            else{
                blocks--;
                player++;
            }
        }
    }
    if(player%2==0){
        cout<<"SHAHID"<<endl;
    }
    else{
        cout<<"RAMADHIR"<<endl;
    }
} 
}