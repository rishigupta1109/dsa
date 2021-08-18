#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node* next;
node(int value){
    data=value;
    next=NULL;
}
};

class Q{
public:
node* front;
node* rear;
Q(){
    front=rear=NULL;
}
void enqueue(int value){
    node* child=new node(value);
    if(rear==NULL){
        rear=front=child;
    }
    else{
        rear->next=child;
        rear=child;
    }
}
void dequeue(){
    if(front!=NULL){
        node* target=front;
        if(front==rear){
            front=rear=NULL;
        }
        else{
            front=front->next;
        }
        delete target;
    }
}
bool isEmpty(){
    return front==NULL?true:false;
}
void print(){
    node* surfer=front;
    while(surfer!=NULL){
        cout<<surfer->data<<" ";
        surfer=surfer->next;
    }
}

};
int main(){
    Q* line=new Q;
    cout<<line->isEmpty();
    line->enqueue(1);
    line->enqueue(2);
    line->enqueue(3);
    line->enqueue(4);
    line->enqueue(5);
   
    line->print();

    line->dequeue();
    line->dequeue();

    line->print();

}