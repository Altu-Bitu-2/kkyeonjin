//
// Created by r4356 on 2022-05-01.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
//세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    //하나의 용액을 고정하고 남은 용액들에 투포인터 적용
    pair<ll, ll> ans;
    ans = make_pair(INF, INF);

    //left는 항상 right의 왼쪽에 있게 한다
    while (left < right) {
        //용액 섞기
        ll mix = fixed + arr[left] + arr[right];
        if (mix == 0) {
            //용액 값이 0인 경우 return한다
            return make_pair(arr[left], arr[right]);
        }
        //0에 더 가까운 값이 나오는 경우라면 min_diff와 ans 갱신
        if (abs(mix) < min_diff) {
            min_diff = abs(mix);
            ans = make_pair(arr[left], arr[right]);
        }
        //0보다 큰 경우는 용액값을 더 작게 만들기 위해 포인터 이동
        if (mix > 0) {
            //오른쪽 1감소(이동)
            right--;
        } else {
            //왼쪽 1증가(이동)
            left++;
        }
    }
    //
    return ans;
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n;

    //입력
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end());//용액값 정렬
    //3개 용액의 값 저장하는 tuple 선언
    tuple<ll, ll, ll> ans;
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second);
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}
