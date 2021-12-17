//Demonstration of queue in stl
#include<iostream>
#include<queue>
using namespace std;
void displayQueue(queue<int> q){
    cout<<"Elements in Queue : ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> Queue;
    Queue.push(1);
    Queue.push(7);
    Queue.push(3);
    Queue.push(5);
    Queue.push(9);
    
    cout<<"Size of Queue is : "<<Queue.size()<<endl;

    displayQueue(Queue);

    cout<<"element at front : "<<Queue.front()<<endl;
    cout<<"element at back  : "<<Queue.back()<<endl;

    Queue.pop();
    cout<<"Element is popped"<<endl;
    displayQueue(Queue);
    Queue.pop();
    cout<<"Element is popped"<<endl;
    displayQueue(Queue);
    Queue.pop();
    cout<<"Element is popped"<<endl;
    displayQueue(Queue);
    Queue.pop();
    cout<<"Element is popped"<<endl;
    displayQueue(Queue);
    Queue.pop();
    cout<<"Element is popped"<<endl;
    displayQueue(Queue);

    if(Queue.empty()==true){
        cout<<"Queue is empty";
    }
    else{
        cout<<"Queue is not empty";
    }



}