//
// Created by r4356 on 2022-03-21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

int main() {

    string num_string;
    cin >> num_string;
    vector<int> num;
    int sum = 0;

    //입력한 문자열(슷자) 한 자리로 분해 후 벡터에 삽입
    for(int i=0; i<num_string.length(); i++) {
        num.push_back((num_string[i])-'0');
    }


    for (int i = 0; i < num.size(); i++) {
        sum += num[i];
    }

    //각 자릿수 합이 3의 배수가 아닌 경우, 입력한 숫자에 0이 포함되지 않은 경우 -1 출력
    if(find(num.begin(), num.end(), 0) == num.end() || sum % 3 != 0) {
        cout << -1 ;
    }

    //내림차순 정렬 (가장 큰 30의 배수 출력 위해) 후 출력
    else {
        sort(num.begin(), num.end(), greater<>());
        for (int i = 0; i < num.size(); i++) {
            cout << num[i];
        }
    }
}


