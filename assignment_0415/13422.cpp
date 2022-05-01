//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0;
    //연속해서 훔쳐야 할 집 m만큼 반복
    for (int i = 0; i < m; i++) {
        //훔친 돈 합침
        money += house[i];
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        //결과 값 리턴
        return ans;
    }
    for (int i = m; i < n + m - 1; i++) {
        //모듈러 연산으로 윈도우의 양 끝 위치 조절
        money -= house[i - m];
        money += house[i % n];
        //예외처리
        //훔친 돈 합이 k 보다 작으면
        if (money < k) {
            //ans 증가
            ans++;
        }
    }
    return ans;
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0);
        for (int i = 0; i < n; i++) {
            //벡터에 입력 값 저장
            cin >> house[i];
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}
