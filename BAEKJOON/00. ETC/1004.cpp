#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int T;	//테스트 케이스
	cin >> T;

	int start[2];	//출발점의 좌표
	int end[2];		//도착점의 좌표

	int n;	//행성계의 개수

	int count;	//행성계 진입, 이탈 횟수

	for (int i = 0; i < T; i++) {

		count = 0;

		cin >> start[0] >> start[1] >> end[0] >> end[1];

		cin >> n;

		int** planet = new int* [n];	//행성의 정보 저장할 메모리 할당
		for (int j = 0; j < n; j++) {
			planet[j] = new int[3];
		}

		for (int j = 0; j < n; j++) {
			cin >> planet[j][0] >> planet[j][1] >> planet[j][2];	//행성의 중심 좌표, 반지름 입력
		}

		for (int j = 0; j < n; j++) {
			double distance_s_p;	//출발점과 행성 사이의 거리
			double distance_e_p;	//도착점과 행성 사이의 거리

			distance_s_p = sqrt((start[0] - planet[j][0]) * (start[0] - planet[j][0]) 
			+ (start[1] - planet[j][1]) * (start[1] - planet[j][1]));
			distance_e_p = sqrt((end[0] - planet[j][0]) * (end[0] - planet[j][0])
				+ (end[1] - planet[j][1]) * (end[1] - planet[j][1]));

			if (distance_s_p > planet[j][2] && distance_e_p < planet[j][2])
				count++;
			else if (distance_s_p < planet[j][2] && distance_e_p > planet[j][2])
				count++;
		}

		cout << count << endl;

		for (int i = 0; i < n; i++) {	//행성의 정보 저장된 메모리 해제
			delete[]planet[i];
		}
		delete[]planet;
	}

	return 0;
}