#include<iostream>
using namespace std;
//시간복잡도 O(n)
//공간복잡도 O(1)
int main() {
	
	int N;
	int count = 0;
	//수의 개수N 입력 받고
	cin >> N;
	//N개의 수가 주어지는데 수는 1, 000 이하의 자연수이다.
	//소수는 1과 자기자신으로 나눌 때만 나누어 떨어짐
	//입력 받을 수를 1부터 자기자신까지 나누었을때 카운트해서 나누어 떨어지는게
	//2번이면 소수임

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		int cnt = 0;

		
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