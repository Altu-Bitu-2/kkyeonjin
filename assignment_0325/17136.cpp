//
// Created by r4356 on 2022-04-01.
//
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10;
const int INF = 26;

vector<vector<int>> paper(SIZE, vector<int>(SIZE));
vector<int> paper_cnt = {0, 5, 5, 5, 5, 5}; //인덱스 = 색종이 크기

bool promising(int row, int col, int paper_size) {
    for (int i = row; i < row + paper_size; i++) { //색종이 크기 만큼 돌면서 모두 1인지 확인
        for (int j = col; j < col + paper_size; j++) {
            //붙이면 안 되는 곳(0)인 곳에 색종이 붙일 경우 false 리턴
            if (paper[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

//색종이 채운 부분 구별 위한 함수
void fill_paper(int row, int col, int paper_size, int fill_value) {
    for (int i = row; i < row + paper_size; i++) {
        for (int j = col; j < col + paper_size; j++) {
            paper[i][j] = fill_value;
        }
    }
}

int backtracking(int idx, int count) { //row: 행, col: 열, count: 색종이 개수
    int ans = INF;

    if (idx == SIZE * SIZE) { //색종이 다 붙임
        return min(ans, count);
    }
    int row = idx / SIZE;
    int col = idx % SIZE;

    if (!paper[row][col]) { //0이라면 -> 색종이 안 붙이므로 넘어감
        return backtracking(idx + 1, count);
    }
    if (ans <= count) { //기존 정답이 더 작으므로 count 값 답 가능성 x
        return INF;
    }

    for (int i = 5; i >= 1; i--) { //5 ~ 1까지 색종이 다 붙여보기
        //붙일 종이가 남아 있거나, 종이를 붙였을 때 경계를 벗어나지 않는 경우만 실행
        if (row + i > SIZE || col + i > SIZE || !paper_cnt[i]) {
            continue;
        }
        //색종이가 붙은 칸으 모두 1이 적인 칸인 경우
        if (promising(row, col, i)) {
            //사용한 색종이 수 1장 감소
            paper_cnt[i]--;
            //이미 색종이를 붙인 곳에 다시 붙이지 않도록 0으로 채워줌
            fill_paper(row, col, i, 0);
            //색종이 최수 개수 구하기
            ans = min(ans, backtracking(idx + 1, count + 1));
            //다시 돌아왔을 때 원래 상태로 되돌려놓음
            paper_cnt[i]++;
            fill_paper(row, col, i, 1);
        }
    }
    return ans;
}

/**
 * 5x5 색종이부터 1x1 색종이까지 모두 붙여보기
 * -> 필요한 색종이의 "최소" 개수이므로 가장 크기가 큰 5x5부터 시작
 *
 * [가지치기]
 * - 탐색을 하다 아직 색종이를 다 붙이지 않았는데, 개수가 현재 저장된 정답보다 크다면 탐색 종료
 */

int main() {
    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> paper[i][j];
        }
    }

    //연산
    int ans = backtracking(0, 0);

    //출력
    //1을 다 덮는 게 불가능한 경우 -1 출력, 아니면 ans 출력
    cout << (ans == INF ? -1 : ans); //간단한 출력에선 삼항연산자 사용해도 가독성 좋음
    return 0;
}
