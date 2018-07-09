#include <iostream>
#include <vector>

using namespace std;

namespace DATE_ {
enum MONTH {
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};
}

const uint8_t monDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string dayOfWeek[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

struct Date {
	uint16_t year;
	DATE_::MONTH month;
	uint8_t day;
};

bool isLeapYear(const uint16_t year) {
	// 4의 배수이면서 100의 배수가 아닌 년도는 윤년
	if ((year % 4 == 0 && year % 100 != 0)) return true;
	// 400의 배수면 무조건 윤년
	if (year % 400 == 0) return true;
	return false;
}

uint32_t getDays(const Date& date) {
	uint32_t days = date.day;

	for(uint16_t i = 1; i < date.year; ++i) {
		if (isLeapYear(i)) days += 366;
		else days += 365;
	}

	for (uint8_t i = 1; i < date.month; ++i) {
		if(i == 2) {
			if(isLeapYear(date.year)) days += 29;
			else days += 28;
			continue;
		}
		days += monDays[i];
	}
	return days;
}

uint32_t getDiffDays(const Date& start, const Date& end) {
	const uint32_t startDays = getDays(start);
	const uint32_t endDays = getDays(end);
	return endDays - startDays;
}

string getDayOfWeek(const Date& date) {
	uint32_t days = getDays(date);
	return dayOfWeek[days % 7 - 1];
}

vector<string> getCalendar(const Date& date) {
	uint32_t days = getDays(date);
	uint8_t dOfw = days % 7 - 1;
	vector<string> result;

	// 요일 넣기
	for (uint8_t i = 0; i < 7; ++i) {
		result.push_back(dayOfWeek[i]);
	}

	// 빈 칸 넣기
	for (uint8_t i = 0; i < dOfw; ++i) {
		result.push_back("");
	}

	// 날짜 넣기
	for (uint8_t i = 1; i <= monDays[date.month]; ++i) {
		result.push_back(to_string(i));
	}

	// 윤년 처리
	if (isLeapYear(date.year) && (date.month == DATE_::Feb)) {
		result.push_back(to_string(29));
	}

	// 출력
	for (uint8_t i = 0; i < result.size(); ++i) {
		if (i % 7 == 0) cout << endl;
		cout.width(5);
		cout << result[i];
	}
	return result;
}

int main() {
	// getDays
	{
		// 1993-03-02 ~ 2018-07-09 (9260일)
		Date start;
		start.year = 1993;
		start.month = DATE_::Mar;
		start.day = 2;

		Date end;
		end.year = 2018;
		end.month = DATE_::Jul;
		end.day = 9;

		cout << "1993-03-02 ~ 2018-07-09 (" << getDiffDays(start, end) << "일)" << endl;
	}
	// getDayOfWeek
	{
		Date date;
		date.year = 1993;
		date.month = DATE_::Mar;
		date.day = 2;

		cout << "1993-03-02 " << getDayOfWeek(date) << endl; 
	}
	// getCalendar
	{
		Date date;
		date.year = 1992;
		date.month = DATE_::Feb;
		date.day = 1;

		vector<string> calender = getCalendar(date);
	}
	return 0;
}
