#include <iostream>
#include "linked_list.h"
using namespace std;


int main() {
	linked_list<int> firstLL; 
	firstLL.insert(1); 
	firstLL.insert(20);

	linked_list<int> secondLL; 
	secondLL.insert(3); 
	secondLL.insert(4); 

	linked_list<int>::concatenate(firstLL.gethead(), secondLL.gethead());
	cout << "-- " << endl; 

	linked_list<int>::printLL(firstLL.gethead());
	firstLL.deletePos(1); 
	cout << "-- " << endl; 

	linked_list<int>::printLL(firstLL.gethead());
	firstLL.deleteVal(20); 
	cout << "-- " << endl; 

	linked_list<int>::printLL(firstLL.gethead());
	firstLL.insertPos(30, 1); 
	cout << "-- " << endl; 

	linked_list<int>::printLL(firstLL.gethead());
	firstLL.deletePos(10); 
	firstLL.insertPos(40, 11);

	return 0;
}