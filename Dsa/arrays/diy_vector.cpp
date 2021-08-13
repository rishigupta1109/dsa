#include<bits/stdc++.h>
using namespace std;
template<class datatype>
class Balti{
private:
datatype* Array=new datatype[0];
int original_size=0;
int used_size=0;

public:
Balti(int size){
    original_size=size;
    resize(size);
}
Balti(int size,datatype arr[]){
    resize(size);
    for (int i = 0; i < size; i++)
    {
        Array[i]=arr[i];
    }
    used_size=size;
    
}
void resize(int new_size){
    datatype* x=new datatype[new_size];
    for (int i = 0; i < original_size; i++)
    {
        x[i]=Array[i];
    }
    Array=x;
    original_size=new_size;
}
void push_back(datatype value){
   if(original_size==used_size){ resize(++original_size);}
    Array[original_size-1]=value;
    ++used_size;
}
datatype at(int index){
    return Array[index];
}
void Print(){
    for (int i = 0; i < used_size; i++)
    {
        cout<<Array[i];
    }
}
void add_at(int index,datatype value){
     if(original_size==used_size){ resize(++original_size);}
    for(int i=original_size-1;i>index;i--){
        datatype temp=Array[i];
        Array[i]=Array[i-1];
        Array[i-1]=temp;
    }
    Array[index]=value;
    ++used_size;
}
void remove_at(int index){
    for(int i=index;i<original_size;i++){
        datatype temp=Array[i+1];
        Array[i+1]=Array[i];
        Array[i]=temp;
    }
    resize(--original_size);
    --used_size;
}
void replace_at(int index,datatype value){
    Array[index]=value;
}
void sort(){
    for (int i = 0; i < used_size; i++)
    {
        for (int j = i+1; j <used_size ; j++)
        {
            if(Array[j]<Array[i]){
                datatype temp=Array[j];
                Array[j]=Array[i];
                Array[i]=temp;
            }
        }
        
    }
}
int linear_search(datatype key){
    int found=-1;
    for (int i = 0; i < used_size; i++)
    {
        if(Array[i]==key){
           return i;
        }
    }
    return found;
    
}
int binary_search(datatype key){
    int found=-1;
    int s=0,e=used_size-1;
    sort();
    if(Array[s]==key){
        found =s;
    }
    else if(Array[e]==key){
         found=e;
    }
    else{
        for(int i=0;i<e;i++){
            int mid=(s+e)/2;
            if(Array[mid]<key){
                i=mid+1;
            }
            else if(Array[mid]==key){
                found= mid;
            }
            else{
                e=mid-1;
            }

        }
    }
    return found;
}
};
int main(){
    int array[5]={1,2,3,4,7};
 Balti<int> arr(5,array);
//  arr.push_back(7);
//  arr.add_at(2,7);
//  arr.remove_at(4);
 arr.Print();
//  cout<<endl;
//  cout<<arr.linear_search(5);
 cout<<arr.binary_search(7);
}