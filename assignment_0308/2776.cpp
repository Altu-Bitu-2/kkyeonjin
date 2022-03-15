//
// Created by r4356 on 2022-03-13.
//
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_set<int> note1;

    int t, m, n, num;
    cin >> t;
    while(t--) {
        cin >> n;

        while(n--) {
            cin >> num;
            note1.insert(num);
        }
        cin >> m;
        while (m--) {
            cin >> num;
            cout << note1.count(num) << '\n';
        }
        note1.clear();
    }

}




