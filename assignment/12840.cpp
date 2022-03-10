//
// Created by r4356 on 2022-03-09.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, m, s, q, t, c;
    int time_current;
    cin >> h >> m >> s;
    cin >> q;
    time_current = h*3600 + m*60 + s;
    for(int i=0; i<q; i++){
        cin >> t;
        if(t == 3 ) {
            cout << time_current/3600 << " " << (time_current/60)%60 << " " << time_current%60 << "\n";
        }
        else if(t == 1) {
            cin >> c;
            time_current = (time_current+c)%86400;
        }
        else{
            cin >> c;
            time_current = (time_current - c) %86400;
            while(time_current < 0) {
                time_current += 86400;
            }
        }

    }
}

