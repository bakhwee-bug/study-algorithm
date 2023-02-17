#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int A[MAX], dp[MAX];

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void dynamic() {
    for (int i = 1; i <= N; i++) {//dp[i]=1 �־��ֱ�
        dp[i] = 1;
        for (int j = 1; j < i; j++) {//A[i]�� �ִ� ���� �տ� �ִ� ���麸�� �۰� dp�� ������?
            if (A[i] < A[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = *max_element(begin(dp), end(dp));
    cout <<max;
}

int main() {
    input();
    dynamic();
    return 0;
}

