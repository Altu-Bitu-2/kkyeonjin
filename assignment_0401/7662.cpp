//
// Created by r4356 on 2022-04-08.
//
#include <iostream>
#include <set>

using namespace std;

/**
 * set 풀이
 *
 * set은 중복값이 제거되기 때문에 multiset을 이용하여 저장해야 함
 * multiset 또한 값을 넣으면 정렬이 바로 되기 때문에 이후의 정렬 과정이 따로 필요 없음
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, n;
    //연산 나타내는 문자
    char cmd;

    cin >> t;
    //테스트 데이터 수 만큼 반복
    while (t--) {
        multiset<int> ms; //중복 저장
        cin >> k;
        //연산 개수 만큼 반복
        while (k--) {
            //입력
            cin >> cmd >> n;

            //연산
            switch (cmd) {
                case 'I': //I 연산
                    //n set에 삽입
                    ms.insert(n);
                    break;
                case 'D': //D 연산
                    if (ms.empty()) { //ms가 비어있다면 연산 무시
                        break;
                    }
                    if (n == 1) { //최댓값 삭제
                        //맨 마지막에 있는 값(최댓값 삭제)
                        ms.erase(--ms.end());
                    }
                    if (n == -1) { //최솟값 삭제
                        //맨 앞에 있는 값(최솟값) 삭제
                        ms.erase(ms.begin());
                    }
                    break;
            }
        }

        //출력
        //set이 비어있다면 EMPTY 출력
        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }
}