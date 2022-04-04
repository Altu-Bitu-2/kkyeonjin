//
// Created by r4356 on 2022-03-30.
//
#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> ii;
deque<ii> belt;
int n;
int stage = 0;

//내구도 0인 칸의 개수 check
int check() {
    int cnt = 0;
    for(int i = 0; i < belt.size(); i++) {
        if(belt[i].first == 0) {
            cnt++;
        }
    }
    return cnt;
}

void rotate() {
    //한 칸 회전

    ii temp = belt.back();
    belt.pop_back();
    belt.push_front(temp);

    //내리는 위치 도달하면 로봇 내리기
    belt[n-1].second = 0;

}

void move() {

//로봇 이동할 수 있으면 이동
    for (int i = n - 2; i >= 0; i--) {
        if (belt[i].second == 1 && belt[i + 1].first > 0 && belt[i + 1].second == 0) {
            belt[i].second = 0;
            belt[i + 1].second = 1;
            belt[i + 1].first -= 1;
        }
    }
    //내리는 위치 도달하면 로봇 내리기
    belt[n - 1].second = 0;
}

void onBelt() {

    //올리는 위치에 올리기
    if(belt[0].first > 0 && belt[0].second == 0) {
        belt[0].first -= 1;
        belt[0].second = 1;
    }
}

int main() {

    int k, a;
    cin >> n >> k;
    for(int i = 0; i < 2*n; i++) {
        cin >> a;
        belt.push_back(ii(a, 0));
    }

    //내구도 0인 칸이 k개 이상이면 while탈출
    while(check() < k) {
        ++stage;
        rotate();
        move();
        onBelt();
    }

    cout << stage;

}
