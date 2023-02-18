#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int A[MAX], dp[MAX], dp2[MAX];//증가 부분 수열, 감소 부분 수열 dp

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void dynamic() {
    for (int i = 1; i <= N; i++) {//dp[i]=1 넣어주기
        dp[i] = 1;
        dp2[i] = 1;
        for (int j = 1; j < i; j++) {//A[i]에 있는 수가 앞에 있는 수들보다 크고 dp가 작으면?
            if (A[i] > A[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
     //    cout << dp[i] <<" ";
    }
  //  cout << "\n";


    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= i; j--) {
            if (A[i] > A[j] && dp2[i] <= dp2[j]) {//A[i]에 있는 수가 뒤에 있는 수들보다 크고 dp가 작으면?
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
