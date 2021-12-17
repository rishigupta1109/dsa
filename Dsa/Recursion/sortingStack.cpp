#include<iostream>
using namespace std;
class stack{
    private:
        int* array;
        int size;
        int top;
    public:
        stack(int s){
            size=s;
            array=new int[s];
            top=-1;
        }
        void push(int a){
            if(top!=(size-1))
            array[++top]=a;
        }
        int pop(){
            return array[top--];
        }
        int getTop(){
            return array[top];
        }
        bool isEmpty(){
            return (top==-1);
        }
        void print(){
           if(isEmpty()){
               return ;
           }
           int x=pop();
           print();
           cout<<x<<" ";
           push(x);
        }
        void insertRight(int element){
            if(getTop()<element||isEmpty()){
                push(element);
                return;
            }
            int x=pop();
            insertRight(element);
            push(x);
        }
        void sort(){
            if(isEmpty()){
                return;
            }
            int x=pop();
            sort();
            insertRight(x);
        }
        void popAtMid(){
            if(top==(size-1)/2){
                pop();
                return;
            }
            int x=pop();
            popAtMid();
            push(x);
        }
        void insertAtBottom(int element){
            if(isEmpty()){
                push(element);
                return;
            }
            int x=pop();
            insertAtBottom(element);
            push(x);
        }
        void reverse(){
            if(isEmpty()){
                return;
            }
            int x=pop();
            reverse();
            insertAtBottom(x);
        }
};
int main(){
    stack s(6);
    s.push(6);
    s.push(4);
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(3);
    s.sort();
    s.print();
    cout<<endl;
    // s.popAtMid();
    // s.insertAtBottom(3);
    s.reverse();
    s.print();
}