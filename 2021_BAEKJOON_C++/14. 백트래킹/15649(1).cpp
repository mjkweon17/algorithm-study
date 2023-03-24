//��Ʈ��ŷ�� ���� �������� �ʰ� Ǭ ����
//�ϴ��� ȥ�� ������ �����غ��� 2~3�ð� ���� Ǯ�

#include <iostream>
using namespace std;

void init() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool backtracking(int arr[], int recursive, int N, int M) {
    int cur = 1;

    if (recursive != M) {
        while (cur <= N) {
            bool cur_fixed = false;  //������ ���� ���� �־����� �˻�
            while (!cur_fixed) {
                cur_fixed = true;
                for (int i = 0; i < recursive - 1; i++) {
                    if (arr[i] == cur) {
                        cur++;
                        cur_fixed = false;
                        break;
                    }
                }
            }
            if (cur > N) break;

            arr[recursive - 1] = cur;
            backtracking(arr, recursive + 1, N, M);
            cur++;
        }
    }

    else if (recursive == M) {
        while (true) {
            bool cur_fixed = false;
            while (!cur_fixed) {
                cur_fixed = true;
                for (int i = 0; i < recursive - 1; i++) {
                    if (arr[i] == cur) {
                        cur++;
                        cur_fixed = false;
                        break;
                    }
                }
            }
            if (cur > N) break;

            arr[recursive - 1] = cur;
            for (int i = 0; i < M; i++) {
                cout << arr[i] << ' ';
            }
            cout << '\n';
            cur++;
            if (cur > N) break;
        }
    }
    return true;
}

int main(void) {
    init();

    int N, M;
    cin >> N >> M;

    int* arr = new int[M];

    backtracking(arr, 1, N, M);

    return 0;
}