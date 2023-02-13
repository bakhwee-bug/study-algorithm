#include <iostream>
#include <string>
using namespace std;
#define MAX_STACK_SIZE	10001
//�ð����⵵ O(n)
//�������⵵ O(n) 
/*������� ��: push X��� �Ǿ��־ ��� ������ �����ϴ� �� ������� !! 
���� �ڷᱸ�� �ð��� ��� ���� Ŭ������ ������ �� �׳� �����Ǿ� �ִ� stack �� �� ��
����ϴٰ� �̿� �ϴ� �迡 �غ��� !! �ߴµ� �� ��ȸ�Ǳ⵵ �ߴ�..*/ 
 
class ArrayStack
{
	int		data[MAX_STACK_SIZE];	// ����� �迭
	int		count;					// ����� ����

public:
	ArrayStack() { count = -1; }
	~ArrayStack() {}
	//���� e ���ÿ� �ְ� 
	void push(int e) {
		data[++count] = e;
	}
	bool empty() { return count == -1; }
	int pop() {
		if (empty() == 1) {
			return -1;
		}
		else
			return data[count--];
	}
	
	int top() {
		if (empty() == 1) {
			return -1;
		}
		else
			return data[count];
	}

	int size() {
		return count+1;
	}
	
};

int main() {
	//Ŭ���� �ʱ�ȭ
	ArrayStack stack;

	// �־����� ����� �� N
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string cmd;//�Է¹��� ��ɾ�
		cin >> cmd;

		//push X: ���� X�� ���ÿ� �ִ� ����.
		if (cmd == "push") {
			int num;
			cin >> num;
			stack.push(num);
		}
		//pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ���.
		//���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ���.
		else if (cmd == "pop") {
			cout<<stack.pop()<<'\n';
		}
		//size: ���ÿ� ����ִ� ������ ������ ���.
		else if (cmd == "size") {
			cout << stack.size() << '\n';
		}
		//empty: ������ ��������� 1, �ƴϸ� 0�� ���.
		else if (cmd == "empty") {
			cout << stack.empty() << '\n';
		}
		//top: ������ ���� ���� �ִ� ������ ���.
		//���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ���.
		else if (cmd == "top") {
			cout << stack.top() << '\n';
		}

	}
	return 0;
}
