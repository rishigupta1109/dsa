#include<bits/stdc++.h>
using namespace std;
void solve(string input,string output=""){
   if(input.size()==0){
       cout<<output<<" ";
       return;
   }
   unsigned long long int flag=output.find(input[0]);
   string tempop=output+input[0];
   input.erase(0,1);
    solve(input,tempop);
   if(flag>output.size()){
        solve(input,output); 
   }
    //  solve(input,output); for non-unique subsets use this only 
  
}
int main(){
string s="aab";
solve(s); 
}