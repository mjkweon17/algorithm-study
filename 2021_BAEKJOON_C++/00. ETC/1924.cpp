#include <iostream>
using namespace std;

int main(void) {

	string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int month;
	int date;
	int diff = 0;

	cin >> month >> date;

	for (int i = 1; i < month; i++) {
		diff += days_in_month[i - 1];
	}

	diff += date;

	cout << day[diff % 7];

	return 0;
}