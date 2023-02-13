#include <iostream>
#include <string>
using namespace std;
#define MAX_STACK_SIZE	10001
//시간복잡도 O(n)
//공간복잡도 O(n) 
/*어려웠던 점: push X라고 되어있어서 어떻게 받을지 생각하는 게 힘들었다 !! 
또한 자료구조 시간에 배운 스택 클래스를 구현할 지 그냥 구현되어 있는 stack 을 쓸 지
고민하다가 이왕 하는 김에 해보자 !! 했는데 좀 후회되기도 했다..*/ 
 
class ArrayStack
{
	int		data[MAX_STACK_SIZE];	// 요소의 배열
	int		count;					// 요소의 개수

public:
	ArrayStack() { count = -1; }
	~ArrayStack() {}
	//정수 e 스택에 넣고 
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
	//클래스 초기화
	ArrayStack stack;

	// 주어지는 명령의 수 N
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string cmd;//입력받을 명령어
		cin >> cmd;

		//push X: 정수 X를 스택에 넣는 연산.
		if (cmd == "push") {
			int num;
			cin >> num;
			stack.push(num);
		}
		//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력.
		//만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력.
		else if (cmd == "pop") {
			cout<<stack.pop()<<'\n';
		}
		//size: 스택에 들어있는 정수의 개수를 출력.
		else if (cmd == "size") {
			cout << stack.size() << '\n';
		}
		//empty: 스택이 비어있으면 1, 아니면 0을 출력.
		else if (cmd == "empty") {
			cout << stack.empty() << '\n';
		}
		//top: 스택의 가장 위에 있는 정수를 출력.
		//만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력.
		else if (cmd == "top") {
			cout << stack.top() << '\n';
		}

	}
	return 0;
}
