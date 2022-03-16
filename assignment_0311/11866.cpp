//
// Created by r4356 on 2022-03-17.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void josephus(queue<int> &a, int k){
    vector<int> output;
    int t1;
    while(!(a.empty())){
        for(int i = 0; i < k-1; i++) {
            t1 = a.front();
            a.pop();
            a.push(t1);
        }
        output.push_back(a.front());
        a.pop();
    }

    cout << '<';

    for (int i = 0; i < output.size()-1; i++) {
        cout << output[i] << ", ";
    }

    cout << output[output.size()-1] << '>';

}
int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i=0; i<n; i++){
        q.push(i+1);
    }

    josephus(q, k);

}
