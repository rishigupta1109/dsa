#include<bits/stdc++.h>
using namespace std;
class stackArray{
public:
int top;
int size;
int *arr;
stackArray(int s){
    size=s;
    arr=new int[size];
    top=-1;
}
bool push(int value){
    if(top<size){
        arr[++top]=value;
        return true;
    }
    else{
        return false;
    }
}
char pop(){
        return arr[top--];   
}
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
};
int main(){
    string s;
    getline(cin,s);
    stackArray sa(s.length());
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            sa.push(s[i]);
        }
        else if(s[i]==')'){
            if(sa.isEmpty()||sa.pop()!='('){
                sa.push(-1);
                break;
            }
        }
        else if(s[i]=='['){
             sa.push(s[i]);
        }
        else if(s[i]==']'){
            if(sa.isEmpty()||sa.pop()!='['){
                sa.push(-1);
                break;
            }
        }
          else if(s[i]=='{'){
             sa.push(s[i]);
        }
         else if(s[i]=='}'){
            if(sa.isEmpty()||sa.pop()!='{'){
                sa.push(-1);
                break;
            }
        }

    }
    if(sa.isEmpty()){
        cout<<"paranthesises are placed right";
    }
    else{
        cout<<"paranthesises are not placed right";
    }
   
 
}