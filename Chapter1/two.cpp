#include <iostream>
#include <time.h>

using namespace std;

#define MAX_ARRAY_SIZE 312501
#define INT_SIZE 32
#define MAX 1000000
#define MAX_NUM 10000000

class BitVector
{
public:
	BitVector();
	void insert(const int value);
	void remove(const int value);
	void print();
private:
	uint32_t m_data[MAX_ARRAY_SIZE];
};

BitVector::BitVector()
{
	for(int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		m_data[i] = 0;
	}
}

void BitVector::insert(const int value)
{
	uint32_t mask = 0x00000001;
	m_data[value/INT_SIZE] = m_data[value/INT_SIZE] | (mask << (value % INT_SIZE));
}

void BitVector::remove(const int value)
{
	uint32_t mask = 0x00000001;
	m_data[value/INT_SIZE] = m_data[value/INT_SIZE] & ~(mask << (value % INT_SIZE)); 
}

void BitVector::print()
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		if(m_data[i] == 0) {
			continue;
		}
		uint32_t tmp = 0x00000001;
		for (int j = 0; j < INT_SIZE; ++j) {
			if((tmp & m_data[i]) != 0) {
				cout << i * INT_SIZE + j << endl;
			}
			tmp = tmp << 1;
		}
	}
}

int main()
{
	BitVector vector;
	clock_t begin, end;
	begin = clock();

	// rand
	for (int i = 0; i < MAX; ++i) {
		vector.insert(rand()%MAX);
	}
	end = clock();
	cout<<"수행시간 : "<<((double)(end-begin)/(double)CLOCKS_PER_SEC)<<endl;

//	// insert
//	vector.insert(2);
//	vector.insert(11);
//	vector.insert(34);
//	vector.insert(32);
//	vector.insert(110);
//	// remove
//	vector.remove(34);
//	// print
//	vector.print();
	return 0;
}

