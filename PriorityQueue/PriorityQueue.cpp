#include <string.h>
#include <stdio.h>

/*
	Default constructor that initializes the:
	Elements array with size two
	number of nodes to zero
	maximum size with two
*/
template<class DT>
PriorityQueue<DT> :: PriorityQueue(){
	elements = new DT[2];
	numNodes = 0;
	maxSize = 2;
}

/*
	Constructor that takes the initial size of the array
*/
template<class DT>
PriorityQueue<DT> :: PriorityQueue(int initialSize){
	elements = new DT[initialSize];
	numNodes = 0;
	maxSize = initialSize;
}

template<class DT>
void PriorityQueue<DT> :: extend(){		//Duplicates the size of the elements array
	maxSize <<= 1;											//Duplicate maximum Size
	DT * newArray = new DT[maxSize];		//get an array with the new maximum size
	memcpy(newArray, elements, numNodes * sizeof elements[0]);
	delete [] elements;									//delete the old array
	elements = newArray;								//Hello Array :D
}

template<class DT>
inline int PriorityQueue<DT> :: parentOf(int idx)const{
	return (idx>0 ? (idx-1)>>1 : 0);			//returns index of parent otherwise, root
}

template<class DT>
inline int PriorityQueue<DT> :: leftChild(int idx)const{
	return (((idx<<1)+1)<numNodes ? (idx<<1)+1 : idx);		//left child or me
}

template<class DT>
inline int PriorityQueue<DT> :: rightChild(int idx)const{
	return (((idx<<1)+2)<numNodes ? (idx<<1)+2 : idx);		//right child or me
}

template<class DT>
void PriorityQueue<DT> :: swap(int i1, int i2){
	DT tmp = elements[i1];
	elements[i1] = elements[i2];
	elements[i2] = tmp;
}

template<class DT>
void PriorityQueue<DT> :: heapifyUp(int idx){
	int parent = parentOf(idx);
	if(elements[parent] < elements[idx]){
		swap(idx, parent);
		heapifyUp(parent);
	}
}

template<class DT>
void PriorityQueue<DT> :: heapifyDown(int idx){
	int lft = leftChild(idx), rit = rightChild(idx);
	if(elements[idx] < elements[lft] && elements[rit] <= elements[lft]){
		swap(idx, lft);
		heapifyDown(lft);
	}else if(elements[idx] < elements[rit]){
		swap(idx, rit);
		heapifyDown(rit);
	}
}

template<class DT>
void PriorityQueue<DT> :: push(DT newElement){
	if(numNodes == maxSize)	extend();
	elements[numNodes] = newElement;
	heapifyUp(numNodes++);
}

template<class DT>
void PriorityQueue<DT> :: pop(){
	if(!numNodes)	return;
	swap(0, --numNodes);
	heapifyDown(0);
}

template<class DT>
DT PriorityQueue<DT> :: top()const{
	if(!numNodes)	throw "Empty Priority Queue";
	return elements[0];
}

template<class DT>
inline int PriorityQueue<DT> :: size()const{
	return numNodes;
}

template<class DT>
inline bool PriorityQueue<DT> :: empty()const{
	return numNodes == 0;
}

template<class DT>
inline int PriorityQueue<DT> :: capacity()const{
	return maxSize;
}
