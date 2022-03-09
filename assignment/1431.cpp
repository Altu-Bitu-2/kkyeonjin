//
// Created by r4356 on 2022-03-10.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string s) {
    int sum = 0;

    for (int i =0; i<s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            sum += s[i] - '0';
    }
    return sum;
}

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    else if (a.length() == b.length()) {
        if (sum(a) != sum(b)){
            return sum(a) < sum(b);
        }
        else
            return a < b;
    }

}

int main() {
    int n;
    cin >> n;
    vector<string> serial(n);

    for (int i = 0; i < n; i++) {
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << serial[i] << "\n" ;
    }
    return 0;
}
