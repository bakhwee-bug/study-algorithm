#include<iostream>
using namespace std;

int main() {
	
	int N;
	int count = 0;
	//수의 개수N 입력 받고
	cin >> N;
	//N개의 수가 주어지는데 수는 1, 000 이하의 자연수이다.
	//소수는 1과 자기자신으로 나눌 때만 나누어 떨어짐
	//입력 받을 수를 1부터 자기자신까지 나누었을때 카운트해서 나누어 떨어지는게
	//2번이면 소수임 ( 1은 제외 )

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		int cnt = 0;

		if (num == 1) {
			cnt++;
		}
		//1이면 한 번 더 cnt++해서 아래 과정을 거쳤을 때 1도 cnt가 2가 돼서 count 됨
		for (int i = 1; i <= num; i++) {
			if (num % i == 0) {
				cnt++;
			}
		}

		if (cnt == 2) {
			count++;
		}
	}
	cout << count;
	

	return 0;
}