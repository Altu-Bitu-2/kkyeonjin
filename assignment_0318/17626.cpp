//
// Created by r4356 on 2022-03-24.
//
#include <iostream>

using namespace std;

int main() {

    int list[225];

    // 자연수의 제곱수들 중 50000이하의 수들을 배열에 저장
    for(int i = 1; i <= 224; i++) {
        list[i] = i*i;
    }

    int n;
    cin >> n;

    //n이 제곱수면 1 출력
   for(int i = 0; i <= 224; i++) {
        if (list[i] == n) {
            cout << 1;
            return 0;
        }
    }

   // 제곱수 2개로 표현가능한지 판단
    for (int i = 1; i <= 224; i++) {
        for (int j = 0; j <= 224; j++) {
            if (list[i] + list[j] == n) {
                cout << 2;
                return 0;
            }
        }
    }

    //제곱수 3개로 표현가능한지 판단
    for(int i = 1; i <= 224; i++) {
        for(int j = 0; j <= 224; j++){
            for(int k = 0; k <= 224; k++) {
                if(list[i] + list[j] + list[k] == n) {
                    cout << 3;
                    return 0;
                }
            }
        }
    }

    //위의 세 경우 모두 아니면 4 출력
    cout << 4;

}
