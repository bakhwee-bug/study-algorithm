// �ð����⵵
// �������⵵
// ������� ��:
/**********************************
�ϴ� ���� �κ� �������� ���ϰ� 
�� ���� �κ� �������� ���� �� ���ϰ�
�� �� �ִ��� ����
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
	for (int i = 1; i <= N; i++) {//dp[i]=A[i] �־��ֱ�
		dp[i] = A[i];
		for (int j = 0; j < i; j++) {//A[i]�� �ִ� ���� � ������ ũ��
			// �� � ���� dp �� + A[i] �� dp[i]���� �۴ٸ� ���� �� ū�Ŵϱ� dp�� �־��ֱ�
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