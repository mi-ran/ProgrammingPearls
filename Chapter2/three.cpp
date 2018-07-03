#include <iostream>

using namespace std;
#define N 10
int list[N];

void init() {
	for(int i = 0; i < N; ++i) {
		list[i] = i;
	}
}

void one(int n) {
	int* temp = new int[n];

	for (int i = 0; i < n;  ++i) {
		temp[i] = list[i];
	}

	for(int i = n; i < N; ++i) {
		list[i - n] = list[i];
	}

	for(int i = N-n; i < N; ++i) {
		list[i] = temp[i-(N-n)];
	}

	delete[] temp;
}

void two(int n) {
	int temp;
	for (int i = 0; i < n; ++i) {
		temp = list[i];
		int j = i+n;
		for (; j < N; j = j+n) {
			list[j-n] = list[j];
		}
		list[j-n] = temp;
	}
}

void print() {
	cout << "===========================" << endl;
	for(int i = 0; i < N; ++i) {
		cout << list[i] << endl;
	}
}

int main() {
	init();
	one(2);
	print();

	init();
	two(2);
	print();
	return 0;
}
