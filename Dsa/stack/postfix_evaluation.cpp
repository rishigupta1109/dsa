#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        int* arr;
        int size;
        int top;
        Stack(int s){
            size=s;
            arr=new int[s];
            top=-1;
        }
        void push(int value){
            arr[++top]=value;
        }
        int pop(){
            return arr[top--];
        }
        void print (){
            for(int i=0;i<=top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        bool isEmpty(){
            if(top==-1){
                return true;

            }
            else return false;
        }
};
int main(){
    string s;
    getline(cin,s);
    Stack sa(s.length());
     for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            int a=sa.pop();
            int b=sa.pop();
            int c=a+b;
            sa.push(c);
        }
        else if(s[i]=='-'){
             int a=sa.pop();
            int b=sa.pop();
            int c=b-a;
            sa.push(c);
        }
        else if(s[i]=='*'){
             int a=sa.pop();
            int b=sa.pop();
            int c=a*b;
            sa.push(c);
        }
        else if(s[i]=='/'){
             int a=sa.pop();
            int b=sa.pop();
            int c=b/a;
            sa.push(c);
        }
        else if(s[i]=='^'){
             int a=sa.pop();
            int b=sa.pop();
            int c=a^b;
            sa.push(c);
        }
        else{
            int x=s[i]-'0';
            sa.push(x);
        }
       sa.print();
    }
    cout<<sa.arr[sa.top];
}