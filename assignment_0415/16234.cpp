//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited;
//좌표 큐
queue<ci> countries;


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    //연합 인구 수 만큼 반복
    for (int i = 0; i < union_cord.size(); i++) {
        int row = union_cord[i].first, col = union_cord[i].second;
        //인구 수 저장 (인구 이동)
        board[row][col] = population;
        countries.push({row, col}); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc});
    queue<ci> q;
    //좌표 큐에 나라 저장
    q.push({cr, cc});
    //cnt는 1로 초기화
    int sum = board[cr][cc], cnt = 1;
    //q가 비어있지 않을 때 까지 반복
    while (!q.empty()) {
        //첫번째, 두번째 원소 값 저장
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) {
                continue;
            }
            //국경선 공유하는 두 나라의 인구 차이
            int diff = abs(board[nr][nc] - board[cr][cc]);
            //국경선 공유하는 두 나라의 인구 차이 l명 이상 r명 이하
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc});
                visited[nr][nc] = day;
                union_cord.push_back({nr, nc}); //연합에 추가
                sum += board[nr][nc];
                cnt++;
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true;
    }
    return false;
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) {
        day++;
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) {
            //가로, 세로에 나라 저장
            int row = countries.front().first;
            int col = countries.front().second;
            countries.pop();
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue;
            }
            visited[row][col] = day;
            //방문 체크 후 bfs 탐색함
            if (bfs(n, l, r, row, col, day)) {
                is_move = true;
            }
        }
        if (!is_move) {
            return day - 1;
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    int n, l, r;

    //입력
    cin >> n >> l >> r;
    board.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //나라별 인구 수 입력 받음
            cin >> board[i][j];
            countries.push({i, j});
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);
    return 0;
}
