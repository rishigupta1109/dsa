#include<bits/stdc++.h>
using namespace std;
void solve(int a,int b,int c,int m,string &s,string op){
    if(a==0&&b==0&&c==0){
        if(m==0)
        {s="YES";
        }
        return;
    }
    if(s=="YES"){
        return;
    }
  
    string op1=op+"A";
    string op2=op+"B";
    string op3=op+"C";
    
    
    if(a==0){
        if(b!=0)
        {   if(op[(op.size()-1)]=='B'){
            solve(a,b-1,c,m-1,s,op2);
        }
        else{
             solve(a,b-1,c,m,s,op2);
        }
        }
        if(c!=0)
        {
            if(op[(op.size()-1)]=='C'){
            solve(a,b,c-1,m-1,s,op3);
        }
        else{
            solve(a,b,c-1,m,s,op3);}}
    }
    else if(b==0){
        if(a!=0)
        {solve(a-1,b,c,m,s,op1);}
       if(c!=0)
        {
            if(op[(op.size()-1)]=='C'){
            solve(a,b,c-1,m-1,s,op3);
        }
        else{
            solve(a,b,c-1,m,s,op3);}}
    }
    else if(c==0){
        if(a!=0)
        {if(op[(op.size()-1)]=='A'){
             solve(a-1,b,c,m-1,s,op1);
        }
           else{
                solve(a-1,b,c,m,s,op1); 
           } }
        if(b!=0)
        {   if(op[(op.size()-1)]=='B'){
            solve(a,b-1,c,m-1,s,op2);
        }
        else{
             solve(a,b-1,c,m,s,op2);
        }
        }
    }
    else{if(op[(op.size()-1)]=='A'){
             solve(a-1,b,c,m-1,s,op1);
        }
           else{
                solve(a-1,b,c,m,s,op1); 
           } 
             if(op[(op.size()-1)]=='B'){
            solve(a,b-1,c,m-1,s,op2);
        }
        else{
             solve(a,b-1,c,m,s,op2);
        }
        if(op[(op.size()-1)]=='C'){
            solve(a,b,c-1,m-1,s,op3);
        }
        else{
            solve(a,b,c-1,m,s,op3);}

    }
    
}
int main(){
int t;
cin>>t;
while(t--){
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    string s="NO";
    solve(a,b,c,m,s,"");
    cout<<s<<endl;
} 
}