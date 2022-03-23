//
// Created by r4356 on 2022-03-24.
//
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int r, b;
    cin >> r >> b;
    int total = r+b;
    map<int, int> possible;

    // 총 타일 갯수의 약수를 찾고, 약수와 몫을 map에 저장(L과 W 차례대로)
    for(int i = 1; i <= sqrt(total); i++) {
        if((total % i) == 0 ) {
            possible[total/i] = i;
        }
    }
    //(L-2)*(W-2)가 안 쪽 갈색 타일의 갯수가 되므로 이를 만족하는 pair를 출력
    for(auto it : possible) {
       if (((it.first - 2) * (it.second - 2)) == b) {
           cout << it.first << ' ' << it.second;
       }
    }
}