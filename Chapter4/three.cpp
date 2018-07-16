#include <iostream>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

class BinarySearch
{
public:
	int binarysearch(int array[], int n, int d);
	BinarySearch(int size);
	~BinarySearch() { delete m_array; }
	void print();
	int find(int d);
private:
	void init();
	int* m_array;
	uint32_t m_size;
};

BinarySearch::BinarySearch(int size)
: m_size(size)
{
	init();
}

void BinarySearch::init() {
	m_array = new int[m_size];
	// 난수 생성
	for (uint8_t i = 0; i < m_size; ++i) {
		m_array[i] = rand() % 15;
	}
	// 정렬
	qsort(m_array, m_size, sizeof(int), compare);
}

int BinarySearch::find(int d) {
	return binarysearch(m_array, m_size, d);
}

int BinarySearch::binarysearch(int array[], int n, int d) {
	if(n == 0) return -1;
	if(array[n-1] < d) return -1;
	if(array[n-1] == d) return n-1;
	int m = n/2;
	int res = 0;

	if (array[m] < d) {
		res = binarysearch(&array[m+1], n-1-m, d) + m + 1;
	} else if (array[m] == d) {
		while(m > 0) {
			--m;
			if(array[m] != d) {
				return m+1;
			}
		}
		return m;
	} else if (array[m] > d) {
		res = binarysearch(array, m, d);
	}

	return res;
}

void BinarySearch::print() {
	for(uint32_t i = 0; i < m_size; ++i) {
		cout << m_array[i] << " ";
	}
	cout << endl;
}

int main() {
	BinarySearch bs(10);
	int res = bs.find(9);
	cout << res << endl;
	bs.print();
}
