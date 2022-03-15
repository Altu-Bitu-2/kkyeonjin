//
// Created by r4356 on 2022-03-13.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> ii;

bool cmp(ii &a, ii &b) {
    if(a.second != b.second)
        return a.second > b.second;
    else if(a.first.length() != b.first.length())
        return a.first.length() > b.first.length();
    else
        return a < b;
}

int main() {
    int n, m;
    string word;
    map<string, int> list;
    cin >> n >> m;
    for (int i = 0; i<n; i++) {
        cin >> word;
        if(word.length() >= m) {
            list[word]++;
        }
    }

    vector<ii> arr(list.begin(), list.end());

    sort(arr.begin(), arr.end(), cmp);


    for(ii it : arr){
        cout << it.first << '\n';
    }

}
