#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
using namespace std;

template<typename T>
struct node {
	T data;
	node* next;
};


template<typename T>
class linked_list {
private:
	node<T>* head, * tail;
	int node_size = 0;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}

	void add_at_head(T value) {
		node<T>* nod = new node<T>;
		nod->data = value;
		if (node_size == 0) {
			nod->next = NULL;
			head = nod;
			tail = nod;
		}
		else {
			nod->next = head;
			head = nod;
		}
		node_size++;
	}

	void add_at_tail(T value) {
		node<T>* nod = new node<T>;
		nod->data = value;
		if (node_size == 0) {
			head = nod;
			tail = nod;
			nod->next = NULL;
		}
		else {
			tail->next = nod;
			tail = nod;
			nod->next = NULL;
		}
		node_size++;
	}

	void insert(T n) {
		add_at_tail(n);
	}

	void insertPos(int data, int position) {
		int counter = 0;
		node<T>* pos;
		pos = head;
		while (pos->next != NULL) {
			counter++;
			pos = pos->next;
		}
		node_size = counter;
		tail = pos;
		if (position >= 0 && position < node_size + 1) {
			if (position == 0) {
				add_at_head(data);
			}
			else if (position == node_size) {
				add_at_tail(data);
			}
			else {
				node<T>* nod = new node<T>;
				nod->data = data;
				node<T>* p;
				node<T>* p2;
				p = head;
				p2 = head->next;
				for (int i = 0; i < position - 1; i++) {
					p = p->next;
					p2 = p2->next;
				}
				p->next = nod;
				nod->next = p2;
			}
			node_size++;
		}
		else {
			cout << "Insertion Out of Boundries" << endl;
		}
	}

	node<T>* gethead() {
		return head;
	}

	static void printLL(node<T>* head) {
		if (head != NULL) {
			cout << head->data << endl;
			head = head->next;
			printLL(head);
		}
	}

	void deletePos(int position) {
		int counter = 0;
		node<T>* pos;
		pos = head;
		while (pos->next != NULL) {
			counter++;
			pos = pos->next;
		}
		node_size = counter;
		if (position >= 0 && position < node_size) {
			if (position == 0) {
				node<T>* p;
				p = head;
				head = head->next;
				delete p;
			}
			else if (position == node_size-1) {
				node<T>* p;
				p = head;
				for (int i = 0; i < node_size - 2; i++) {
					p = p->next;
				}
				tail = p;
				tail->next = NULL;
				p = p->next;
				delete p;
			}
			else {
				node<T>* p;
				node<T>* p1;
				p = head;
				p1 = head;
				p1 = p1->next;
				
				for (int i = 0; i < position-1; i++) {
					p = p->next;
					p1 = p1->next;
				}
				p->next = p1->next;
				delete p1;
			}
			node_size--;
		}
		else {
			cout << "Deletion Out of Boundries" << endl;
		}
	}

	void deleteVal(T value) {
		int counter = 0;
		node<T>* pos;
		pos = head;
		while (pos->next != NULL) {
			counter++;
			pos = pos->next;
		}
		node_size = counter;
		tail = pos;
		node<T>* po;
		bool val_checker = false;
		po = head;
		while (po->next != NULL) {
			if (po->data == value) {
				val_checker = true;
				break;
			}
			po = po->next;
		}
		if (value == head->data) {
			deletePos(0);
		}
		else if (value == tail->data) {
			deletePos(node_size - 1);
		}
		else if (val_checker == true){
			node<T>* p;
			node<T>* p1;
			p = head;
			p1 = head;
			p1 = p1->next;

			for (int i = 0; i < node_size-1; i++) {
				if (p1->data == value) {
					break;
				}
				p = p->next;
				p1 = p1->next;
			}
			if (p1 != NULL) {
				p->next = p1->next;
				delete p1;
			}
		}
		node_size--;
	}

	static void concatenate(node<T>* a, node<T>* b) {
		while (a->next != NULL) {
			a = a->next;
		}
		a->next = b;
	}

};

#endif //LINKED_LIST_H_
