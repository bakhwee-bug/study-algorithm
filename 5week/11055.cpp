// 시간복잡도
// 공간복잡도
// 어려웠던 점:
/**********************************
일단 증가 부분 수열들을 구하고 
그 증가 부분 수열들의 합을 다 구하고
그 중 최댓값을 도출
**********************************/

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int A[MAX],dp[MAX];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

void dynamic() {
	for (int i = 1; i <= N; i++) {//dp[i]=A[i] 넣어주기
		dp[i] = A[i];
		for (int j = 0; j < i; j++) {//A[i]에 있는 수가 어떤 수보다 크고
			// 그 어떤 수의 dp 수 + A[i] 가 dp[i]보다 작다면 합이 더 큰거니까 dp에 넣어주기
			if (A[i] > A[j] && dp[i] < A[i] + dp[j]) {
				dp[i] = A[i] + dp[j];
			}
		}
	}

	int max = *max_element(begin(dp), end(dp));
	cout << max;
}

int main() {
	input();
	dynamic();
	return 0;
}