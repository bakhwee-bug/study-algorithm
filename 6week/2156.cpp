// �ð����⵵
// �������⵵
// ������� ��:
/**********************************
������ ã�Ҵ� !! 
������ i>=3 ���ʹ� ��� ���� ������ �ݺ���
���� ��͸� �����ߴµ� �׷��� �ð��ʰ� �� �� ���Ƽ�
�迭�� �����ߴ�.
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