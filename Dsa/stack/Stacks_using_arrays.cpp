#include<iostream>
using namespace std;
class stack{
public:
int* arr;
int size;
int top;
stack(int s){
    size=s;
    arr=new int[size];
    top=-1;
}
bool push(int value){
   if(top!=(size-1)){ 
       arr[++top]=value; 
        return true;
    }
    else{
        return false;
    }
}
bool pop(){
   if(top!=-1){
       top--;
       return true;
   }
   else{
       return false;
   }
}
bool isFull(){
    if(top==(size-1)){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
int peek(int position){
    int index=top-position+1;
    return arr[index];
}
int stackTop(){
        return arr[top];   
}
int stackBottom(){  
        return arr[0];
}
};
int main(){
    stack s(6);
    cout<<s.push(5);
    cout<<s.push(9);
    cout<<s.push(11);
    cout<<s.push(13);
    cout<<s.push(15);
    cout<<s.push(18);
    cout<<s.isEmpty()<<endl;
    // cout<<s.peek(3);
    cout<<s.stackTop();
}