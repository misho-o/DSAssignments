
#include <iostream>
using namespace std;


void swap(int arr[],int n,int m) {
	int temp = arr[n];
	arr[n] = arr[m];
	arr[m] = temp;

}
class maxHeap {
	int * arr;
	int size;
	int totalSize;

public:
	maxHeap(int n) {
		arr = new int[n];
		size=0;
		totalSize = n;
	}
	void deleteByIndex(int i){
	    
	    if(i>=size||i<0){
            cout<<"index out of bounds\n";
            return;
        }
        
        arr[i] = arr[size-1];
        size--;
        
        int index = i;
        
        indexValid(i);
	}
	
	void indexValid(int i){
	    int index = i;
        //case1: indexed element is greater than parent
        bool swapped = false;
        while(index>0&&arr[index]>arr[(index-1)/2]){
            int parent = (index-1)/2;
            swap(arr,arr[index],arr[parent]);
            index = parent;
            swapped = true;
            
        }
        if(swapped){
            return;
        }
        //case2: indexed element children are greater than parent
        
        heapify(index);
	}
    void insertByIndex(int i,int value){
        if(i>=size||i<0){
            cout<<"index out of bounds\n";
            return;
        }
        
        arr[i] = value;
        int index = i;
        indexValid(i);
        
    }
	void insert(int value) {

		//check if array heap is filled or not

		if(size==totalSize) {
			cout<<"heap overflow\n";
			return;
		}
		//add value to current index and store index in var

		arr[size] = value;

		//jis index me store kia current value
		int index = size;
		//store ke bad size increase hoa
		size++;


		while(index>0&&arr[(index-1)/2]<arr[index]) {
			//swap if parent is lesser
			int parent = (index-1)/2;
			int temp = arr[index];
    		arr[index] = arr[parent];
    		arr[parent] = temp;
    
    			//store the swapped parent index in now index
    
    		index = parent;
			
	}
	    
	}
	void heapify(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
    
        // check left child
        if(left < size && arr[left] > arr[largest])
            largest = left;
    
        // check right child
        if(right < size && arr[right] > arr[largest])
            largest = right;
    
        // if no change, stop
        if(largest == index)
            return;
    
        // swap with larger child
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
    
        // continue heapifying down
        heapify(largest);
}

	void del() {
		if(size==0) {
			cout<<"heap underflow \n";
			return;
		}

		cout<<arr[0]<<" deleted\n";
		arr[0] = arr[size-1];
		size--;

		if(size==0) {
			return;
		}
		heapify(0);

	}

	void print() {
		for(int i =0; i<size; i++) {
			cout<<arr[i]<<"->";
		}
		cout<<"\n";
	}
};



int main()
{

	maxHeap h1(10);
	h1.insert(4);
	h1.insert(14);
	h1.insert(11);
	h1.insertByIndex(4,4); 
	h1.insert(14);
	h1.insertByIndex(1,11);
	//h1.deleteByIndex(4);
	h1.print();
	return 0;
}
