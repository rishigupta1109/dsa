#include<bits/stdc++.h>
using namespace std;
typedef struct node* NODE;
struct node{
    int data;
    NODE left;
    NODE right;
    node(int value){
        data=value;
    }
};
class BT{
    public:
    NODE Root;
    BT(){Root=NULL;}
    int posnFinder(int A[],int key,int s,int e){
        for(int i=s;i<=e;i++){
            if(A[i]==key){
                return i;
            }
        }
        return -1;
    }
    NODE PreNInORderInsert(int Pre[],int In[],int s,int e){
        static int idx=0;
        if(s>e){
            return NULL;
        }
        NODE child =new node(Pre[idx]);
        
        if(Root==NULL){
            Root=child;
        }
       
        int pos=posnFinder(In,Pre[idx],s,e);
        idx++;
        child->left=PreNInORderInsert(Pre,In,s,pos-1);
        
        child->right=PreNInORderInsert(Pre,In,pos+1,e);

        return child;
    }
    NODE PostNInORderInsert(int Post[],int In[],int s,int e){
        static int idx=e;
        if(s>e){
            return NULL;
        }
      
        NODE child =new node(Post[idx]);
        
        if(Root==NULL){
            Root=child;
        }
       
        int pos=posnFinder(In,Post[idx],s,e);
        idx--;
        child->right=PostNInORderInsert(Post,In,pos+1,e);
        child->left=PostNInORderInsert(Post,In,s,pos-1);
        

        return child;
    }
    

};
void preorder(node* root){
    if(root!=NULL){
        cout<<(root->data)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<(root->data)<<" ";
    }
}
void Inorder(node* root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<(root->data)<<" ";
        Inorder(root->right);
    }
}
void levelorder(node* root){
    if(root==NULL){
        return;
    }
    queue<struct node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node* temp=Q.front();
        Q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                Q.push(temp->left);
            }
           
            if(temp->right!=NULL){
                Q.push(temp->right);
            }
        }
        else if(!Q.empty()){
            Q.push(NULL);
        }
    }
}
int sumofkthlevel(node* root,int l){
     if(root==NULL){
        return -1;
    }
    queue<struct node*> Q;
    Q.push(root);
    Q.push(NULL);
    int sum=0;
    int level=0;
    while(!Q.empty()){
        node* temp=Q.front();
        Q.pop();
        if(temp!=NULL){
            if(level==l)
            sum+=temp->data;
            if(temp->left!=NULL){
                Q.push(temp->left);
            }
           
            if(temp->right!=NULL){
                Q.push(temp->right);
            }
        }
        else if(!Q.empty()){
            if(level==l){
                return sum;
            }
            sum=0;
            level++;
            Q.push(NULL);
        }
        else{
            if(level==l){
                return sum;
            }
        }
    }
    return -1;
}
int main(){
    BT* tree=new BT();
    int pre[7]={1,2,4,5,3,6,7};
    int In[7]={4,2,5,1,6,3,7};
   
    tree->PreNInORderInsert(pre,In,0,6);

    // levelorder(tree->Root);
    cout<<sumofkthlevel(tree->Root,2);

   
}