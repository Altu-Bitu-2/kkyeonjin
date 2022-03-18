//
// Created by r4356 on 2022-03-17.
//

#include <iostream>
#include <vector>
#include <cmath>
#include<map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

bool cmp(ii &a, ii &b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else
        return a.first < b.first;
}

int mean(vector<int> &a){

    int sum = 0;
    for(int i =0; i<a.size(); i++) {
        sum += a[i];
    }
    int temp = round((float)sum/a.size());

    if(-1 < temp < 0){
        return 0;
    }
    else
        return temp;

}

int median(vector<int> &a) {
    int mid = (a.size()/2);
    return a[mid];
}

int mode(vector<ii> &a){
    if(a[0].second == a[1].second)
        return a[1].first;
    else
        return a[0].first;
}

int range(vector<int> &a) {
    return (a[a.size()-1])-(a[0]) ;
}

int main() {

    int n;
    int num;
    cin >> n;
    map<int, int> in;
    vector<int> v;
    while(n--) {
        cin >> num;
        in[num]++;
        v.push_back(num);
    }

    vector<ii> list(in.begin(), in.end());

    sort(list.begin(), list.end());
    sort(v.begin(), v.end());

    int a=mean(v);
    int b=median(v);
    int d=range(v);

    sort(list.begin(), list.end(), cmp);

    int c=mode(list);

    cout << a << '\n' << b << '\n' <<  c << '\n' << d;
}
