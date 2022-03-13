//
// Created by r4356 on 2022-03-14.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string file, name, type;
    map<string, int> list;
    cin >> n;
    while(n--) {
        cin >> file;
        type = file.substr(file.find('.')+1);
        if(list.count(type) == 0)
            list[type] = 1;
        else
            list[type]++;
    }
    map<string, int>::iterator iter;
    for(iter = list.begin(); iter != list.end(); iter++){
        cout << iter->first << " " << iter->second << '\n';
    }

}


