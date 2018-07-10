#include <iostream>
#include <string>

using namespace std;

char array_[10] = {125, 80, 55, 87, 90, 79, 111, 84, 127, 94};

void print(uint16_t num) {
	char res[5];
	int16_t dec = 10000;
	uint8_t idx = 0;
	uint16_t r = num;

	while(idx < 5) {
		res[idx] = array_[r / dec];
		r = r % dec;
		++idx;
		dec = dec / 10;
	}

	for(int8_t i = 0; i < 5; ++i) {
		cout << bitset<7>(res[i]) << endl;
	}
}

int main() {
	uint16_t input;
	cout << "input : ";
	cin >> input;
	cout << endl;

	print(input);
}
