//
// Created by r4356 on 2022-04-11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n;
    cin >> n;
    vector<ii> classes(n);
    //우선순위 큐 사용
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < n; i++) {
        cin >> classes[i].first >> classes[i].second;
    }

    //강의 시작 순서 기준 오름차순 정렬
    sort(classes.begin(), classes.end());

    //맨 처음 시작하는 강의의 끝나는 시간 pq에 push
    pq.push(classes[0].second);

    //pq의 top값(끝나는 시간)과 강의들의 시작 시간을 차례로 비교
    for(int i = 1; i < n; i++) {
        //강의실이 더 필요한 경우
        if(pq.top() > classes[i].first) {
            pq.push(classes[i].second);
        }
        //같은 강의실 사용 가능한 경우
        else {
            pq.pop();
            pq.push(classes[i].second);
        }
    }

    //pq의 크기가 필요한 강의실의 최소 개수
    cout << pq.size();
}
