#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int elec[MAX];
int dp[MAX];
int T;

void input() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int r, c;
		cin >> r >> c;
		elec[c] = r;
	}
}

void dynamic() {
	for (int i = 1; i <MAX; i++) {
		if (elec[i] == 0) {
			dp[i] = 0;
		}
		else {
			dp[i] = 1;
		}
		for (int j = 1; j <= i; j++) {
			if (elec[j] < elec[i] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
		//cout << "dp[" << i << "] = " << dp[i] << "\n";
	}
	int max = *max_element(begin(dp), end(dp));
	cout << T - max;
}

int main() {
	input();
	dynamic();
	return 0;
}