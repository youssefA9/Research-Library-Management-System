#include<iostream>
using namespace std;

class linkedQ {
public:
	string date, borrower, borrowDate;
	int numOfDays;
	bool flag;
	linkedQ* next;
	linkedQ* first;
	linkedQ* tail;
	int length;
public:
	linkedQ() {
		first = tail = NULL;
		length = 0;
		date = "Empty!";
		borrower = "Empty!";
		borrowDate = "Empty!";
		numOfDays = 0;
		flag = false;
	}
};

class book_linkedlist {
protected:
	struct Node {
		string BookName;
		int ISBN, NumOfCopies;
		Node* next;
		linkedQ* queue_pointer;
	};
	Node* head;
	Node* tail;
	int length;
	bool check_queue = false;
public:
	book_linkedlist() {
		head = tail = NULL;
		length = 0;
	}
	void addbook(string name, int isbn, int num, linkedQ* m) {
		Node* newNode = new Node;
		newNode->ISBN = isbn;
		newNode->BookName = name;
		newNode->NumOfCopies = num;
		newNode->queue_pointer = m;
		if (length == 0) {
			head = tail = newNode;
			newNode->next = NULL;
		}
		else {
			tail->next = newNode;
			newNode->next = NULL;
			tail = newNode;
		}
		length++;
	}
	bool SearchBook(int num) {
		Node* serch = head;
		while (serch != NULL) {
			if (serch->ISBN == num)
				return true;
			serch = serch->next;
		}
		return false;
	}

	void add_copy(int ISBN) {
		Node* borw = head;
		linkedQ* ptr;
		string str;
		int num = 0;
		bool flag = false;
		while (borw != NULL) {
			if (borw->ISBN == ISBN) {
				break;
			}
			borw = borw->next;
		}
		ptr = borw->queue_pointer;
		int NumCopies = 0, numdays = 0;
		string date, borrower, borrowdate;
		bool borrowed;
		char ans;
		cout << "Enter Copy information" << endl;
		cout << "----------------------------" << endl;
		cout << "Is this book borrowed or not (Y/N)" << endl;
		cin >> ans;
		while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
			cout << "Invalid input! please enter a valid one." << endl;
			cin >> ans;
		}
		if (ans == 'y' || ans == 'Y') {
			cout << "Copy date : "; cin >> date;
			cout << "Borrower : "; cin >> borrower;
			cout << "Borrow date : "; cin >> borrowdate;
			cout << "Number of days to return : "; cin >> numdays;
			borrowed = true;
		}
		else {
			borrowed = false;
			date = "Empty!"; borrower = "Empty!"; borrowdate = "Empty!";
			numdays = 0;
		}
		linkedQ* newNode = new linkedQ;
		newNode->date = date;
		newNode->flag = borrowed;
		newNode->borrower = borrower;
		newNode->borrowDate = borrowdate;
		newNode->numOfDays = numdays;
		newNode->next = NULL;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newNode;
		length++;
		cout << endl;
	}

	void book_borrow(int ISBN) {
		Node* borw = head;
		linkedQ* ptr;
		string str;
		int num = 0;
		bool flag = false;
		while (borw != NULL) {
			if (borw->ISBN == ISBN) {
				break;
			}
			borw = borw->next;
		}
		ptr = borw->queue_pointer;
		while (ptr != NULL) {
			if (ptr->flag == false) {
				flag = true;
				break;
			}
			ptr = ptr->next;
		}
		if (flag == true) {
			ptr->flag = true;
			cout << "Enter copy Date : ";
			cin >> str;
			ptr->date = str;
			cout << "Enter your name : ";
			cin >> str;
			ptr->borrower = str;
			cout << "Enter Date : ";
			cin >> str;
			ptr->borrowDate = str;
			cout << "Enter the number of days to return the copy : ";
			cin >> num;
			ptr->numOfDays = num;
			cout << "Book copy has been borrowed" << endl;
		}
		else {
			cout << "No copies are available for this book!" << endl;
		}
	}
	void return_book(int ISBN, string borrower) {
		Node* ret = head;
		linkedQ* ptr;
		int num = 0;
		bool flag = false;
		while (ret != NULL) {
			if (ret->ISBN == ISBN) {
				break;
			}
			ret = ret->next;
		}
		ptr = ret->queue_pointer;
		while (ptr != NULL) {
			if (ptr->borrower == borrower && ptr->flag == true) {
				flag = true;
				break;
			}
			ptr = ptr->next;
		}
		if (flag == true && ptr->borrower == borrower) {
			ptr->flag = false;
			ptr->date = "Empty!";
			ptr->borrower = "Empty!";
			ptr->borrowDate = "Empty!";
			ptr->numOfDays = 0;

			cout << "Book copy has been returned" << endl;
		}
		else {
			cout << "No copies are taken with that borrower name!" << endl;
		}
	}

	void print() {
		Node* pr = head;
		linkedQ* ptr;
		int counter = 1;
		while (pr != NULL) {
			cout << "Book " << counter << " information : " << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "Book Name : " << pr->BookName << endl;
			cout << "Book ISBN : " << pr->ISBN << endl;
			cout << "Number of copies : " << pr->NumOfCopies << endl;
			ptr = pr->queue_pointer;
			int index = 1;
			while (ptr != NULL) {
				cout << "----------------------------------------------" << endl;
				cout << "Copy " << index << " borrowing information : " << endl;
				cout << "----------------------------------------------" << endl;
				cout << "Copy date : " << ptr->date << endl;
				cout << "Borrower : " << ptr->borrower << endl;
				cout << "Borrow date : " << ptr->borrowDate << endl;
				cout << "Number of days to return : " << ptr->numOfDays << endl;
				ptr = ptr->next;
				index++;
			}
			counter++;
			pr = pr->next;
			cout << "------------------------------------------------------" << endl;
			cout << "======================================================" << endl;
			cout << "------------------------------------------------------" << endl;
		}
	}
};

