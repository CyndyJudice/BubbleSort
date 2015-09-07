#include <iostream>
#include <vector>
#include "math.h"
#include <cmath>

using namespace std;

int* heap = NULL;
const int size = 100;


// PRE:  data between subscript top+1 and numElements-1 is a heap.
// POST: data between subscript top and numElements-1 is a heap.
void ReheapDown( int* heap, int top, int numElements )  {
	int leftChild = 2 * top + 1;
	int rightChild = 2 * top + 2;
	int minChild;
	if( leftChild < numElements ) { // size
 		// find subscript of smallest child
		if( rightChild >= numElements || heap[leftChild] < heap[rightChild] )
			minChild = leftChild;
		else
			minChild = rightChild;
		// if data at top is greater than smallest
		// child then swap and continue
		if (heap[top] > heap[minChild]) {
			swap( heap[top], heap[minChild] );
			ReheapDown( heap, minChild, numElements);
		}
	}
}

//PRE:	heap is a ptr to an array
//		current == subscript of the node to be considered
//		0 <= current < the capacity of the array pointed to by heap
//POST:	data in heap[current] has been moved up through the heap to its 	
//		appropriate location
bool ReheapUp( int* heap, int current )  {
	//bool b = false;
	int parent = floor((current - 1)/2);

    if (current > 0) {
		if (heap[current] < heap[parent]) {
			swap(heap[current], heap[parent]);
			ReheapUp(heap, parent);
			//b= true;
			return true;
		}
	}
	//b= false;
	return false;	
	
}
	
//PRE:  data points to an array
//POST: The first size elements of arr are a minimum heap.
void BuildMinHeap( int* arr, int numElements) {
	int index;
	for( index = (numElements - 2) / 2; index >= 0; index-- )
		ReheapDown( arr, index, numElements);
}

//PRE:  The capacity of the array pointed to by heap
//POST: The first size elements of data have been sorted in descending order. 
void sort( int* heap, int numElements) {
	int swpIndx;
	BuildMinHeap( heap, numElements );  // Heapify algorithm	
	for( swpIndx = numElements - 1; swpIndx > 0; swpIndx-- )
	{
		swap( heap[0], heap[swpIndx] );
		ReheapDown( heap, 0, swpIndx );
	}
}

//PRE:  The capacity of the array pointed to by heap
//POST: The first size elements of heap are printed to the screen.
void printList( int* heap, int numElements )  {
	for( int i = 0; i < numElements; i++ )
		cout << heap[i] << " ";
	cout << endl;
}

//PRE:	heap is a ptr to an array
//		key is the value to be added to the heap
//		last is the subscript of the last element in the heap
//POST:	key has been added to the heap
void insert( int* heap, int key, int last) {
	
	//	...to be completed...
	
	heap[last + 1] = key;
	ReheapUp(heap, last+1);


}

//PRE:	Element at top (root) of heap is to be removed from the heap
//POST:	Element has been removed from heap and true returned,
//		or the heap was empty and false returned
bool remove( int* heap, int last, int numElements) {
	
	//	...to be completed...
	if (heap < 0) {
		return false;
	} else {
		swap(heap[0], heap[last]);

		// cout << "Look here" << endl; 
		// printList(heap, numElements);
		ReheapDown(heap, 0, numElements-1);
		last--;
		cout << "Look here again";
		for (int i=0; i <= last;i++) {
			cout << heap[i] << " ";
		}
		cout << endl;

		return true;
	}
}


int main() {
	
	int arr[5] = {3,4,5,2,7};
	BuildMinHeap(arr, 5);
	printList(arr, 5);
	
	ReheapUp(arr, 2);
	printList(arr, 5);

	insert(arr, 8, 4);
	printList(arr, 6);

	insert(arr, 1, 5);
	printList(arr, 7);

	remove(arr, 6, 7);
	printList(arr, 6);

	int arrr[5] = {9,6,4,1,10};
	ReheapUp(arrr, 3);
	printList(arrr, 5);


	return 0;
}