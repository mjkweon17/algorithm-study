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

	int N;	//������׷��� ���� ĭ ��
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hist[i];
	}

	stack<pair<int, int>> S;	//<����, �ʺ�>
	int largest = 0;
	for (int i = 0; i < N; i++) {

		cout << "i: " << i << endl;	//�׽�Ʈ��

		if (S.empty()) {
			S.push(make_pair(hist[i], 1));
			cout << "���� �� " << endl;	//�׽�Ʈ��
			cout << "S.top(): " << S.top().first << ", " << S.top().second << endl;	//�׽�Ʈ��
		}
		else {
			//������ top�� ���� ���̺��� ũ�� ��� pop��
			int width = 0;
			while (!S.empty() && S.top().first > hist[i]) {
				cout << "whileS.top(): " << S.top().first << ", " << S.top().second << endl;	//�׽�Ʈ��
				pair<int, int> p1 = S.top();
				S.pop();
				//largest����
				cout << "while p1: " << p1.first << ", " << p1.second << endl;	//�׽�Ʈ��
				if (p1.first * p1.second > largest) largest = p1.first * p1.second;
				//top�� �ʺ� ����
				cout << "largest: " << largest << endl;	//�׽�Ʈ��
				width = p1.second;
				cout << "width" << width << endl;	//�׽�Ʈ��
				if (!S.empty()) {
					pair<int, int> p2 = S.top();
					S.pop();
					p2.second += width;
					S.push(p2);
				}
				cout << "while�� ��" << endl;	//�׽�Ʈ��
			}

			if (!S.empty()) cout << "������S.top(): " << S.top().first << ", " << S.top().second << endl;	//�׽�Ʈ��
			else cout << "���ú�" << endl;	//�׽�Ʈ��

			if (!S.empty() && S.top().first == hist[i]) {	//������ top�� ���� ���̿� ���ٸ�
				pair<int, int> p = S.top();
				S.pop();
				p.second++;
				S.push(p);
			}
			else {	//������ top�� ���� ���̺��� �۴ٸ�
				S.push(make_pair(hist[i], width + 1));
			}

			cout << "S.top(): " << S.top().first << ", " << S.top().second << endl;	//�׽�Ʈ��
		}

		cout << endl << endl;	//�׽�Ʈ��
	}

	cout << "����ֱ�" << endl;	//�׽�Ʈ��

	//���� ����ֱ�
	while (!S.empty()) {
		pair<int, int> p1 = S.top();
		S.pop();
		//largest����
		if (p1.first * p1.second > largest) largest = p1.first * p1.second;
		//top�� �ʺ� ����
		int width = p1.second;
		//cout << "width" << width << endl;	//�׽�Ʈ��
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