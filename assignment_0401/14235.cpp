//
// Created by r4356 on 2022-04-08.
//
#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n;
    //n만큼 반복
    while (n--) {
        cin >> a;
        if (!a) { //아이들을 만난 경우
            //pq가 비어있어 줄 선물이 없다면 1 출력
            if (pq.empty()) {
                cout << "-1\n";
            } else {
                //비어있지 않다면 가장 가치가 큰 것을 출력
                cout << pq.top() << '\n';
                //삭제
                pq.pop();
            }
        } else { //선물을 충전하는 경우
            //a만큼 반복
            while (a--) {
                //선물의 가치 입력받음
                cin >> input;
                //pq에 삽입
                pq.push(input);
            }
        }
    }
    return 0;
}
