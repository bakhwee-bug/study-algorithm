// �ð����⵵
// �������⵵
// ������� ��: ���� ����� ���� ��� Ǯ��� �� �� �����̾���
/**********************************
ó������ ��� ��츦 �� �����ұ�?! ��� �����ߴµ� �׷���
�ִ� ����� ���� 3*2^999 �� �����ϴٰ�
��ƼĿ ������ ����ϰ� Ǫ�� �������� �ذ��ߴ�.
**********************************/

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int RGB[MAX][4], dp[MAX][4];//���̶� dp������ �迭
int N;//���� ��

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> RGB[i][j];
		}
	}
}


void dynamic() {
	//2����ʹ� �ڱ� �ڽ� ������ ���� �ٸ��� 2���߿� ������ ����
	for (int i = 1; i <= N; i++) {
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