#include <iostream>
#define MAX 101
using namespace std;

long long arr[21][MAX];//���� ������ �迭
int num[MAX]; //�Է� ���� ���ڵ� (0~9)
int N; //������ ���� (3 �� N �� 100)

void input() {
	cin >> N; //������ ���� �Է¹ް�
	for (int i = 1; i <= N; i++) {
		cin >> num[i]; // �� ���ڸ�ŭ ���� �Է¹ޱ�
	}
}

void dp() {
	arr[num[1]][1] = 1;
	
	for (int j = 2; j <= N; j++) {

		for (int i = 0; i <= 20; i++) {
			if (arr[i][j - 1] > 0) {
				if (i + num[j] <= 20) {
					arr[i + num[j]][j]+=arr[i][j-1];	
				}
				if (i - num[j] >= 0) {
					arr[i - num[j]][j] += arr[i][j - 1];
				}
			}
		}
			
	}

	cout << arr[num[N]][N - 1] << "\n";
}


int main() {
	input();
	dp();

	return 0;
}