//
// Created by r4356 on 2022-03-13.
//
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, e, q, time, name;
    int cnt = 0;
    unordered_set<string> chat_in, chat_out;
    cin >> s >> e >> q;

    while(!cin.eof()) {

        cin >> time >> name;
        if ( time >= "00:00" && time <= s){
            chat_in.insert(name);
        }

        else if(time>=e && time <= q){
            if(chat_in.count(name) == 1 )
                chat_out.insert(name);
        }
    }

    cout << chat_out.size() ;

}
