//
// Created by r4356 on 2022-03-17.
//
#include <iostream>
#include <deque>

using namespace std;

void arrangeCard(deque<int> &a, int n) {
    deque<int> first, last;
    int temp;
    for(int i =1; i<n+1; i++){
        last.push_back(i);
    }
    while(!a.empty()){
        switch (a.front()) {
            case 1:
                first.push_front(last.front());
                last.pop_front();
                a.pop_front();
                break;
            case 2:
                temp = first.front();
                first.pop_front();
                first.push_front(last.front());
                first.push_front(temp);
                last.pop_front();
                a.pop_front();
                break;
            case 3:
                first.push_back(last.front());
                a.pop_front();
                last.pop_front();
                break;
        }
    }
    while(!first.empty()) {
        cout << first.front() << " ";
        first.pop_front();
    }
}

int main() {
    int n, num;
    cin >> n;
    deque<int> order;
    for(int i =0; i<n; i++) {
        cin >> num;
        order.push_front(num);
    }

    arrangeCard(order, n);
}
