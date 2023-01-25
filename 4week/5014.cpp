#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000001
using namespace std;

// �ð����⵵
// �������⵵
// ������� ��: 
/**********************************
F: ��ŸƮ��ũ �� �� <= 1,000,000
S: ���� �ִ� �� >= 1
G: ��ŸƮ��ũ�� �ִ� ���� ��ġ <= 1,000,000
U: 0 <= �������� �󸶳� ���� �� <= 1,000,000
D: 0 <= �Ʒ������� �󸶳� ���� �� <= 1,000,000

S������ G������ ���� ���� ������ �ϴ� ��ư�� ���� �ּڰ�

 s + ( N * u ) - ( M * d ) = g
 N + M�� �ּڰ� �Ǵ� �� ���ϸ� ��
 -> ó���� �̷��� ���������� �����ߴٰ� bfs�� ����Ѵٰ� ���ݰ� ��


**********************************/

int f, s, g, u, d;


void input() {
    cin >> f >> s >> g >> u >> d;//�� 5�� �Է� �޴´�.
}

bool visited[MAX];//�湮 üũ �迭

void bfs(int floor)
{
    visited[floor] = true;
    queue<pair<int, int>> q;//���̶� ���° ���� ����� ���� ������ �޴� ť ����

    q.push(make_pair(floor, 0));//0���� ����

    while (!q.empty()) {//ť�� ���� �ʴ� ����
        int a = q.front().first; // �� ������.
        int cnt = q.front().second;//�� ��° ���� ����� ��
        q.pop();
        //��ŸƮ��ũ�� �ִ� ���� ������ ���° ���� ����� ���� ����ϰ� while�� ������.
        if (a == g) {
            cout << cnt;
            return;
        }
        //���� ������ +u / -d �� ���� �� ���� �ȿ� �ְ� �湮 �� ������ ť�� �־��ֱ�.
        if (a + u >= 1 && a + u <= f) {
            if (!visited[a + u]) {
                visited[a + u] = true;
                q.push(make_pair(a + u, cnt + 1));
            }
        }
        if (a - d >= 1 && a - d <= f) {
            if (!visited[a - d]) {
                visited[a - d] = true;
                q.push(make_pair(a - d, cnt + 1));
            }
        }
    }
    
    cout << "use the stairs";
    
    
}

int main()
{
    input();
    bfs(s);

    return 0;
}