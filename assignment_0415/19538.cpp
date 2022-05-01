//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q;

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        //초기화
        ans[init[i]] = 0;
        //q에 값 넣기
        q.push(init[i]);
    }

    //루머 믿어야 하는 주변인 수 초기화
    for (int i = 1; i <= n; i++) {
        //최소 주변인 수를 계산해 rest에 넣음
        rest[i] = (people[i].size() + 1) / 2;
    }

    //q가 비어있지 않을 때 까지
    while (!q.empty()) {
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        //현재 값 pop
        q.pop();

        for (int i = 0; i < people[curr].size(); i++) {
            int next = people[curr][i];
            if (ans[next] > -1) { //이미 루머를 믿는 다면
                //반복문 계속해서 진행
                continue;
            }
            //남아있는 사람의 수 감소
            rest[next]--;
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                //시간에 + 1
                ans[next] = t + 1;
                //q에 next 추가
                q.push(next);
            }
        }
    }
    //ans 리턴
    return ans;
}

/**
 * [루머]
 *
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
 *    ans[i] = -1 일 경우, i는 루머를 믿지 않는다
 *    ans[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
 * 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
 * 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
 */

int main() {
    int n, m, input;

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    //사람 저장할 벡터
    vector<vector<int>> people(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input;
            //입력이 공백인 경우 break
            if (!input) {
                break;
            }
            //입력 값 벡터에 삽입
            people[i].push_back(input);
        }
    }

    //최초 유포자 입력
    cin >> m;
    //유포자 저장하는 배열 선언
    vector<int> init(m, 0);
    for (int i = 0; i < m; i++) {
        //배열에 입력 값 저장
        cin >> init[i];
    }

    //연산
    vector<int> ans = bfs(people, init, n);

    //출력
    for (int i = 1; i <= n; i++) {
        //루머를 믿기 시작한 시간을 출력함
        cout << ans[i] << ' ';
    }
    return 0;
}
