//
// Created by r4356 on 2022-03-27.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w, i, i_e, t, d, a, g_1, g_2;
    cin >> w >> i >> t;
    cin >> d >> i_e >> a;

    int w_1 = w;
    int w_2 = w;

    int i_2 = i;

    while(d--) {
        //첫번째 줄 출력 위한 연산
        g_1 = (i_e - (i + a));
        w_1 += g_1;
        //두번째 줄 출력 위한 연산
        g_2 = (i_e - (i_2 + a));
        w_2 += g_2;
        if ((abs(g_2)) > t) {
            i_2 += floor(g_2/2.0);
        }
    }

    //첫번째 줄
    if(w_1 <= 0) {
        cout << "Danger Diet" << '\n';
    }
    else {
        cout << w_1 << " " << i << " " << '\n';
    }

    //두번째 줄
    if(w_2 <= 0 || i_2 <= 0) {
        cout << "Danger Diet" << '\n';
    }

    else {
        cout << w_2 << " " << i_2 << " ";

        if(i > i_2) {
            cout << "YOYO";
        }
        else {
            cout << "NO";
        }
    }

}
