#include <iostream>
#include <time.h>
#include <string>

using namespace std;

tm setTmStruct(const uint32_t year, const uint32_t mon, const uint32_t day) {
	tm result;
	result.tm_year = year - 1900;
	result.tm_mon = mon;
	result.tm_mday = day;
	result.tm_hour = 0;
	result.tm_sec = 0;
	result.tm_min = 0;
	return result;
}

uint32_t getDays(const time_t& start, const time_t& end) {
	uint32_t sec = difftime(end, start);
	return sec/(60*60*24);
}

uint32_t getDays(tm& start, tm& end) {
	return getDays(mktime(&start), mktime(&end));
}

uint32_t getDays(const uint32_t s_y, const uint32_t s_m, const uint32_t s_d, const uint32_t e_y, const uint32_t e_m, const uint32_t e_d) {
	tm start = setTmStruct(s_y, s_m, s_d);
	tm end = setTmStruct(e_y, e_m, e_d);
	return getDays(start, end);
}

int main() {
	// 1. 2018-10-10 ~ 2018-11-10 (31일)
	cout << "2018-10-10 ~ 2018-11-10 (" << getDays(2018, 10, 10, 2018, 11, 10) << "일)" << endl; 
}
