#include <iostream>
#include <stack>
using namespace std;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int seq[1000001];	//������ ������ �迭
int num[1000001];	//Ư�� ���ڰ� ������ �����ϴ� Ƚ���� ������ �迭
int ans[1000001];	//������ ������ �迭

int main(void) {

	init();

	int N;	//������ ũ��
	cin >> N;

	for (int i = 1; i <= N; i++) {	
		cin >> seq[i];	//������ ���� ����
		num[seq[i]]++;	//�Է¹��� ���� ������ �ִ� ���� ������Ʈ
	}

	stack<int> S;	//���� ���� �����ʺ��� �ϳ��� ������Ʈ
	for (int i = N; i > 0; i--) {

		while (!S.empty() && num[S.top()] <= num[seq[i]]) {
			S.pop();
		}

		if (S.empty()) {	//������ ��������� ans�� -1
			ans[i] = -1;
		}
		else {	//������ ������� �ʴٸ�
			ans[i] = S.top();
		}

		//���ÿ� push
		S.push(seq[i]);
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}