// 시간복잡도
// 공간복잡도
// 어려웠던 점: 여러 경우의 수를 어떻게 풀어야 할 지 고민이었다
/**********************************
처음에는 모든 경우를 다 저장할까?! 라고 생각했는데 그러면
최대 경우의 수가 3*2^999 라서 고민하다가
스티커 문제랑 비슷하게 푸는 방향으로 해결했다.
**********************************/

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int RGB[MAX][4], dp[MAX][4];//값이랑 dp저장할 배열
int N;//집의 수

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> RGB[i][j];
		}
	}
}


void dynamic() {
	//1행에는 자기 자신 저장
	dp[1][1] = RGB[1][1];
	dp[1][2] = RGB[1][2];
	dp[1][3] = RGB[1][3];

	//2행부터는 자기 자신 위에꺼 말고 다른거 2개중에 작은거 저장
	for (int i = 2; i <= N; i++) {
		dp[i][1] = RGB[i][1] + min(dp[i - 1][2], dp[i - 1][3]);
		dp[i][2] = RGB[i][2] + min(dp[i - 1][1], dp[i - 1][3]);
		dp[i][3] = RGB[i][3] + min(dp[i - 1][1], dp[i - 1][2]);
	}
	
	cout << min({ dp[N][1],dp[N][2],dp[N][3] })<<"\n";
}


int main() {
	input();
	dynamic();
	return 0;
}