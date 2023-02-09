#include <iostream>
#include <algorithm>
#define MAX1 101
#define MAX2 100001
using namespace std;

int N, K, W, V;
int bag[MAX1][MAX2] = { 0 };
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		for (int j = 1; j <= K; j++) {
			if (W > j) bag[i][j] = bag[i - 1][j];
			else bag[i][j] = max(bag[i - 1][j], (bag[i - 1][j-W] + V));
		}
	}
	cout << bag[N][K];
}


int main() {
	input();
	return 0;
}
