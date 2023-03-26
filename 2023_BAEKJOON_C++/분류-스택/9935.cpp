#include <iostream>
#include <string>
using namespace std;

void init() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    string str, bomb;
    cin >> str >> bomb;

    char ans[1000001];
    int ans_len = 0;
    int bomb_len = bomb.length();

    for (int i = 0; i < str.length(); i++) {
        ans[ans_len] = str[i];
        ans_len++;

        if (ans_len >= bomb_len && ans[ans_len - 1] == bomb[bomb_len - 1]) {
            bool del = true;
            for (int j = 0; j < bomb_len; j++) {
                if (ans[ans_len - bomb_len + j] != bomb[j]) {
                    del = false;
                    break;
                }
            }
            if (del) ans_len -= bomb_len;
        }
    }

    if (ans_len == 0) {
        cout << "FRULA";
    }
    else {
        for (int i = 0; i < ans_len; i++) {
            cout << ans[i];
        }
    }
    cout << "\n";

    return 0;
}