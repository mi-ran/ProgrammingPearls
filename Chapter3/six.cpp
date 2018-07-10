#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<string> > datas;

vector<string> splitString(const string& str, const char ch) {
	vector<string> result;
	size_t s_pos = 0;
	size_t e_pos = str.find(ch);
	while (e_pos != string::npos) {
		result.push_back(str.substr(s_pos, e_pos - s_pos));
		s_pos = e_pos + 1;
		e_pos = str.find(ch, s_pos);
	}
	result.push_back(str.substr(s_pos));
	return result;
}

void readScheme(const string& file) {
	fstream openFile(file.c_str());
	if (!openFile.is_open()) return;

	string line;
	while(getline(openFile, line)){
		datas.push_back(splitString(line, '/'));
	}
	openFile.close();
}

bool isNumber(char n) {
	return '0' <= n && n <= '9';
}

void print(int num) {
	string text = "$1 회원($2)이 $4일에 $6에서 $3을 빌려갔습니다. 반납일은 $5일 입니다.";

	size_t pos = text.find('$');
	while(pos != string::npos) {
		size_t e_pos = pos + 1;
		while (isNumber(text[e_pos])) {
			++e_pos;
			if (e_pos == text.size()) break;
		}

		string s_index = text.substr(pos+1, e_pos - 1);
		int i_index = std::stoi(s_index);
		text.replace(pos, e_pos - pos, datas[num][i_index]);
		pos = text.find('$', e_pos);
	}

	cout << text << endl;
}

int main() {
	readScheme("scheme.txt");
	print(0);
}
