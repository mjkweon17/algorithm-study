#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
int vowel_used;
int consonant_used;
char alpha[16];
string str[16];
int index;

void init() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
}

void func(int k) {
	if (k == L) {
		if (vowel_used && consonant_used >= 2) {
			for (int i = 0; i < L; i++) {
				cout << str[i];
			}
			cout << '\n';
		}
		return;
	}

	if (k < L - (C - index)) return;
	//����
	str[k] = alpha[index];
	if (alpha[index] == 'a' || alpha[index] == 'e' || alpha[index] == 'i'
		|| alpha[index] == 'o' || alpha[index] == 'u') {
		vowel_used++;
	}
	else {
		consonant_used++;
	}
	index++;
	func(k + 1);
	index--;
	if (alpha[index] == 'a' || alpha[index] == 'e' || alpha[index] == 'i'
		|| alpha[index] == 'o' || alpha[index] == 'u') {
		vowel_used--;
	}
	else {
		consonant_used--;
	}

	if(k - 1 < L - (C - index)) return;

	index++;
	func(k);
	index--;
}

int main(void) {

	init();

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	sort(alpha, alpha + C - 1);

	func(0);

	return 0;
}