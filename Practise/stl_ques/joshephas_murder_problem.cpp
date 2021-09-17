#include<bits/stdc++.h>
using namespace std;
class node{
  public:
    node* next;
    int data;
    node(int val){
        data=val;
        next=NULL;
    }
};
class circular_list{
  public:
    node* head;
    node* tail;
    int size;
    circular_list(){
        tail=head=NULL;
        size=0;
    }
    void push_back(int val){
        node* child =new node(val);
        if(head==NULL){
            head=child;
            tail=child;
            head->next=child;
            size++;
        }
        else{
            tail->next=child;
            tail=child;
            tail->next=head;
            size++;
        }
    }
    void pop_back(){
        node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=head;
        node* target=tail;
        tail=temp;
        delete target;
        size--;
    }
    void erase(node* &it){
        node* temp=head;
        while(temp->next!=it){
            temp=temp->next;
        }
        temp->next=it->next;
        node* target=it;
        it=temp->next;
        delete target;
    }
};
int main(){
int n,k;
cin>>n>>k;

// list <int> l;
// for(int i=1;i<=n;i++){
//     l.push_back(i);
// }
// auto it=l.begin();
// for(int j=0;j<n-1;j++){
//     for(int i=1;i<k;i++){
//         it++;
//         if(it==l.end()){
//             it=l.begin();
//         }
//     }

//     l.erase(it);
    
// }
// cout<< (*it);
circular_list* cl = new circular_list;
        for(int i=1;i<=n;i++){
            cl->push_back(i);
        }
        node* ptr=cl->head;
        for(int i=1;i<n;i++){
            for(int j=1;j<k;j++){
                ptr=ptr->next;
            }
            cl->erase(ptr);
        }
        cout<< ptr->data;
}