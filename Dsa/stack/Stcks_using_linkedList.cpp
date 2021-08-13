#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int value){
    data=value;
    next=NULL;
}
};

class Stack{
    public:
    Node* node;
    Node* top;
    Node* bottom;
    int size;
    int used_size;
    Stack(int s){
        used_size=0;
        size=s;
        top=NULL;
        bottom=NULL;
    }
    bool push(int value){
        if(used_size<size){
            node=new Node(value);
            if(top==NULL){
                bottom=node;
                 top=node;
                 ++used_size;
            }
            else{
                top->next=node;
                top=node;
                 ++used_size;
            }
            return true;
        }
        else{
            return false;
        }
    }
    bool pop(){
        if(used_size==0){
            return false;
        }
        else{
            if(top!=bottom){
                Node* tail=bottom;
                 while(tail->next->next!=NULL){
                tail=tail->next;
                }
                top=tail;
                tail=tail->next;
                top->next=NULL;
                delete tail;
            }
            else{
                top=NULL;
                bottom=NULL;
            }
            return true;

        }

    }
    int peek(int position){
        int index=used_size-position;
        Node* element=bottom;
        while((index)--){
            element=element->next;
        }
        return element->data;
    }
    int stackTop(){
        return top->data;
    }
    int stackBottom(){
        return bottom->data;
    }

    bool isEmpty(){
        return top==NULL;
    } 
    bool isFull(){
        return used_size==size;
        //when size is not defined
        // Node* n=new Node(-1);
        // return n==NULL;
    }
     
};

int main(){
Stack s(6);
cout<<s.push(5);
cout<<s.push(8);
cout<<s.push(9);
cout<<s.push(12);
cout<<s.push(12);
cout<<s.push(12);
cout<<s.push(12);
// cout<<s.isEmpty();

}