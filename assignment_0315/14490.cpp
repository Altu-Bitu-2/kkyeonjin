//
// Created by r4356 on 2022-03-21.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//최대공약수 구하기
int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

int main() {
    string input;
    cin >> input;

    //':' 기준으로 문자열 분리 후 숫자만 vector에 삽입
    istringstream iss(input);
    string buffer;
    vector<int> nums;
    while(getline(iss, buffer, ':')) {
        nums.push_back(stoi(buffer));
    }


    int gcd = getGcd(max(nums[0], nums[1]), min(nums[0], nums[1]));
    //최대 공약수로 나눠 최대한으로 약분한 값 출력
    cout << nums[0] / gcd << ':' << nums[1] / gcd ;

}
