#include <iostream>
using namespace std;

int main(void) {

	int N;	//사람의 수
	cin >> N;

	int** frame = new int* [N];
	for (int i = 0; i < N; i++) {
		frame[i] = new int[3];
	}

	for (int i = 0; i < N; i++) {
		cin >> frame[i][0] >> frame[i][1];
		frame[i][2] = 1;	//[i][2]에는 등수 저장
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (frame[i][0] < frame[j][0]) {
				if (frame[i][1] < frame[j][1]) {
					frame[i][2]++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << frame[i][2] << " ";
	}

	for (int i = 0; i < N; i++) {
		delete[] frame[i];
	}
	delete[]frame;

	return 0;
}