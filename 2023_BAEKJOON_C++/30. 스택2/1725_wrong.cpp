#include <iostream>
#include <stack>
#include <utility>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int hist[100001];

int main(void) {

	init();

	int N;	//히스토그램의 가로 칸 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hist[i];
	}

	stack<pair<int, int>> S;	//<높이, 너비>
	int largest = 0;
	for (int i = 0; i < N; i++) {

		cout << "i: " << i << endl;	//테스트용

		if (S.empty()) {
			S.push(make_pair(hist[i], 1));
			cout << "스택 빔 " << endl;	//테스트용
			cout << "S.top(): " << S.top().first << ", " << S.top().second << endl;	//테스트용
		}
		else {
			//스택의 top이 현재 높이보다 크면 계속 pop함
			int width = 0;
			while (!S.empty() && S.top().first > hist[i]) {
				cout << "whileS.top(): " << S.top().first << ", " << S.top().second << endl;	//테스트용
				pair<int, int> p1 = S.top();
				S.pop();
				//largest갱신
				cout << "while p1: " << p1.first << ", " << p1.second << endl;	//테스트용
				if (p1.first * p1.second > largest) largest = p1.first * p1.second;
				//top의 너비 갱신
				cout << "largest: " << largest << endl;	//테스트용
				width = p1.second;
				cout << "width" << width << endl;	//테스트용
				if (!S.empty()) {
					pair<int, int> p2 = S.top();
					S.pop();
					p2.second += width;
					S.push(p2);
				}
				cout << "while문 끝" << endl;	//테스트용
			}

			if (!S.empty()) cout << "ㅇㅅㅇS.top(): " << S.top().first << ", " << S.top().second << endl;	//테스트용
			else cout << "스택빔" << endl;	//테스트용

			if (!S.empty() && S.top().first == hist[i]) {	//스택의 top이 현재 높이와 같다면
				pair<int, int> p = S.top();
				S.pop();
				p.second++;
				S.push(p);
			}
			else {	//스택의 top이 현재 높이보다 작다면
				S.push(make_pair(hist[i], width + 1));
			}

			cout << "S.top(): " << S.top().first << ", " << S.top().second << endl;	//테스트용
		}

		cout << endl << endl;	//테스트용
	}

	cout << "비워주기" << endl;	//테스트용

	//스택 비워주기
	while (!S.empty()) {
		pair<int, int> p1 = S.top();
		S.pop();
		//largest갱신
		if (p1.first * p1.second > largest) largest = p1.first * p1.second;
		//top의 너비 갱신
		int width = p1.second;
		//cout << "width" << width << endl;	//테스트용
		if (!S.empty()) {
			pair<int, int> p2 = S.top();
			S.pop();
			p2.second += width;
			S.push(p2);
		}
	}

	cout << largest;

	return 0;
}