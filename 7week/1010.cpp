#include <iostream>
#define MAX 31
using namespace std;

long long arr[MAX][MAX];//개수 저장할 배열
int T, N, M; //테스트, N, M

void dp() {
	cin >> T;
	for (int k = 1; k<= T; k++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= M; j++) {
				if (i == 1) arr[i][j] = j;
				else arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
			}
		}
		cout << arr[N][M] << "\n";
	}
}

int main() {
	dp();
	return 0;
}