int main() {
	book_linkedlist b;
	linkedQ* bQueue = new linkedQ;
	linkedQ* ptr1 = NULL;
	string bookName;
	int NumCopies, bookISBN;
	string date, borrower, borrowdate;
	int numdays;
	cout << "=============== LIBRARY MANAGEMENT SYSTYEM ================" << endl;
	int choice = 0;
	while (choice != 6) {
		cout << endl;
		cout << "Please select one of the below options" << endl;
		cout << "1- Add a new book " << endl;
		cout << "2- Adding book copies" << endl;
		cout << "3- Adding book borrow " << endl;
		cout << "4- Adding book return" << endl;
		cout << "5- Library inventory" << endl;
		cout << "6- Exit" << endl;
		cin >> choice;
		while (choice < 1 || choice>6) {
			cout << "invalid input! please enter a valid one." << endl;
			cin >> choice;
		}
		switch (choice) {
		case 1:
			bQueue = new linkedQ;
			cout << "Enter the name of the book : "; cin >> bookName;
			cout << "Enter ISBN : "; cin >> bookISBN;
			while (b.SearchBook(bookISBN)) {
				cout << "You can't add two books with the same ISBN" << endl;
				cin >> bookISBN;
			}
			cout << "Enter Number of copies : "; cin >> NumCopies;
			b.addbook(bookName, bookISBN, NumCopies, bQueue);
			for (int i = 0; i < NumCopies; i++) {
				b.add_copy(bookISBN);
			}
			cout << "Book has been added!" << endl;

			break;
		case 2:
			cout << "Enter book ISBN to add copies to it : " << endl;
			cin >> bookISBN;
			if (b.SearchBook(bookISBN)) {
				cout << "Enter number of copies to add : " << endl;
				cin >> NumCopies;
				for (int i = 0; i < NumCopies; i++) {
					b.add_copy(bookISBN);
				}
				cout << "copy has been added!" << endl;
			}
			else {
				cout << "Book is not available!" << endl;
			}
			break;
		case 3:
			cout << "Enter ISBN of the book you want to borrow : " << endl;
			cin >> bookISBN;
			if (b.SearchBook(bookISBN)) {
				b.book_borrow(bookISBN);
			}
			else {
				cout << "This book is not available!" << endl;
			}
			break;
		case 4: {
			cout << "Enter ISBN of the book you want to return : " << endl;
			cin >> bookISBN;
			string str;
			if (b.SearchBook(bookISBN)) {
				cout << "Enter The borrower name : "; cin >> str;
				b.return_book(bookISBN, str);

			}
			else {
				cout << "This book is not available!" << endl;
			}

			break; }
		case 5:
			cout << "Library inventory : " << endl;
			cout << "=======================================" << endl;
			b.print();
			break;
		case 6:
			break;
		}
	}
	return 0;
}