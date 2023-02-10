// 시간복잡도 O(n)
// 공간복잡도
// 어려웠던 점:
/**********************************
패턴을 찾았다 !! 
어차피 i>=3 부터는 계속 같은 패턴이 반복됨
따라서 재귀를 쓰려했는데 그러면 시간초과 날 거 같아서
배열에 저장했다.
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
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max({dp[i-3]+grape[i-1]+grape[i], dp[i-2]+grape[i], dp[i-1]});
	}
	cout << dp[n];
}

int main() {
	input();
	drink();
	return 0;
}
