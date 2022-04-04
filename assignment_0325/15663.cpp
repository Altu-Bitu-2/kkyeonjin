//
// Created by r4356 on 2022-03-29.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;

int n, m, num;
vector<int> nums(n);
vector<int> result(SIZE);
vector<bool> check(SIZE);

void backtracking(int cnt) {

    if (cnt == m) {
        for(int i = 0; i < cnt; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    //중복수열 피하기 위해 temp변수 사용
    int temp = 0;

    for (int i = 0; i < nums.size(); i++) {
        //이전에 사용한 값(temp)값과 사용하려는 수가 다른 경우에만 result 배열에 삽입
        if(!check[i] && temp != nums[i]) {
            result[cnt] = nums[i];
            temp = nums[i];
            check[i] = true;
            backtracking(cnt + 1);
            check[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;

    while(n--) {
        cin >> num;
        nums.push_back(num);
    }
    //입력받은 수 정렬
    sort(nums.begin(), nums.end());
    backtracking(0);
    return 0;
}

