//
// Created by r4356 on 2022-04-08.
//
#include <iostream>
#include <deque>

using namespace std;

//deque에 있는 값들을 string으로 바꾸는 함수
string dqToString(deque<char> &dq) {
    string ans = "";
    //비어있지 않을 때 까지
    while (!dq.empty()) {
        //deque앞에 있는 값을 문자열에 더하고 pop한다
        ans += dq.front();
        dq.pop_front();
    }
    //string ans 리턴
    return ans;
}

string findPass(string s) {
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '-': //현재 커서 앞에 있는 글자를 지운다.
                //dq_left가 비어있지 않은 경우에만 실행
                if (!dq_left.empty()) {
                    //맨 뒤의 값 삭제
                    dq_left.pop_back();
                }
                break;
            case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                //dq_left가 비어있지 않은 경우에만 실행
                if (!dq_left.empty()) {
                    //dq_left의 마지막 원소를 dq_right의 맨 앞에 삽입
                    dq_right.push_front(dq_left.back());
                    //dq_left의 마지막 원소 삭제
                    dq_left.pop_back();
                }
                break;
            case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                //dq_right가 비어있지 않은 경우에만 실행
                if (!dq_right.empty()) {
                    //dq_right의 처음 원소를 dq_left의 맨 마지막에 삽입
                    dq_left.push_back(dq_right.front());
                    //dq_right의 첫번째 원소 삭제
                    dq_right.pop_front();
                }
                break;
            default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]);
                break;
        }
    }
    //dq_left와 dq_right를 string으로 바꿈
    string pass = dqToString(dq_left);
    pass += dqToString(dq_right);
    //비밀번호 pass 값 리턴
    return pass;
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t;
    string s;

    //입력
    cin >> t;
    //테스트 케이스 수 만큼 반복
    while (t--) {
        cin >> s;

        //연산 & 출력
        cout << findPass(s) << '\n';
    }
    return 0;
}
