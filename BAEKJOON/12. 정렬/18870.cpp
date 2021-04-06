#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void init() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool compare0(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) < get<0>(b)) {
        return true;
    }
    else {
        return false;
    }
}

bool compare1(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<1>(a) < get<1>(b)) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {

    init();

    int N;
    cin >> N;

    vector<tuple<int, int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> get<0>(arr[i]);  //original num
        get<1>(arr[i]) = i; //index
    }

    sort(arr.begin(), arr.end(), compare0);

    int num = 0;
    get<2>(arr[0]) = num;
    for (int i = 1; i < N; i++) {
        if (get<0>(arr[i]) != get<0>(arr[i - 1])) {
            get<2>(arr[i]) = ++num;
        }
        else {
            get<2>(arr[i]) = num;
        }
    }

    sort(arr.begin(), arr.end(), compare1);
    for (int i = 0; i < N; i++) {
        cout << get<2>(arr[i]) << ' ';
    }


    return 0;
}