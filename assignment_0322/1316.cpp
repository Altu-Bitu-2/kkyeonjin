//
// Created by r4356 on 2022-03-26.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    //count해야하는 단어인지 확인하기 위한 변수 is_cnt;
    int is_cnt;
    int cnt = 0;
    string word;
    //알파벳이 나왔는지 체크하는 배열 check
    bool check[26];
    fill_n(check, 26, false);
    cin >> n;
    while(n--) {
        cin >> word;
        is_cnt = 1;
        //check 배열이 인덱스로 알파벳을 구분해 체크할 수 있도록 문자를 숫자로 바꾸기 (a=o, b=1, c=2,...되도록)
        check[(word[0] - '0') - 49] = true;
        //단어 길이가 1이면 무조건 count되므로 if문 사용
        if(word.length() != 1) {
            for (int i = 1; i < word.length(); i++) {
                int c = (word[i] - '0') - 49;
                //check 배열 값이 true이고 같은 알파벳이 연속으로 나오는 경우가 아니라면 count하지 않음
                if (check[c] == true && word[i] != word[i - 1]) {
                    is_cnt = 0;
                    break;
                } else {
                    check[c] = true;
                }
            }
        }
        if(is_cnt == 1) {
            cnt++;
        }
        else {

        }
        // check 배열 초기화
        fill_n(check, 26, false);
    }
    cout << cnt;
}