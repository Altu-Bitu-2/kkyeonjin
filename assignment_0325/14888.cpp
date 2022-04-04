//
// Created by r4356 on 2022-03-31.
//
#include <iostream>
#include <vector>

using namespace std;
//연산 최대값
const int INF_MAX = 1e9;
const int SIZE = 11;

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        //식 결과 최대값 max_value에 저장
        max_value = max(max_value, sum);
        //식 결과 최소값 min_value에 저장
        min_value = min(min_value, sum);
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        //연산자가 존재하는 경우 식 계산
        if (expression[i]) {
            //연산자 사용할 예정이니 연산자 수 1 감소
            expression[i]--;
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
                //'+' 연산자인 경우 덧셈 연산
                case 0:
                    new_sum = sum + num[cnt + 1];
                    break;
                //'-' 연산자인 경우 뺄셈 연산
                case 1:
                    new_sum = sum - num[cnt + 1];
                    break;
                //'*' 연산자인 경우 곱셈 연산
                case 2:
                    new_sum = sum * num[cnt + 1];
                    break;
                //'/' 연산자인 경우 나눗셈 연산
                case 3:
                    new_sum = sum / num[cnt + 1];
                    break;
            }
            //다음 수 연산 위해 함수 호출
            backtracking(cnt + 1, new_sum);
            //다시 돌아왔을 때 원래 상태로 돌려놓음
            expression[i]++;
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}