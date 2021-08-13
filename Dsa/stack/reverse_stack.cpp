#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
int size;
int top;
int* arr;
Stack(int s=100){
    size=s;
    top=-1;
    arr=new int(s);
}
void push (int value){
    arr[++top]=value;
}
int pop(){
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
void print(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
};
void insert_at_bottom(Stack &s,int ele){
    if(s.isEmpty()){
        s.push(ele);
        return;
    }
    int element=s.pop();
    insert_at_bottom(s,ele);
    s.push(element);
}
void reverse(Stack &s){
    if(s.isEmpty()){
        return;
    }
    int element=s.pop();
    reverse(s);
    insert_at_bottom(s,element);

}

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    reverse(s);
    s.print();

 
}