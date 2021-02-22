#include <iostream>
using namespace std;

int get_score(string str);

int main(void) {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	//ÄÉÀÌ½º
	cin >> N;

	string* result = new string[N];
	int* score = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> result[i];
	}

	for (int i = 0; i < N; i++) {
		score[i] = get_score(result[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << score[i] << '\n';
	}

	return 0;
}

int get_score(string str) {
	int total_score = 0;
	int score = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == 'O') {
			score++;
			total_score += score;
		}
		else if (str[i] == 'X') {
			score = 0;
		}
	}

	return total_score;
}