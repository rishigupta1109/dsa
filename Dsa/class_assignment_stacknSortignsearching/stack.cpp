#include<iostream>
using namespace std;
class Stack{
    int *stack;
    int size;
    int top;
    public:
    Stack(int s){
        size=s;
        top=-1;
        stack=new int[s];
    }
    void push(int element){
        if(top==size-1){
            return;
        }
        stack[++top]=element;
    }
    int pop(){
        if(top!=-1){
            return stack[top--];
        }
        return INT_MIN;
    }
    // void displayElements(){
    //     if(top==-1){
    //         return;
    //     }
    //     int x=pop();
    //     displayElements();
    //     cout<<x<<" ";
    //     push(x);
    // }
    void displayElements(){
        if(top==-1){
            return;
        }
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    
};
int main(){
    Stack S(5);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.displayElements();
    S.pop();
    S.displayElements();
}