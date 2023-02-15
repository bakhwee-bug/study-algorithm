#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> ans;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		ans.push_back(num);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < N; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}