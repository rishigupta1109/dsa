//Permutation of letter cases
// Eg. I: abc
//     O: abc Abc aBc abC ABc aBC AbC ABC

#include<bits/stdc++.h>
using namespace std;
void solve(string input,string output=""){
     if(input.size()==0){
       cout<<output<<" ";
       return;
    }
   string temp1(1,toupper( input[0]));
   string temp2(1,tolower( input[0]));
    int a=int(input[0])-'0';
    input.erase(0,1);
    string op1=output+temp1,op2=output+temp2;
    if(a>=0&&a<=9){
        solve(input,op1);
        return;
    }
    
    solve(input,op1);
    solve(input,op2);

}
int main(){
 string s;
 cin>>s;
 solve(s);
}