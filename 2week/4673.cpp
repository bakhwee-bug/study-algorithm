#include <iostream>
using namespace std;
// 시간복잡도
// 공간복잡도
// 어려웠던 점:
/**********************************
생성자가 없는 수를 어떻게 찾을까 ,,,,
배열 10000개짜리를 만들어서 d(n)을 돌리고 나온 결과 값에 맞는 거에 +1씩 count??
예를 들어 1로 시작하면 1+1=2, 2+2=4, 4+4=8, 8+8=16 ... 이렇게 나오면
배열 [2] [4] [8] [16] 에 +1을 하는 것....
그럼 어디까지 for문을 돌려야하지?...
**********************************/

//배열 만들기
int cnt[10000];

//각 자리수 합 만드는 함수 만들기
int solution(int n) {
	int answer = 0;
	while (n != 0)
	{
		answer = answer + n % 10;
		n = n / 10;
	}

	return answer;
}

//함수 d(n)??을 만들어야 함. 재귀함수를 써야하나??
int d(int a) {
	if (a > 10000) {
		//나온 숫자 10000넘으면 종료
		return;
	}
	else {
		int result = a + solution(a);
		cnt[result]++;
		return d(result);
	}
}

int main() {
	
	
		
	return 0;
}