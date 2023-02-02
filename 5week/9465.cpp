// �ð����⵵
// �������⵵
// ������� ��: �׳� ���� ��ü�� �������.. ���� ����� ���� ��� Ǯ��� �� �� ����̾���
/**********************************
��ó������ ������ ������׷� ���ߵǴ� �� �ƴѰ�?! �ߴµ� ��� ��� ��찡 ���ܼ�
 ��� Ǯ�� �ϴٰ� 1������ �����ؼ� ū ���� ���� �����ϴ� ������� Ǯ����.
**********************************/

#include <iostream>
#define MAX 100001
using namespace std;

int sticker[2][MAX], dp[2][MAX];//������ ���� ������ �迭
int T, n;

int max(int a, int b) {//a, b �� �ִ� ���ϴ� �Լ�
    if (a > b) return a;
    else return b;
}

void dynamic(int n) {

    for (int i = 0; i < 2; i++) { //�Է� ���� ��ƼĿ ������ �迭�� ����
        for (int j = 0; j < n; j++) {
            cin >> sticker[i][j];
        }
    }
    //��ƼĿ ���� 2���� �� ������ ������ �������
    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[1][0] + sticker[0][1];
    dp[1][1] = sticker[0][0] + sticker[1][1];

    //3��° �� ���ʹ� max ������ �ؾ���
    for (int i = 2; i < n; i++) {
        dp[0][i] = sticker[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
        dp[1][i] = sticker[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";

}



void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        dynamic(n);
    }
}




int main() {

    input();



    return 0;
}