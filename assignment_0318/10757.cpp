//
// Created by r4356 on 2022-03-22.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a;
    string b;
    string A,B;
    cin >> a >> b;

    //항상 a를 더 긴 문자열이라고 놓음
    if(a.size() < b.size()) {
        swap(a, b);
    }

    //짧은 문자열의 앞에 '0'을 채워 두 문자열의 길이 맞추기
    A =  a;
    for(int i = 0; i < a.size() - b.size(); i++) {
        B += '0';
    }
    B += b;

    vector<int> result;

    int carry = 0;

    //끝에서부터 두 문자열 더하기
    for(int i = A.length() - 1; i >= 0; i--) {

        int res = (B[i] - '0') + (A[i] - '0');
        //연산 결과의 1의 자리만 result에 넣기 위해 모듈러 연산
        result.push_back((res+carry) % 10);
        carry = 0;
        //10이 넘으면 carry를 1로, carry 값은 다음 번 연산에서 더해짐
        if(res >= 10) {
            carry = 1;
        }
    }

    //루프 끝난 후 carry가 1 -> 받아올림
    if(carry == 1) {
        result.push_back(1);
    }

    //result 거꾸로 출력
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }

}
