#include <iostream>

using namespace std;

void heapify(int arr[],int i,int size);

void swap(int arr[],int n,int m) {
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;

}

void heapMachine(int arr[],int size){
    //build using step up
    
    
    int nonLeaf = (size/2)-1;
    
    
    
    for(int i = nonLeaf;i>=0;i--){
        int index = i;

        heapify(arr,index,size);
        
    }
    
    
    
    //build 
}


void heapify(int arr[],int i,int size){
    
    
    int index = i;
    int left = (2*index)+1;
    int right = (2*index)+2;
    
    int largest = index;
    
    if(left<size&&arr[left]>arr[largest]){
        largest = left;
    }
    
    if(right<size&&arr[right]>arr[largest]){
        largest = right;
    }
    
    
    if(index==largest){
        return;
    }
    
    swap(arr,index,largest);
    
    index = largest;
    heapify(arr,largest,size);
}


int returnKth(int arr[],int k,int size){
    if(k==0 || k>size){
        return -1;
    }
    int kth = 0;
    
    heapMachine(arr,size);
    for(int i = 1;i<=k;i++){
        arr[0] = arr[size-1];
        size--;
        heapify(arr,0,size);
        if(i==k){
            kth = arr[0];
        }
    }
    
    return kth;
}
void print(int arr[],int size){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<"->";
    }
    cout<<"\n";
}
int main(){
    int *arr = new int[7]{1, 23, 12, 9, 30, 2, 50};
    int kth = returnKth(arr,2,7);
    //heapMachine(arr,7);
    //print(arr,7);
    cout<<kth;
    return 0;
}
