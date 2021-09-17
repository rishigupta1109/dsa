#include<bits/stdc++.h>
using namespace std;
void Swap(int arr[],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void print (int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
void bubbleSort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){              
            if(arr[j-1]>arr[j]){
                Swap(arr,j-1,j);
            }
        }
    }
}
void selectionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int minIndex=i-1;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        Swap(arr,i-1,minIndex);
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i;
       while(j!=0&&arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
       }
       arr[j]=temp;
    }
}
int partition(int arr[],int a,int b){
    int pivot=arr[a];
    int i=a,j=b;
    while(i<j){
        while(i!=b&&arr[i]<=pivot){
            i++;
        }
        while(j!=0&&arr[j]>pivot){
            j--;
        }
        if(i<j){
            Swap(arr,i,j);
        }
    }
    Swap(arr,a,j);
    return j;
}
void quickSort(int arr[],int a,int b){
    if(a<b){
    int pivot=partition(arr,a,b);
        quickSort(arr,a,pivot-1);
        quickSort(arr,pivot+1,b);
    }
} 
void merge(int arr[],int start1,int end1,int end2){
    int s1=start1;
    int e1=end1;
    int e2=end2;
    int s2=e1+1;
    int temp[e2+1];
    int k=0;
    while(s1<=e1&&s2<=e2){
        if(arr[s1]>arr[s2]){
            temp[k]=arr[s2];
            k++;
            s2++;
        }
        else{
            temp[k]=arr[s1];
            k++;
            s1++;
        }
    }
    while(s1<=e1){
        temp[k]=arr[s1];
        k++;s1++;
    }
    while(s2<=e2){
        temp[k]=arr[s2];
        k++;
        s2++;
    }
    int l=0;
    for(int i=start1;i<=end2;i++){
        arr[i]=temp[l];
        l++;
    }
    
}
void mergeSort(int arr[],int a,int b){
    if(a<b){
        int mid=(a+b)/2;
        mergeSort(arr,a,mid);
        mergeSort(arr,mid+1,b);
        merge(arr,a,mid,b);
    }
}
void countingSort(int arr[],int n){
    int maxElement=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maxElement){
            maxElement=arr[i];
        }
    }
    int temp[maxElement+1]={0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    for(int i=1;i<maxElement+1;i++){
        temp[i]+=temp[i-1];
    }
    int ansArray[n]={0};
    for(int i=0;i<n;i++){
        int x=arr[i];
        temp[x]--;
        ansArray[temp[x]]=x;
    }
    for(int i=0;i<n;i++){
        arr[i]=ansArray[i];
    }

}
void radixSort(int arr[],int n){
    int maxElement=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maxElement){
            maxElement=arr[i];
        }
    }
    int maxPlaces=0;
    while(maxElement!=0){
        maxPlaces++;
        maxElement/=10;
    }
    for(int i=0;i<maxPlaces;i++){
       vector<int> newArray[10];
        for(int j=0;j<n;j++){
            int x=arr[j];
            int y=0;
            for(int k=0;k<=i;k++){
                if(x<10&&i==0){
                        y=x;
                        break;
                }
                y=x%10;
                x=x/10;
            }
            
            newArray[y].push_back(arr[j]);
            
        }
        int index=0;
        for(int l=0;l<10;l++){
            for(int j=0;j<newArray[l].size();j++){
                arr[index]=newArray[l][j];
                index++;
            }
        }
     
    }
}
void shellSort(int arr[],int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]<arr[i]){
                    Swap(arr,(i+gap),i);
                }
                else{
                    break;
                }
            }
        }
    }
}
int main(){
int n=6; 
int array[n]={11,3,5,2,7,1};
print(array,n);
// bubbleSort(array,n);
// selectionSort(array,n);
// insertionSort(array,n);
// quickSort(array,0,n-1);
// mergeSort(array,0,n-1);
// countingSort(array,n);
// radixSort(array,n);
shellSort(array,n);
print(array,n);
}