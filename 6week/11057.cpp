// 시간복잡도
// 공간복잡도
// 어려웠던 점: 그냥 문제 자체가 어려웠다.. 여러 경우의 수를 어떻게 풀어야 할 지 고민이었다
/**********************************
처음에는 순열인가 조합인가 어떻게 풀어야 하지? 라고 생각하다가
 2차원 배열을 써서 옆에꺼 위에꺼 더하는 형식으로 풀었다.
 1 1      1            1
 1 1+1 (1+1)+1 (1+1+1)+1
**********************************/

#include <iostream>
#define MAX 1001
using namespace std;

int N;
long long arr[MAX][10];

void input() {
    cin >> N;
}

void find(int n) {
    for (int i = 1; i <= n; i++) {
        arr[i][0] = 1; //첫째줄 1로 초기화 arr[1][0]~arr[n][0]
        for (int j = 1; j <= 9; j++) {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j]; //옆에꺼랑 위에꺼 더한걸로 넣기
            arr[i][j] %= 10007;//이거 추가하니까 됨.. 왜지?
        }
    }
    long long cnt = 0;
    for (int i = 0; i <= 9; i++) {
        cnt += arr[n][i];
    }
    cout << cnt % 10007;
}

int main() {
    input();
    find(N);

    return 0;
}
