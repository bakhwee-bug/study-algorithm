#include <iostream>
#define MAX 31
using namespace std;

int D, K; //입력 받을 날짜, 떡 개수
int A[MAX], B[MAX]; //A랑 B 세기 위한 배열

void input() {
	cin >> D >> K;
}

void df() {

	A[1] = 1; //첫째날은 A니까 A[1] = 1 저장
	B[2] = 1; //둘째날이 B니까 B[2] = 1 저장

	for (int i = 3; i <= D; i++) { //다이나믹 프로그래밍으로 D일 까지 A와 B 계산
		A[i] = A[i - 2] + A[i - 1];
		B[i] = B[i - 2] + B[i - 1];
	}

	for (int i = 1; i <= K; i++) { //식 만들어서 A와 B 구하기
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