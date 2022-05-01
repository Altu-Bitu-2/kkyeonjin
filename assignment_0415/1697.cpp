//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <queue>

using namespace std;
//최대값 상수로 설정
const int SIZE = 1e5;

//bfs 탐색 함수
int bfs(int n, int k) {
    //방문 check 배열 선언
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //큐에 좌표값 저장
    //ans 초기값 0
    int ans = 0;

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    //좌표 값 q에 push
    q.push(n);
    //q비어있지 않을 때 까지 반복
    while (!q.empty()) {
        //front값 저장 후 pop하기
        int x = q.front();
        q.pop();

        //x가 k에 도달
        if (x == k) {
            ans = check[x] - 1;
            //탐색을 종료함함
           break;
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) {
            //아직 방문 안 한 자식 노드가 있다면
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {
                //방문 체크 후 push
                check[child[i]] = check[x] + 1;
                q.push(child[i]);
            }
        }
    }
    //ans 값 리턴
    return ans;
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}
