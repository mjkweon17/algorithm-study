#include <iostream>
using namespace std;

int main(void) {

	int T;	//Test Case
	cin >> T;
	
	int floor, room; //층, 호
	//추후 floor는 k로, room은 n으로 rename. 
	//floor는 0부터, room은 1부터 시작

	for (int i = 0; i < T; i++) {

		cin >> floor >> room;

		//floor는 1더해주기. 왜냐하면, 0층부터 시작하기 때문에 n번째 floor는 n+1번째 층과 다름이 없다
		floor++;

		//arr[floor][room]을 이중 배열로 동적할당하기
		int** arr = new int* [floor];
		for (int i = 0; i < floor; i++) {
			arr[i] = new int[room];
		}

		//0층에 있는 방들 전부 i + 1명으로 초기화
		for (int i = 0; i < room; i++) {
			arr[0][i] = i + 1;
		}
		//1호에 있는 방들 전부 1명으로 초기화
		for (int i = 0; i < floor; i++) {
			arr[i][0] = 1;
		}

		//나머지 호수들 전부 arr[i - 1][j] + arr[i][j-1]로 초기화
		for (int i = 1; i < floor; i++) {
			for (int j = 1; j < room; j++) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		//cout << arr[i][j]
		cout << arr[floor - 1][room - 1] << endl;

		//동적할당 메모리 해제하기
		for (int i = 0; i < floor; i++) {
			delete[] arr[i];
		}
		delete[]arr;
	}

	return 0;
}