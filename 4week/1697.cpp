#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
// �ð����⵵
// �������⵵
// ������� ��: for���� ������ ���� �� �����ϴ� �� ����� �� ����.
/**********************************
ó������ ���������� �����ؼ� �ʹ� ������µ�
�ٽ� �����غ��ϱ� �׳� ��� ��츦 ����� �ǰڴٰ� �����ؼ�
BFS�� �ؼ� ��� ��츦 �غ��� �������� ������ �ϴ� �غ��� ��� �����ߴ�.
**********************************/

int N, K;// �Է¹��� N�ϰ� K
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
        //������ �ִ� ���� ������ ���° ���� ����� ���� ����ϰ� while�� ������.
        if (a == K) {
            cout << cnt;
            break;
        }
        //���� ������ +1, -1, *2 �� ���� �� ���� �ȿ� �ְ� �湮 �� ������ ť�� �־��ֱ�.
        if (a + 1 >= 0 && a + 1 < MAX) {
            if (!visited[a + 1]) {
                visited[a + 1] = true;
                q.push(make_pair(a + 1, cnt + 1));
            }
        }
        if (a - 1 >= 0 && a - 1 < MAX) {
            if (!visited[a - 1]) {
                visited[a - 1] = true;
                q.push(make_pair(a - 1, cnt + 1));
            }
        }
        if (2 * a >= 0 && 2 * a < MAX) {
            if (!visited[2 * a]) {
                visited[2 * a] = true;
                q.push(make_pair(2 * a, cnt + 1));
            }
        }
    }


}


int main()
{
    cin >> N >> K;
    bfs(N);

    return 0;
}