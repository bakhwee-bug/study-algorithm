#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 61
using namespace std;

// �ð����⵵
// �������⵵
// ������� ��: ����. / �湮 üũ �迭 ��� �� ��.
/**********************************
�� ������ �� 2������ ����ϰ� Ǯ�� �ȴٰ� ����.
�ٸ� ������ ��� �ϴ� ���� ������?

ť�� �迭 �ְ� �� ��츶�� -9 -3 -1 �ؼ� �� ����
-�̸� 0���� �ٲ���
�� 0�̸� Ž�� ����
**********************************/

int N;//�Է� ���� ü�� ��
bool visited[MAX][MAX][MAX];//�湮 üũ �迭

struct NODE {
    int scv[3];
    int depth;
};//ü�� 3���� ��� �� �־� �� ����ü ����

NODE node;
deque<NODE> q; //��带 �ִ� �� ����

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> node.scv[i];
    }
    
    node.depth = 0;
}//ü�� �Է¹޴� �Լ�

int iszero(int a) {
    if (a <= 0) return 0;
    else return a;
}//0���� ������ 0���� ������ִ� �Լ�

void bfs(NODE hp)
{
    q.push_back(hp);
    visited[hp.scv[0]][hp.scv[1]][hp.scv[2]] = true;//�湮 üũ
    
    sort(hp.scv[0], hp.scv[2]); // �������� ����

    do {
        while (!q.empty()) {
            NODE s = q.front();
            q.pop_front();
            for (int i = 0; i < 3; i++) {
                s.scv[i] = iszero[s.scv[i]];
            }
            
        }
    } while (next_permutation(hp.scv[0], hp.scv[2]));

}

int main()
{
  
    return 0;
}