//https://cryptosalamander.tistory.com/38 ยüฐํวิ

#include <iostream>
using namespace std;

void printStar(int i, int j, int num);

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printStar(i, j, N);
		}
		cout << endl;
	}

	return 0;
}

void printStar(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
		cout << " ";
	}
	else {
		if (num / 3 == 0) {
			cout << "*";
		}
		else {
			printStar(i, j, num / 3);
		}
	}
}