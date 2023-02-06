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
#define MAX 10001
using namespace std;

int n;
int grape[MAX], dp[MAX];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}
}

void drink() {
	
}

int main() {
	input();
	drink();
	return 0;
}