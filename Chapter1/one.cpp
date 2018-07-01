#include<iostream>
#include <stdlib.h>
#include <set>
#include <stdio.h>
#include <time.h>

using namespace std;

#define MAX 1000000
#define MAX_NUM 10000000
int data[MAX];

void sortWithSet() {
	set<int> sortedData;
	for(int i = 0; i < MAX; ++i) {
		sortedData.insert(data[i]);
	}

	//for(set<int>::iterator iter = sortedData.begin(); iter != sortedData.end(); ++iter) {
	//	cout << *iter << endl;
	//}
}

int compare(const void* left, const void* right) {
	return *(int *)left - *(int *)right;
}

int main() {
	// rand
	for (int i = 0; i < MAX; ++i) {
		data[i] = rand();
	}

	// set으로 sort
	cout << "set으로 sort" << endl;
	clock_t begin, end;
	begin = clock();
	sortWithSet();
	end = clock();
	cout<<"수행시간 : "<<((end-begin)/CLOCKS_PER_SEC)<<endl;

	// qsort로 sort
	cout << "qsort로 sort" << endl;
	begin = clock();
	qsort(data, MAX, sizeof(int), compare);
	end = clock();
	cout<<"수행시간 : "<<((end-begin)/CLOCKS_PER_SEC)<<endl;
	//for (int i = 0; i < MAX; ++i) {
	//	cout << data[i] << endl;
	//}

	return 0;
}
