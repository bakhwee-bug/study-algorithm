// 시간복잡도
// 공간복잡도
// 어려웠던 점: 그냥 문제 자체가 어려웠다.. 여러 경우의 수를 어떻게 풀어야 할 지 고민이었다
/**********************************
맨처음에는 무조건 지그재그로 가야되는 거 아닌가?! 했는데 가운데 비는 경우가 생겨서
 어떻게 풀까 하다가 1열부터 시작해서 큰 값을 누적 저장하는 방법으로 풀었다.
**********************************/

#include <iostream>
#define MAX 100001
using namespace std;

int sticker[2][MAX], dp[2][MAX];//점수랑 누적 저장할 배열
int T, n;

int max(int a, int b) {//a, b 중 최댓값 구하는 함수
    if (a > b) return a;
    else return b;
}

void dynamic(int n) {

    for (int i = 0; i < 2; i++) { //입력 받은 스티커 점수들 배열에 저장
        for (int j = 0; j < n; j++) {
            cin >> sticker[i][j];
        }
    }
    //스티커 열이 2개일 때 까지는 저장을 해줘야함
    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[1][0] + sticker[0][1];
    dp[1][1] = sticker[0][0] + sticker[1][1];

    //3번째 열 부터는 max 값으로 해야함
    for (int i = 2; i < n; i++) {
        dp[0][i] = sticker[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
        dp[1][i] = sticker[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";

}



void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        dynamic(n);
    }
}




int main() {

    input();



    return 0;
}