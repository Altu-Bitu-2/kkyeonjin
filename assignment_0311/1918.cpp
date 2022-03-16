//
// Created by r4356 on 2022-03-17.
//
#include <iostream>
#include <stack>

using namespace std;

int priority(char op){

    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void infixToPostfix(string s, stack<char> *a){
    for(int i=0; i<s.length(); i++) {
        switch (s[i]) {
            case '+': case '-': case '*': case '/':
                while(!a->empty() && priority(s[i]) <= priority(a->top())) {
                    cout << a->top();
                    a->pop();
                }
                a->push(s[i]);
                break;
            case '(':
                a->push(s[i]);
                break;
            case ')':
                while(!(a->top() == '(')){
                    cout << a->top();
                    a->pop();
                }
                a->pop();
                break;
            default:
                cout << s[i] ;
                break;
        }
    }
    while(!a->empty()) {
        cout << a->top();
        a->pop();
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string input;
    cin >> input;

    infixToPostfix(input, &st);

}