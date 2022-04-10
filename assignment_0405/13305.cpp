//
// Created by r4356 on 2022-04-10.
//
#include <iostream>

using namespace std;
int n;
long long price[100000];
long long dist[100000];

int solve() {
    long long sum = 0;
    //리터당 가격은 1000000000 이하
    long long cheaper_price = 1000000001;

    for(int i = 0; i < n; i++) {
        if(price[i] < cheaper_price) {
            sum += price[i] * dist[i+1];
            cheaper_price = price[i];
        }
        else {
            sum += cheaper_price * dist[i+1];
        }
    }

    return sum;
}

int main() {
    cin >> n;

    for(int i = 1; i < n; i++) {
        cin >> dist[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << solve();

}
