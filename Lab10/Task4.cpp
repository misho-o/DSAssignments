#include <iostream>


using namespace std;

void swap(int arr[],int n,int m) {
    
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;

}
void heapify(int arr[],int i,int size){
    
    int index = i;
    int left = (index*2)+1;
    int right = (index*2)+2;
    
    int largest = index;
    
    if(index<size&&arr[left]>arr[largest]){
        largest = left;
    }
    if(index<size&&arr[right]>arr[largest]){
        largest = right;
    }
    
    
    if(index==largest){
        return;
    }
    swap(arr,index,largest);
    
    heapify(arr,largest,size);
}
void buildMaxHeap1(int arr[],int size){
    //step up method

    int ele = size-1;
    for(int i = ele ;i>=0 ;i--){
        
        int index = i;
        int parent = (index-1)/2;
        
        while(index>0&&arr[index]>arr[(index-1)/2]){
            
            int parent = (index-1)/2;
        
            swap(arr,index,parent);
            index = parent;
            }
        
        }
        
        
        for(int i = 0;i<size;i++){
            cout<<arr[i]<<"->";
        }

        cout<<"\n";
    }


void buildMaxHeap(int arr[],int size){
    //if using heapify
    int ele = size-1;
    int nonLeaf = (ele/2)-1;
    for(int i = nonLeaf ;i>=0 ;i--){
        
        int index = i;
        
        
        heapify(arr,index,size);
        
    }
}


void print(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<"->";
    }

    cout<<"\n";
}


int main(){
    int size = 10;
    int* arr = new int[size]{3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    buildMaxHeap1(arr,size);
    //{20, 18, 10, 12, 9, 9, 3, 5, 6, 8}
    
    //print(heap,size);
    return 0;
}
