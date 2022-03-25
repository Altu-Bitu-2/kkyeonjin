//
// Created by r4356 on 2022-03-24.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//next_permutation 사용 위한 temp 설정
void setTemp(int temp[], int n) {
    temp[0] = 1;
    temp[1] = 1;
    temp[2] = 1;
    for(int i = 3; i < n; i++){
        temp[i] = 0;
    }
}

int getAnswer(int cards[], int temp[], int m, int n) {
    int sum = 0;
    int answer = 0;
    int index;
    vector<int> sums;
    //조합을 구해 조합의 합을 구한다
    do{
        for(int i = 0; i < n; i++) {
            if(temp[i] == 1){
                sum += cards[i];
            }
        }
        sums.push_back(sum);

        sum = 0;
    } while (prev_permutation(temp, temp+n));

    //m과 차이가 가장 적은 수를 찾는다
    for(int i = 0; i < sums.size(); i++) {
        if(sums[i] <= m && sums[i] > answer) {
            answer = sums[i];
        }
    }
    return answer;
}


int main() {
    int n, m, num;
    cin >> n >> m;
    int cards[n];
    int temp[n];
    setTemp(temp, n);
    for(int i = 0; i < n; i++) {
        cin >> num;
        cards[i] = num;
    }

    sort(cards, cards+n);

    cout << getAnswer(cards, temp, m, n);

}

