//
// Created by r4356 on 2022-03-09.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
    int x, y;
};

bool cmp(const point &a, const point &b) {

    if (a.y != b.y) {
        return a.y < b.y;
    }
    if (a.x != b.x) {
        return a.x < b.x;
    }
}

int main() {
    int n;
    cin >> n;
    vector <point> list(n);

    for (int i = 0; i < n; i++) {
        cin >> list[i].x >> list[i].y;
    }

    sort(list.begin(), list.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << list[i].x << " " << list[i].y << '\n';
    }
    return 0;

}
