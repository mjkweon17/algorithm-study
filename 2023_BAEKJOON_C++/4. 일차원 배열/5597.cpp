#include <iostream>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int student[31];

int main(void) {

	init();

	for (int i = 0; i < 28; i++) {
		int stu;
		cin >> stu;
		student[stu] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (!student[i])
			cout << i << "\n";
	}

	return 0;
}