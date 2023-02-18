#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int A[MAX], dp[MAX], dp2[MAX];//���� �κ� ����, ���� �κ� ���� dp

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void dynamic() {
    for (int i = 1; i <= N; i++) {//dp[i]=1 �־��ֱ�
        dp[i] = 1;
        dp2[i] = 1;
        for (int j = 1; j < i; j++) {//A[i]�� �ִ� ���� �տ� �ִ� ���麸�� ũ�� dp�� ������?
            if (A[i] > A[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
     //    cout << dp[i] <<" ";
    }
  //  cout << "\n";


    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= i; j--) {
            if (A[i] > A[j] && dp2[i] <= dp2[j]) {//A[i]�� �ִ� ���� �ڿ� �ִ� ���麸�� ũ�� dp�� ������?
                dp2[i] = dp2[j] + 1;
            }
        }
    }
    
    for(int i = 1;i<=N; i++){
      //  cout << dp2[i] <<" ";
        dp2[i] += dp[i];
    }



   // int max1 = *max_element(begin(dp), end(dp));
    int max2 = *max_element(begin(dp2), end(dp2));

   // cout << "\n" << max1 << " " << max2 << "\n";
    //cout << max1 + max2 - 1;
    cout << max2 - 1;
}

int main() {
    input();
    dynamic();
    return 0;
}
