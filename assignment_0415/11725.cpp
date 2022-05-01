//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <vector>

using namespace std;

//인접 노드
vector<vector<int>> adj_list;
//부모 노드
vector<int> parent;

//dfs 탐색 함수
void dfs_recursion(int prev, int curr) {
    //만약 부모 노드가 있다면 return
    if (parent[curr]) {
        return;
    }
    //현재 노드의 부모를 이전노드로 설정
    parent[curr] = prev;
    for (int i = 0; i < adj_list[curr].size(); i++) {
        //dfs 탐색
        dfs_recursion(curr, adj_list[curr][i]);
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {
    int n, a, b;

    //입력
    cin >> n;
    //인접 노드, 부모 노드 선언
    adj_list.assign(n + 1, vector<int>(0));
    parent.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        //입력 받은 값 벡터에 저장
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {
        //부모 노드 출력
        cout << parent[i] << '\n';
    }
    return 0;
}
