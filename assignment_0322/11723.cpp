//
// Created by r4356 on 2022-03-27.
//
#include <iostream>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x;
    //인덱스와 bool 값으로 집합 상태 표현
    bool s[21];
    //처음 상태는 공집합(전부 false)
    fill_n(s+1, 20, false);
    string op;
    cin >> m;
    while(m--) {
        cin >> op;
        if(op == "add") {
            cin >> x;
            s[x] = true;
        }
        else if(op == "remove") {
            cin >> x;
            s[x] = false;
        }
        else if(op == "check") {
            cin >> x;
            if(s[x] == true) {
                cout << 1 << '\n';
            }
            else
                cout << 0 << '\n';
        }
        else if(op == "toggle") {
            cin >> x;
            if(s[x] == true) {
                s[x] = false;
            }
            else
                s[x] = true;
        }
        else if (op == "all") {
            fill_n(s+1, 20, true);
        }
        else if (op == "empty") {
            fill_n(s+1, 20, false);
        }
    }

}

