//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    //left는 항상 right의 왼쪽에 있게 한다
    while (left < right) {
        //현재 만드려는 수의 위치와 left 포인터 위치가 겹칠 경우
        if (left == idx) {
            //left 포인터 이동
            left++;
            continue;
        }
        //현재 만드려는 수의 위치와 right 포인터 위치가 겹칠 경우
        if (right == idx) {
            //right 포인터 이동
            right--;
            continue;
        }

        //두 수를 더해 현재 수를 만들 수 있다면 true 리턴
        if (num[left] + num[right] == num[idx]) {
            return true;
        }
        //더한 값이 현재 수보다 더 크다면
        if (num[left] + num[right] > num[idx]) {
            //right 감소
            right--;
        } else {
            //left 증가
            left++;
        }
    }
    //불가하다면 false 리턴
    return false;
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0;

    //입력
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        //배열에 입력한 수 저장
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.end());//값 정렬
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i)) {
            //좋은 수라면(return 값 true) ans 1증가 시킴
            ans++;
        }
    }

    //출력
    cout << ans;
    return 0;
}
