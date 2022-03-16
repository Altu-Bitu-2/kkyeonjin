//
// Created by r4356 on 2022-03-17.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool isPossible(map<char, int> &a) {
    map<char, int>:: iterator it;
    int cnt = 0;
    for(it = a.begin(); it != a.end(); it++) {
        if(it->second % 2 == 1)
            cnt++;
    }

    if(cnt > 1)
        return false;
    else
        return true;
}

void makePalindrome(map<char, int> &a) {
    int cnt = 0;
    char temp;
    map<char, int>::iterator it;
    string output = "";

    for (it = a.begin(); it != a.end(); it++) {
        if (it->second % 2 == 1) {
            cnt++;
            temp = it->first;
        }
    }

    for (it = a.begin(); it != a.end(); it++) {
        for (int j = 0; j < it->second / 2; j++)
            output += it->first;
    }

    for (int i = 0; i < output.size(); i++)
        cout << output[i];
    reverse(output.begin(), output.end());

    if(cnt == 1)
        cout << temp;

    for (int i = 0; i < output.size(); i++)
        cout << output[i];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    map<char, int> arr;
    cin >> input;
    int size = input.size();
    for(int i=0; i < size; i++){
        arr[input[i]]++;
    }

    if(input.length() == 1)
        cout << input;

    else {
        if(isPossible(arr)) {
            makePalindrome(arr);
        }
        else
            cout << "I'm Sorry Hansoo" ;
    }

}