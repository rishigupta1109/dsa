#include<iostream>
using namespace std;
string Reverser(string s){
for(int i=0;i<(s.length()-1)/2;i++){
    int temp=s[i];
    s[i]=s[(s.length()-1)-i];
    s[(s.length()-1)-i]=temp;
}
return s;
}
int main(){
 
 string s;
 cin>>s;
 s=Reverser(s);
 cout<<s;

}