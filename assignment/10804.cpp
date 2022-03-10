//
// Created by r4356 on 2022-03-09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;


void makeList() {
    int n = 1;
    for (int i = 0; i < 20; i++) {
        list.push_back(n);
        n++;
    }
    list.push_back(NULL);
}

int main() {
    makeList();
    int a, b;

    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverse(&list[a-1], &list[b]);

    }


    for (int i = 0; i < 20; i++) {
        cout << list[i] << ' ';
    }


    return 0;
}
