#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int* data;
    node* left;
    node* right;   
    node(int val){
        data=new int(val);
        left=NULL;
        right=NULL;
    }
};
void preorder(node* root){
    if(root!=NULL){
        cout<<*(root->data)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<*(root->data)<<" ";
    }
}
void Inorder(node* root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<*(root->data)<<" ";
        Inorder(root->right);
    }
}
int search(node* root,int key){
    if(root==NULL){
        return 0;
    }
    else{
        cout<<*(root->data)<<endl;
        if(*(root->data)==key){
            return 1;
        }
        else if(*(root->data)>key){
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        }
    }
}
void insert(node* &root,int element){
    node* child=new node(element);
    if(root==NULL){
        root=child;
        return;
    }
    if(*root->data>element&&root->left==NULL){
        root->left=child;
          return;
    }
    else if(*root->data<element&&root->right==NULL){
        root->right=child;
          return;
    }
    if(*(root->data)>element){
        insert(root->left,element);
    }
    else if(*root->data==element){
        return;
    }
    else{
        insert(root->right,element);
    }
}
node* InOrderPreceddor(node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
node* InorderSuccessor(node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

node* deletion(node* &root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL){
        delete root;
        return NULL;
    }
     if(*root->data>key){
          deletion(root->left,key);
        }
        else if(*root->data<key){
           deletion(root->right,key);
        } 
    else{
        node* pre=InOrderPreceddor(root->left);
        if(pre==NULL){
            pre=InorderSuccessor(root->right);
         *(root->data)=*(pre->data);
            root->right= deletion(root->right,*(pre->data));
        }
        else{
         *(root->data)=*(pre->data);
            root->left= deletion(root->left,*(pre->data));
        }
       
    }
    return root;
}
node* helper(node* n){
    if(n->right&&n->left){
        node* temp=n->left;
        while(temp->right!=NULL) temp=temp->right;
        temp->right=n->right;
        temp= n->left;
        delete n;
        return temp;
    }
    else{
        node* temp;
        if(n->right) {temp=n->right; delete n; return temp;}
        if(n->left) {temp=n->left;delete n; return temp;}
    }
        return NULL;

}
void deleteEasy(node* &root,int key){
   node* target=root;
   if(*root->data==key){
       root=helper(root);
       return;
   }
   while(target!=NULL){
      
       if(*target->data>key){
           if(target->left&&*target->left->data==key){
               target->left=helper(target->left);
               return;
           }
           target=target->left;
       }
       else {
           if(target->right&&*target->right->data==key){
               target->right=helper(target->right);
               return;
           }
           target=target->right;
       }
      
   }
}
 //Using static variable in recursive function makes it non reusable;
int count_nodes(node* root){
    static int count =0;
    if(root==NULL){
        return 0;
    }
    count++;
    count_nodes(root->left);
    count_nodes(root->right);
    return count;
}
int count_nodes_without_staticvar(node* root){
    if(root==NULL){
        return 0;
    }
    return count_nodes_without_staticvar(root->left)+count_nodes_without_staticvar(root->right)+1;
}
int sumofnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return *root->data+sumofnodes(root->left)+sumofnodes(root->right);
}
//height calculation O(N)
int height(node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
//For diammeter 2 Cases are there 1.when particular node is part of diameter(leftheight+rightheight+1) 2.when not part of diameter(max(left childs diameter,right childs diameter))
//diameter calculation O(N^2)
// int diameter(node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int heightDiameter=height(root->left)+height(root->right)+1;
//     int lDiametr=diameter(root->left);
//     int rDiameter=diameter(root->right);
//     return max(heightDiameter,max(lDiametr,rDiameter));
// }
//optimised way of finding diameterin O(N)
int diameter(node* root,int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldiameter=diameter(root->left,&lh);
    int rdiameter=diameter(root->right,&rh);
    int heightdiameter=lh+rh+1;
    *height=max(lh,rh)+1;

    return max(heightdiameter,max(ldiameter,rdiameter));
}
//function to make a node sum of itself, its left and right sub trees
void sum_replacement(node* root){
    if(root==NULL){
        return;
    }
    sum_replacement(root->left);
    sum_replacement(root->right);
    if(root->right!=NULL&&root->left!=NULL){
        *root->data+=*root->left->data+*root->right->data;
    }
    else if(root->right!=NULL){
           *root->data+=*root->right->data;
    }
    else if(root->left!=NULL){
          *root->data+=*root->left->data;
    }
             
}
node* ceil(node* root,int key){
    if(!root) return root;
    node* ceil=root;
    if(*root->data!=key){
        while(root!=NULL&&*root->data!=key){
            if(*root->data>key){
                if(*root->data>key)
                ceil=root;
                root=root->left;
            }
            else{
                if(*root->data>key)
                ceil=root;
                root=root->right;
            }
        }
    }
    return root?root:ceil;
}
node* floor(node* root,int key){
    if(!root) return root;
    node* floor=root;
    if(*root->data!=key){
        while(root!=NULL&&*root->data!=key){
            if(*root->data>key){
                if(*root->data<key)
                floor=root;
                root=root->left;
            }
            else{
                if(*root->data<key)
                floor=root;
                root=root->right;
            }
        }
    }
    return root?root:floor;
}

int kthSmallestwayOne(node* root,int k){
    if(!root) return INT_MIN;
    vector<int> Inorder;
    stack<node*> s;
    s.push(root);
    node* temp=root->left;
    while(!s.empty()){
        if(temp) s.push(temp);
        else{
            temp=s.top();
            s.pop();
            Inorder.push_back(*temp->data);
            temp=temp->right;
            if(temp) s.push(temp);
        }
        if(temp) temp=temp->left;
    }
    return Inorder[k-1];

}
int kthSmallestwayTwo(node* root,int k){
     if(!root) return INT_MIN;
    int x=0;
    stack<node*> s;
    s.push(root);
    node* temp=root->left;
    while(!s.empty()){
        if(temp) s.push(temp);
        else{
            temp=s.top();
            s.pop();
            x++;
            if(x==k)
            return *temp->data;
            temp=temp->right;
            if(temp) s.push(temp);
        }
        if(temp) temp=temp->left;
    }
   return INT_MIN;
}
bool isBST(node* root,int lb=INT_MIN,int ub=INT_MAX){
    if(root==NULL) return true;
    if(isBST(root->left,lb,*root->data)&&isBST(root->right,*root->data,ub)){
        return *root->data>lb&&*root->data<ub;
    }
    return  false;
}
node* LCA(node* root,int x,int y){
    while(root){
        if(*root->data>x&&*root->data>y){
            root=root->left;
        }
        else if(*root->data<x&&*root->data<y){
            root=root->right;
        }
        else{
            return root;
        }
    }
    return root;
}
int posnFinder(vector<int> In,int x,int s,int e){
    for(int i=s;i<=e;i++){
        if(In[i]==x){
            return i;
        }
    }
    return -1;
}
node* build(vector<int> Pre,vector<int> In,int s,int e){
    if(s>e)return NULL;
    static int idx=0;
    node* child=new node(Pre[idx]);
    int posn=posnFinder(In,Pre[idx],s,e);
    idx++;
    child->left=build(Pre,In,s,posn-1);
    child->right=build(Pre,In,posn+1,e);
    return child;
}
node* BSTfromPre(vector<int> Pre){
    vector<int> In(Pre);
    sort(In.begin(),In.end());
    return build(Pre,In,0,Pre.size()-1);
}
node* buildTwo(vector<int>Pre ,int &idx,int max=INT_MAX){
    if(Pre.size()<=idx||Pre[idx]>=max){
        return NULL;
    }
    node* child=new node(Pre[idx]);
    idx++;
    child->left=buildTwo(Pre,idx,*child->data);
    child->right=buildTwo(Pre,idx,max);
    return child;
}
node* BSTfromPreWaytwo(vector<int> Pre){
    int idx=0;
    return buildTwo(Pre,idx);
}
int InorderSuccesor(node* root,int key){
    vector<int> In;
    stack<node*> s;
    s.push(root);
    node* curr=root->left;
    while(!s.empty()){
        if(curr){
            s.push(curr);
        }
        else{
            curr=s.top();
            s.pop();
            In.push_back(*curr->data);
            curr=curr->right;
            if(curr)s.push(curr);
        }
        if(curr)curr=curr->left;
    }
    int posn=-1;
    for(int i=0;i<In.size();i++){
        if(In[i]==key){
            posn=i+1;
        }
    }
    return posn<In.size()?In[posn]:INT_MAX;
    
}
int InorderSuccessorMorrisTraversal(node* root,int key){
    node* curr=root;
   
    while(curr){
        if(curr->left){
            node* prev=curr->left;
            while(prev->right!=NULL&&prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right){
                if(*curr->data>key){return *curr->data;}
                prev->right=NULL;
                curr=curr->right;
            }
            else{
                prev->right=curr;
                curr=curr->left;
            }
        }
        else{
           
            if(*curr->data>key){return *curr->data;}
            curr=curr->right;
        }
    }
    return INT_MAX;
}
//To find Succesor Inorder in O(H) which is possible only in BST
int InorderSuccesorinBST(node* root,int key){
    int value=INT_MAX;
    while(root!=NULL){
        if(*root->data>key&&*root->data<value){
            value=*root->data;
        }
        if(*root->data<=key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return value;
}
class SuccessiveIterator{
    public:
    stack<node*> s;
    SuccessiveIterator(node* root){
        pushAll(root);
    }
    int next(){
        node* n=s.top();
        s.pop();
        pushAll(n->right);
        return *n->data;
    }
    bool hasNext(){
        return !s.empty();
    }
    private:
    void pushAll(node* root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }

};
class PredecessiveIterator{
    public:
    stack<node*> s;
    PredecessiveIterator(node* root){
        pushAll(root);
    }
    int next(){
        node* n=s.top();
        s.pop();
        pushAll(n->left);
        return *n->data;
    }
    bool hasNext(){
        return !s.empty();
    }
    private:
    void pushAll(node* root){
        while(root!=NULL){
            s.push(root);
            root=root->right;
        }
    }

};
bool sumOfTwoExist(node* root,int key){
    SuccessiveIterator s(root);
    PredecessiveIterator p(root);
    int i=s.next();
    int j=p.next();
    while(i<j){
        if(i+j==key)return true;
        else if(i+j<key) i=s.next();
        else j=p.next();
    }
    return false;
}
int main(){
    node* n=NULL;
    insert(n,10);
    insert(n,5);
    insert(n,25);
    insert(n,35);
    insert(n,1);
    insert(n,15);
    insert(n,16);
    // cout<<kthSmallestwayTwo(n,4);
    // cout<<kthSmallestwayOne(n,4);
    // Inorder(n);
    // deleteEasy(n,10);
    // // sum_replacement(n);
    // cout<<endl;
    // Inorder(n);
    // cout<<sumofnodes(n);
    // int height=0;
    // cout<<diameter(n,&height);
    // cout<<count_nodes_without_staticvar(n);
    // cout<<*floor(n,32)->data;
    // cout<<isBST(n);
    // cout<<*LCA(n,1,5)->data;
    // vector<int> Pre={3,2,1,5,4,6};
    // node* root=BSTfromPreWaytwo(Pre);
    // node* root=BSTfromPre(Pre);
    // Inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<InorderSuccessorMorrisTraversal(n,1);
    // cout<<InorderSuccesorinBST(n,35);
    // PredecessiveIterator *s=new PredecessiveIterator(n);
    // cout<<s->next()<<" ";
    // cout<<s->next()<<" ";
    // cout<<s->next()<<" ";
    // cout<<s->hasNext()<<" ";
    // cout<<s->next()<<" ";
    // cout<<s->next()<<" ";
    // cout<<s->next()<<" ";
    // cout<<s->next()<<" ";
    // cout<<s->hasNext()<<" ";
    cout<<sumOfTwoExist(n,49);
}