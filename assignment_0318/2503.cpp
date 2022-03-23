//
// Created by r4356 on 2022-03-22.
//
#include <iostream>

using namespace std;

// 배열 인덱스 값이 답이 될 수 있는 값이면 true/ 아니면 false
// 세자리 숫자가 모두 달라야 하고 0이 있으면 안 됨
void makeList(bool nums[]) {
    fill_n(nums, 1000, true);
    for (int i = 123; i < 1000; i++) {
         string num = to_string(i);
       if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) {
             nums[i] = false;
         }
         if(num[0] - '0' == 0 || num[1] - '0' == 0 || num[2] - '0' == 0) {
             nums[i] = false;
         }
     }
 }

 void solve(string q, int s, int b, bool nums[]) {
    int s_cnt, b_cnt;
    for(int i = 123; i < 1000; i++) {
        s_cnt = 0;
        b_cnt = 0;
        //정답 가능성이 있는 숫자의 경우만 진행
        if(nums[i]) {
            string num = to_string(i);

            //숫자와 자릿수 모두 같으면 s_cnt 증가
            for(int j = 0; j < 3; j++) {
                if(q[j] == num[j])
                    s_cnt++;
            }

            //숫자만 같고 자릿수가 다르면 b_cnt 증가
            for(int j = 0; j < 3; j++) {
                if (q[0] == num[j] && j != 0) {
                    b_cnt++;
                }
                if (q[1] == num[j] && j != 1) {
                    b_cnt++;
                }
                if (q[2] == num[j] && j != 2) {
                    b_cnt++;
                }
            }

            //s_cnt와 s(strike), b_cnt와 b(ball) 비교해 같지 않으면 false
            if(s_cnt != s || b_cnt != b) {
                nums[i] = false;
            }

        }
    }
}


 int main() {
     int n, s, b;
     string q;
     cin >> n;
     bool nums[1000];
     makeList(nums);
     while(n--) {
         cin >> q >> s >> b ;
         solve(q, s, b, nums);
     }
     int cnt = 0;

     for(int i = 123; i < 1000; i++) {
         if(nums[i])
             cnt++;
     }

     cout << cnt;
}



