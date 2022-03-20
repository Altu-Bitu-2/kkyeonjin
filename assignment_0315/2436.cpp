//
// Created by r4356 on 2022-03-21.
//
#include <iostream>
#include <cmath>

using namespace std;

int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 구해야 하는 2개의 자연수를 A, B라고 했을 때, A = a*gcd, B = b*gcd, ab = lcm/gcd 를 이용 (a, b는 서로소)
    int gcd, lcm;
    int a, b, output_a, output_b;
    cin >> gcd >> lcm;
    int ab = lcm / gcd;

    // 1부터 sqrt(ab) 전까지 순회하며 ab의 약수 찾기
    for(int i = 1; i < sqrt(ab); i++) {
        if((ab % i) == 0) {
            a = i;
            b = (ab/i);
            //(a와 b가 서로소인지 판별)
            if(getGcd(a, b) == 1) {
                output_a = a;
                output_b = b;
            }
        }
    }

    cout << output_a * gcd << ' ' << output_b * gcd ;

}
