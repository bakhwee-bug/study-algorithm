#include<iostream>
using namespace std;

int main() {
	
	int N;
	int count = 0;
	//���� ����N �Է� �ް�
	cin >> N;
	//N���� ���� �־����µ� ���� 1, 000 ������ �ڿ����̴�.
	//�Ҽ��� 1�� �ڱ��ڽ����� ���� ���� ������ ������
	//�Է� ���� ���� 1���� �ڱ��ڽű��� ���������� ī��Ʈ�ؼ� ������ �������°�
	//2���̸� �Ҽ��� ( 1�� ���� )

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		int cnt = 0;

		if (num == 1) {
			cnt++;
		}
		//1�̸� �� �� �� cnt++�ؼ� �Ʒ� ������ ������ �� 1�� cnt�� 2�� �ż� count ��
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