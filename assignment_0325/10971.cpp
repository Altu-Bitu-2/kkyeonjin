//
<<<<<<< Updated upstream
// Created by r4356 on 2022-03-30.
=======
// Created by r4356 on 2022-04-01.
>>>>>>> Stashed changes
//
#include <iostream>

using namespace std;
const int SIZE = 10;
int n;
int w[SIZE][SIZE];
bool check[SIZE];
int answer = 10000001;

void backtracking(int start, int cnt, int money) {

<<<<<<< Updated upstream
    if(cnt == n ) {
        if(w[start][0] != 0) {
            money += w[start][0];
        }
        answer = min(answer, money);
=======
    if(money >= answer) {
        return;
    }

    if(cnt == n) {
        if(w[start][0] != 0) {
            money += w[start][0];
            answer = min(answer, money);
        }
>>>>>>> Stashed changes
        return;
    }

    for(int i = 0; i < n; i++) {
        if(check[i] == false && w[start][i] != 0) {
            money += w[start][i];
            check[i] = true;
            backtracking(i, cnt+1, money);
<<<<<<< Updated upstream
=======
            money -= w[start][i];
>>>>>>> Stashed changes
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

    check[0] = true;
    backtracking(0, 1, 0);

    cout << answer;
}
