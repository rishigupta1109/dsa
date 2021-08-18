#include<bits/stdc++.h>
using namespace std;

class Q{
public:
int* Queue;
int rear;
int front;
int size;
Q(int s){
    size=s;
    rear=-1;
    front=-1;
    Queue=new int [size];
}
void enqueue(int value){
    
    if(rear==size-1){
    if((rear+1)%size<front){
        rear=(rear+1)%size;
        Queue[rear]=value;
    }
    }
    else{
        if(rear+1!=front){
            Queue[++rear]=value;
        }
    }  
    if(front==-1){
        ++front;
    }
}
void dequeue(){
    if(front==rear){
        front=rear=-1;
    }
    else{
        if(front==size-1){
            front=0;
        }
    else{
            ++front;
        }
    }
    
    
}
bool isEmpty(){
    return rear==-1;
}
void print(){
   if(rear!=-1){ int i=front-1;
    do{
        i=(i+1)%size;
        cout<<Queue[i]<<" ";
    }while(i!=rear);}
}
};

int main(){
 Q* line=new Q(5);
 line->enqueue(5);
 line->enqueue(4);
 line->enqueue(3);
 line->enqueue(2);
 line->enqueue(1);
 line->print();
 cout<<endl;
 line->dequeue();
 line->dequeue();
 line->dequeue();
 line->dequeue();
//  cout<<line->front<<line->rear;
 line->dequeue();
//  cout<<line->front<<line->rear;
 line->print();
 cout<<endl;
 line->enqueue(5);
 line->enqueue(4);
 line->enqueue(3);
 line->print();
 cout<<endl;
}