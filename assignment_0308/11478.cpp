//
// Created by r4356 on 2022-03-13.
//
#include <set>
#include <iostream>

using namespace std;

int main() {

    string s;
    set<string> strings;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        for(int j=1; j <= s.length()-i; j++)
            strings.insert(s.substr(i, j));

    }

    cout << strings.size() << '\n';
}

