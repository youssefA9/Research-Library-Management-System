#include <iostream>
using namespace std;

void Alg_1(int arr[], int size) {
	int count_0 = 0;
	int count_1 = 0;
	for (int i = 0; i < size ; i++) {
		if (arr[i] == 0) {
			count_0++;
		}
		else if (arr[i] == 1) {
			count_1++;
		}
	}
	for (int i = 0; i < size; i++) {
		if (i < count_0) {
			arr[i] = 0;
		}
		else {
			arr[i] = 1;
		}
	}
}

void Alg_2(int arr[], int size) {
	int head = 0, tail = size - 1;
	int temp = 0;
	for (int i = 0; i < size; i++) {
		
		if (tail < head) {
		break;
		}
		else if (arr[head] == 1 && arr[tail] == 0) {
			temp = arr[head];
			arr[head] = arr[tail];
			arr[tail] = temp;
			head++;
			tail--;
		}
		else if (arr[tail] == 1) {
			tail--;
		}
		else if (arr[head] == 0) {
			head++;
		}
	}
}

void Alg_3(int arr[], int size) {

	int lo = 0;
	int hi = size - 1;
	int mid = 0;

	while (mid <= hi) {
		switch (arr[mid]) {

			// If the element is 0 
		case 0:
			swap(arr[lo++], arr[mid++]);
			break;

			// If the element is 1 . 
		case 1:
			mid++;
			break;

		}
	}
}

void main() {
	int x[] = {1,0,1,0,1,0,0,1,0};
	int y[] = {1,0,1,0,1,0,0,1,0};
	int z[] = { 1,0,1,0,1,0,0,1,0 };
	int size = sizeof(x) / sizeof(x[0]);
	Alg_1(x, size);
	for (int i = 0; i < size; i++) {
		cout << x[i];
		if (i != size - 1) {
			cout << ",";
		}
	}
	cout << "\n-----------------------------------------" << endl;
	size = sizeof(y) / sizeof(y[0]);
	Alg_2(y, size);
	for (int i = 0; i < size; i++) {
		cout << y[i];
		if (i != size - 1) {
			cout << ",";
		}
	}
	cout << "\n-----------------------------------------" << endl;
	size = sizeof(z) / sizeof(z[0]);
	Alg_3(z, size);
	for (int i = 0; i < size; i++) {
		cout << z[i];
		if (i != size - 1) {
			cout << ",";
		}
	}
}