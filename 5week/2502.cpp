#include <iostream>
#define MAX 31
using namespace std;

int D, K; //�Է� ���� ��¥, �� ����
int A[MAX], B[MAX]; //A�� B ���� ���� �迭

void input() {
	cin >> D >> K;
}

void df() {

	A[1] = 1; //ù°���� A�ϱ� A[1] = 1 ����
	B[2] = 1; //��°���� B�ϱ� B[2] = 1 ����

	for (int i = 3; i <= D; i++) { //���̳��� ���α׷������� D�� ���� A�� B ���
		A[i] = A[i - 2] + A[i - 1];
		B[i] = B[i - 2] + B[i - 1];
	}

	for (int i = 1; i <= K; i++) { //�� ���� A�� B ���ϱ�
		int tmp = K - (A[D] * i);
		if (tmp % B[D] == 0) {
			cout << i << "\n" << (tmp / B[D]);
			break;
		}
	}


}

int main() {
	input();
	df();
}