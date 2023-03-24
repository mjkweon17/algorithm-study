#include <iostream>

void add_cardset(int* arr, int* cardset);

int main(void) {

	int card[10] = { 0, };

	int cardset = 0;

	int N;
	std::cin >> N;

	int temp;
	int exist;	//카드 존재 여부

	while (true) {

		exist = 0;
		temp = N % 10;

		//카드 존재하는지 확인
		if (card[temp]) {
			card[temp]--;
			exist = 1;
		}

		if (!exist) {	//카드 존재하지 않는데 카드가 6이나 9면
			if (temp == 6 || temp == 9) {
				if (card[6]) {
					card[6]--;
					exist = 1;
				}
				if (card[9]) {
					card[9]--;
					exist = 1;
				}
			}
		}

		if (!exist) {	//그래도 카드가 없으면 카드셋 추가
			add_cardset(card, &cardset);
		}

		if (!exist) {
			if (card[temp]) {
				card[temp]--;
			}
		}

		N /= 10;
		if (!N) {
			break;
		}
	}

	std::cout << cardset;

	return 0;
}

void add_cardset(int* arr, int* cardset) {
	for (int i = 0; i < 10; i++) {
		arr[i]++;
	}
	(*cardset)++;
}