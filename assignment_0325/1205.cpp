//
// Created by r4356 on 2022-03-28.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, score_t, score, p;
    vector<int> ranking;
    cin >> n >> score_t >> p;
    while(n--) {
        cin >> score;
        ranking.push_back(score);
    }

    //랭킹 리스트가 꽉 차고, 태수의 점수가 가장 낮은 점수보다 같거나 낮을 때 -1 출력
    if(ranking.size() == p && ranking[p-1] >= score_t) {
        cout << -1;
        return 0;
    }

    //태수 점수를 리스트에 포함하고 정렬
   ranking.push_back(score_t);
    sort(ranking.begin(), ranking.end(), greater<>());

    //반복문을 돌며 태수 점수와 같은 점수를 만나게 되면 등수(i+1)를 출력하고 break
   for(int i = 0; i < ranking.size(); i++) {
       if(ranking[i] == score_t) {
           cout << i+1;
           break;
       }
   }
}
