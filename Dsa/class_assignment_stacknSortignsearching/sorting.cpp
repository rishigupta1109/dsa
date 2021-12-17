#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printByRecursion(int arr[],int n,int s=0){
    if(s==n){
        return;
    }
    cout<<arr[s]<<" ";
    printByRecursion(arr,n,s+1);
}
void BubbleSort(int arr[],int n){
    for(int i=1;i<n;i++){
        bool swapped =false;
        for(int j=1;j<=n-i;j++){
            if(arr[j]<arr[j-1]){
                swapped=true;
                swap(arr,j,j-1);
            }
        }
        if(!swapped){
            break;
        }
    }
}

void Swapper(int arr[],int n,int s=1){
    if(s==n){
        return;
    }
    if(arr[s-1]>arr[s]) swap(arr,s-1,s);
    Swapper(arr,n,s+1);
}
void BubbleSortByRecursion(int arr[],int n,int s=1){
    if(s==n){
        return;
    }
    Swapper(arr,n);
    BubbleSortByRecursion(arr,n,s+1);
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i;
        while(arr[j-1]>temp&&j!=0){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

void insertAtrightposn(int arr[],int n,int e){
   int temp=e;
    if(n==0||arr[n-1]<=temp){
        arr[n]=temp;
        return;
    }
    if(arr[n-1]>temp){
        arr[n]=arr[n-1];
    }
    insertAtrightposn(arr,n-1,e);
}
void insertionSortByRecursion(int arr[],int n,int s=1){
    if(s==n){
        return;
    }
    insertAtrightposn(arr,s,arr[s]);
    insertionSortByRecursion(arr,n,s+1);
}
void selectionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int maxindex=0;
        for(int j=1;j<=n-i;j++){
            if(arr[j]>arr[maxindex]){
                maxindex=j;
            }
        }
        swap(arr,maxindex,n-i);
    }
}
int maxfinder(int arr[],int n,int maxindex=0){
    if(n==0){
        return maxindex;
    }
    if(arr[n]>arr[maxindex]){
        maxindex=n;
    }
    return maxfinder(arr,n-1,maxindex);
}
void selectionsortbyRecursion(int arr[],int n){
    if(n==1){
        return;
    }
    int mi=maxfinder(arr,n-1);
    swap(arr,n-1,mi);
    selectionsortbyRecursion(arr,n-1);

}
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int i=s;
    int j=e;
    while(i<j){
        while(i!=e&&arr[i]<=pivot){
            i++;
        }
        while(j!=0&&arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr,i,j);
        }
    }
    swap(arr,s,j);
    return j;
}
void QuickSort(int arr[],int s,int e){
    if(s<e){
        int pivot=partition(arr,s,e);
        QuickSort(arr,s,pivot-1);
        QuickSort(arr,pivot+1,e);
    }
}
void merge(int arr[],int s1,int e1,int e2){
    int i=s1,j=e1+1;
    int k=0;
    int temp[e2-s1+1]={0};
    while(i<=e1&&j<=e2){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;i++;
        }
        else{
            temp[k]=arr[j];
            k++;j++;
        }
    }
    while(i<=e1){
        temp[k]=arr[i];
        k++;i++;
    }
    while(j<=e2){
        temp[k]=arr[j];
        k++;j++;
    }
    int l=s1;
    for(int i=0;i<e2-s1+1;i++){
        arr[l]=temp[i];
        l++;
    }
}
void MergeSort(int arr[],int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        MergeSort(arr,s,mid);
        MergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);

    }
}



int main(){
    int arr[]={5,9,7,1,15,13,17,15};
    // int arr[]={1,2,4,5,6,7,3,8};
    printByRecursion(arr,8);
    // BubbleSort(arr,8);
    // BubbleSortByRecursion(arr,8);
    // insertionSort(arr,8);
    // printByRecursion(arr,8);
    cout<<endl;
    // insertionSortByRecursion(arr,8);
    // selectionSort(arr,8);
    // selectionsortbyRecursion(arr,8);
    // QuickSort(arr,0,7);
    MergeSort(arr,0,7);
    printByRecursion(arr,8);
   
}