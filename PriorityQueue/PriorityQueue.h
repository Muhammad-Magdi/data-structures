template <class DT>
class PriorityQueue{
private:
	DT * elements;								//Array of DT
	int numNodes;									//Number of Nodes in PriorityQueue
	int maxSize;
	void extend();								//duplicates the size of the elements array
	inline int parentOf(int) const;	//returns the index of the parent of the given index
	inline int leftChild(int) const;//return the index of the left child
	inline int rightChild(int) const;//return the index of the right child
	void swap(int, int);
	void heapifyUp(int);					//restores heap properties either bottom-up
	void heapifyDown(int);				//restores heap properties either top-down
public:
	PriorityQueue();							//default Constructor
	PriorityQueue(int);						//takes initial array size
	void push(DT);								//inserts an elements to the PriorityQueue
	void pop();										//deletes the top priority element
	DT top() const;								//returns the top priority element
	inline int size() const;			//returns the number of nodes in the array
	inline bool empty() const;		//returns whether the PriorityQueue empty or not
	inline int capacity() const;  //returns the maximum size
};

#include "PriorityQueue.cpp"
