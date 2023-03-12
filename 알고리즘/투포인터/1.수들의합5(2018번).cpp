// https://www.acmicpc.net/problem/2018


#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
cin >> N;
int count = 1;
int start = 1;
int end = 1;
int sum = 1;


while(end != N) {
    if(sum == N) {
        count++;
        end++;
        sum = sum + end;
    } else if(sum > N) {
        sum = sum - start;
        start++;
    }else{
        end++;
        sum = sum + end;
    }
}
cout << count << "\n";
}
