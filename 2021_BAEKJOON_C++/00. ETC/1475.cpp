#include <iostream>

void add_cardset(int* arr, int* cardset);

int main(void) {

	int card[10] = { 0, };

	int cardset = 0;

	int N;
	std::cin >> N;

	int temp;
	int exist;	//ī�� ���� ����

	while (true) {

		exist = 0;
		temp = N % 10;

		//ī�� �����ϴ��� Ȯ��
		if (card[temp]) {
			card[temp]--;
			exist = 1;
		}

		if (!exist) {	//ī�� �������� �ʴµ� ī�尡 6�̳� 9��
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

		if (!exist) {	//�׷��� ī�尡 ������ ī��� �߰�
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