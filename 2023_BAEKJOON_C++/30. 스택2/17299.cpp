#include <iostream>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int seq[1000001];	//수열을 저장할 배열
int num[1000001];	//특정 숫자가 수열에 존재하는 횟수를 저장할 배열
int ans[1000001];	//정답을 저장할 배열

int main(void) {

	init();

	int N;	//수열의 크기
	cin >> N;

	for (int i = 1; i <= N; i++) {	
		cin >> seq[i];	//수열에 원소 저장
		num[seq[i]]++;	//입력받은 수가 수열에 있는 개수 업데이트
	}

	stack<int> S;	//스택 만들어서 오른쪽부터 하나씩 업데이트
	for (int i = N; i > 0; i--) {

		while (!S.empty() && num[S.top()] <= num[seq[i]]) {
			S.pop();
		}

		if (S.empty()) {	//스택이 비어있으면 ans에 -1
			ans[i] = -1;
		}
		else {	//스택이 비어있지 않다면
			ans[i] = S.top();
		}

		//스택에 push
		S.push(seq[i]);
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}