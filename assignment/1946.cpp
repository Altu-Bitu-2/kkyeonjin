//
// Created by r4356 on 2022-03-10.
//

#include <iostream>
#include <algorithm>
#include <vector>

struct person{
    int rank_doc, rank_int;
};

using namespace std;
int t, n;


int main() {

    cin >> t ;

    while(t--) {
        cin >> n;

        vector<pair<int,int>> list;

        for(int i=0; i<n; i++) {
            int rank_doc, rank_int;
            cin >> rank_doc >> rank_int;
            list.push_back({rank_doc, rank_int});

        }

        sort(list.begin(), list.end());

        int temp =0;
        int result =1;

        for(int i =1; i<n; i++) {
            if(list[temp].second > list[i].second){
                result++;
                temp=i;
            }
        }
        cout << result << "\n";
    }
}