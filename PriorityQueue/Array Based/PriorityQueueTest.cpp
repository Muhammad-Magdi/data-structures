#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main(){
	PriorityQueue<double> pq;
	int n;
	double x;
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		cin >> x;
		pq.push(x);
		cout << "Current Capacity is " << pq.capacity() << endl;
	}
	cout << "Size is " << pq.size() << endl;
	while(!pq.empty()){
		cout << "Current top val is " << pq.top() << " and capacity is "  << pq.capacity() << endl;
		pq.pop();
	}
	return 0;
}

/*
5
5 2 31 3 1
*/
