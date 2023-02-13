#include <iostream>
#define MAX 12
using namespace std;

int arr[MAX];
int T, n; //Å×½ºÆ®, n

void dp(int n) {
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	if (n < 4) {
		cout << arr[n] << "\n";
	}
	else {
		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
		}
		cout << arr[n] << "\n";
	}
}


int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		dp(n);
	}
	return 0;
}