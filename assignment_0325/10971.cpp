//
// Created by r4356 on 2022-03-30.
//
#include <iostream>

using namespace std;
const int SIZE = 10;
int n;
int w[SIZE][SIZE];
bool check[SIZE];
int money = 0;
int cnt = n;
int m = 10000001;

void backtracking(int start, int cnt) {

    if(cnt == 0) {
        if(m > money) {
            m = money;
            return;
        }
    }

    for(int i = 0; i < n; i++) {
        if(check[i] == false && start != i && w[start][i] != 0) {
            money += w[start][i];
            check[i] = true;
            backtracking(i, cnt-1);
            check[i] = false;
        }
    }

}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    backtracking(0, n);

    cout << m;
}
