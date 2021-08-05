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

void insert_at_tail(node* &head,int value){
    node* child=new node(value);
    if(head==NULL){
        head=child;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=child;

}
void insert_at_head(node* &head,int val){
    node* child=new node(val);
    if(head==NULL){
        head=child;
        return ;
    }
    child->next=head;
    head=child;
}
void print_linked_list(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void insert (node* &head,int val,int index){
    node* child =new node(val);
    node* temphead=head;
    if(index==0){
        node* temp=head;
    head=child;
    child->next=temp;
    
    }
   else{
       int x=index-1;
        while(x){
        temphead=temphead->next;
        --x;
    }
    node* temp=temphead->next;
    temphead->next=child;
    child->next=temp;} 
}
void delete_element(node* &head,int index){
    
     node* temphead=head;
    if(index==0){
        head=head->next;
        delete temphead;
    }
    else{
        int x=index-1;
       
        while(x){
            temphead=temphead->next;
            --x;
        }
        node* element_to_be_removed=temphead->next;
        temphead->next=element_to_be_removed->next;
        delete element_to_be_removed;
    }

}
void delete_at_tail(node* &head){
    if(head==NULL){
        return ;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return ;
    }
    node* temp=head;
    node* element_tobe_deleted=head;
    while(element_tobe_deleted->next!=NULL){
        temp=element_tobe_deleted;
        element_tobe_deleted=element_tobe_deleted->next;
    }
    temp->next=NULL;
    delete element_tobe_deleted;
}
void delete_by_value(node* &head,int val){
    
    if(head->data==val){
        node*temp=head;
        head=head->next;
        delete temp;
        return ;
    }
    if(head->next==NULL){
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* element_to_be_deleted=temp->next;      //to be deleted
    temp->next=element_to_be_deleted->next;
    delete element_to_be_deleted;
    
}
node* search(node* head,int val){
    if(head->data==val){
        return head;
    }
    while(head->next->data!=val){
        head=head->next;
    }
   
    return head->next;

}
void print_node(node* key){ 
    cout<<key->data;
}
void insert_after_node(node* n,int val){
    node* child =new node(val);
    node* temp=n->next;
    n->next=child;
    child->next=temp; 
}
void reverse(node* &head){
    if(head==NULL){
        return;
    }
    else if(head->next==NULL){
        return ;
    }
   node* previous=NULL;
   node* current=head;
   node* next;
   while(current!=NULL){
       next=current->next;
       current->next=previous;
       previous=current;
       current=next;
   }
   head=previous;
}

void reverse_by_recursion(node* &head,node* previous=NULL){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
    head->next=previous;
    }
    else{
        node* next=head->next;
        head->next=previous;
        previous=head;
        head=next;
        reverse_by_recursion(head,previous);
    }
}

node* recursivereverse_apnacollege(node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* newhead=recursivereverse_apnacollege(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* reverse_k_nodes(node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    node* temp=head;
    
    int i=1;
    while( i!=k){
        temp=temp->next;
        ++i;
    }
    node* next_piece_connection=temp->next;
    node* preveous=head;
    node* current=head->next;
    node* next;
    while(current!=next_piece_connection){
        next=current->next;
        current->next=preveous;
        preveous=current;
        current=next;
    }
    head->next=reverse_k_nodes(next_piece_connection,k);
    head=temp;
    return preveous;
}
void make_cycle(node* head,int k){
    node* cycle_node;
    int i=1;
    while(head->next!=NULL){
        if(i==k){
            cycle_node=head;
        }
        head=head->next;
        ++i;
    }
    head->next=cycle_node;
}
bool detect_cycle(node* head){
    node* fastptr=head;
    node* slowptr=head;
    
    while(true){
       if(slowptr->next==NULL||fastptr->next->next==NULL){
            break;
        }
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr){
            return true;
        }
         

    }
    return false;
}
void remove_cycle(node* head){
    node* fastptr=head;
    node* slowptr=head;
    node* meetupptr;
    while(true){
       
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr){
            meetupptr=slowptr;
            break;
        }
    }
    slowptr=head;
    node* chainlink;
    while(true){
        if(slowptr==fastptr){
            break;
        }
        chainlink=fastptr;
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }
    chainlink->next=NULL;
}
int length(node* head){
    int length=1;
    if(head==NULL){
        return 0;
    }
    while(head->next!=NULL){
        length++;
        head=head->next;
    }
    return length;
}
void append_k_nodes(node* &head,int k){
    int i=1;
    int l=length(head);
    int new_tail_pos=l-k;
    node* new_tail=head;
    node* jointptr=head;
    while(jointptr->next!=NULL){
        if(i==new_tail_pos){new_tail=jointptr;}
        jointptr=jointptr->next;
        i++;
    }
    node* new_head=new_tail->next;
    jointptr->next=head;
    new_tail->next=NULL;
    head=new_head;
}
void join_2_lists(node* head1,node* head2,int index){
    while(head2->next!=NULL){
        head2=head2->next;
    }
    int k=0;
    while(k!=index){
        head1=head1->next;
        k++;
    }
    head2->next=head1;
}
bool hasIntersection(node* head1,node* head2){
    int length1=length(head1);
    int length2=length(head2);
    if(length1<length2){
        node* tempptr=head1;
        head1=head2;
        head2=tempptr;
        int temp=length1;
        length1=length2;
        length2=temp;
    }
    int start=length1-length2;
    int i=0;
    while(i!=start){
        head1=head1->next;
        i++;
    }
    while(head2->next!=NULL){
        if(head1==head2){
            return true;
        }
        head1=head1->next;
        head2=head2->next;
    }

    return false;

}
void merge_sorted_lists(node* &head1,node* &head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummy=new node(-1);
    node* ptr3=dummy;
    while(true){
        if(ptr1==NULL&&ptr2==NULL){
            break;
        }
        else if(ptr1==NULL&&ptr2!=NULL){
            ptr3->next=ptr2;
             ptr3=ptr3->next;
            ptr2=ptr2->next;
        }
        else if(ptr2==NULL&&ptr1!=NULL){
          ptr3->next=ptr1;
            ptr3=ptr3->next;
            ptr1=ptr1->next;
        }
        else{
            if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr3=ptr3->next;
            ptr1=ptr1->next;
            }
            else{
            ptr3->next=ptr2;
            ptr3=ptr3->next;
            ptr2=ptr2->next;
            }
        }  
    }
    head1=dummy->next;
    head2=dummy->next;
}
int main(){
 node* head=NULL;
 insert_at_tail(head,1);
 insert_at_tail(head,3);
 insert_at_tail(head,5);
 insert_at_tail(head,7);
// insert_at_head(head,22);
// insert_at_head(head,26);

node* head2=NULL;
 insert_at_tail(head2,2);
 insert_at_tail(head2,4);
 insert_at_tail(head2,6);
// insert_at_head(head2,37);
// insert_at_head(head2,29);

// print_linked_list(head2);
// join_2_lists(head,head2,2);
merge_sorted_lists(head,head2);
print_linked_list(head);
print_linked_list(head2);
// cout<<hasIntersection(head,head2);


// print_linked_list(head);
// node* key=search(head,6);
// insert_after_node(key,21);
// print_linked_list(head);
// reverse(head);
// reverse_by_recursion(head);
// head=recursivereverse_apnacollege(head);
// reverse_k_nodes(head,6);
// make_cycle(head,3);
// cout<<detect_cycle(head)<<endl;
// remove_cycle(head);
// cout<<detect_cycle(head)<<endl;

// print_linked_list(head);
// cout<<length(head)<<endl;
// append_k_nodes(head,4);
// print_linked_list(head);


// delete_at_tail(head);
// print_linked_list(head);
// cout<<endl;
// insert(head,10,0);
// print_linked_list(head);
// // delete_element(head,2);
// // delete_at_tail(head);
// delete_by_value(head,10);
// delete_by_value(head,1);
// delete_by_value(head,18);
// cout<<endl;
// print_linked_list(head);
// print_node(search(head,14));
}

