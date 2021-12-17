//Permutation of spaces means permutatng spaces betweeen letters
// Eg. I: abc
//     O: 
//     a b c
//     a bc
//     ab c
//     abc


#include<bits/stdc++.h>
using namespace std;
void solve(string input,string output=""){
     if(input.size()==0){
       cout<<output<<" ";
       return;
    }
   string temp(1,input[0]);
    input.erase(0,1);
    if(output.size()==0){
        solve(input,temp);
        return;
    }
    string op1=output+" "+temp,op2=output+temp;
    solve(input,op1);
    solve(input,op2);

}
int main(){
 string s;
 cin>>s;
 solve(s);
}