//
// Created by r4356 on 2022-04-01.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> sequence(1000);
vector<int> dp(1000);
int answer = 0;

int calc() {

    for(int i = 0; i < n; i++) {
        int max = 0;
        for(int j = 0; j < i; j++) {
            if(sequence[j] < sequence[i]) {
                if(max < dp[j]) {
                    max = dp[j];
                }
            }
        }
        dp[i] = max + 1;
        if(answer < dp[i]) {
            answer = dp[i];
        }

    }
    return answer;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    cout << calc();


}