#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
// �ð����⵵
// �������⵵
// ������� ��: ���� ���� �� ������ Ž������? ���ϴ� �Ŷ� �ִܰ�� ã�¤� ��
/**********************************
n, m�ް� ���� �Է� �ް� �װ� �迭�� �ִ´�.
�׸��� (1,1)���� �����ϹǷ� ù��°���� BFS�� ����.
�׷��� ���� ���� 1�̰� �湮 �� ������ ť�� �ִ´�.
�׷��� ť�� �� ���� �� ���� BFS�ؼ� ���� �����ϸ� ���Ϳ� ��� ���� �ִ´�.
�׷��� �� ���� ���� ��ΰ� ���� ���� �ְ� �ִ� ��θ� ���� ���� �ִ�.
�ִ� ��θ� ����Ѵ�.
**********************************/
int n, m;
int map[MAX][MAX]; //�Է� ���� ���� �迭
vector<int> ans; //��� �� ���� ����
bool visited[MAX][MAX] = { false }; //�湮 üũ �迭 false�� �ʱ�ȭ


int dx[4] = { -1, 1, 0, 0 };// ��, ��, ��, ��� ���� ���� �迭
int dy[4] = { 0, 0, -1, 1 };// ��, ��, ��, ��� ���� ���� �迭

void bfs(int row, int col)//�ʺ�켱Ž��....
{
    queue<pair<int, int>> q; //������ ��� �� �־�����ϹǷ� ���Ϳ� �� �� �־��ٰ���
    q.push(make_pair(row, col));//ť�� ���̶� �� �� ��� push
    visited[row][col] = true; // �׸��� �湮 üũ �迭�� true�� �������
    int cnt = 0; //��� �� 
    cnt++;//��� �� plus
    while (!q.empty())
    {
        int front_x = q.front().first; //ť���� �� �տ� �ִ� �� x��ǥ
        int front_y = q.front().second;//ť���� �� �տ� �ִ� �� y��ǥ
        q.pop(); //���� ����
        for (int i = 0; i < 4; i++)
        {
            // next_x, next_y�� �������� push�� �ε��� �ĺ�
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m // ������ ������ �Ѿ�� �ȵ�
                && visited[next_x][next_y] == false && map[next_x][next_y] == 1) //next ��ǥ�� �湮���� ���� ���̰�, ���� �ִٸ�
            {
                q.push(make_pair(next_x, next_y));//push����
                visited[next_x][next_y] = true;// �׸��� �湮 üũ �迭�� true�� �������
                cnt++;
            }
        }
    }
    //queue�� �� ������ �ݺ�
    ans.push_back(cnt);//���� �� ans�� �־���
}


int main()
{

    cin >> n;
    // ���� �Է¹ޱ�
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // ���� Ž��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {//�湮 �� �߰� ���� ������ bfs ����
            if (visited[i][j] == false && map[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    // ��� ���
    sort(ans.begin(), ans.end());//��� �� ����
    cout << ans[0] << '\n';

    return 0;
}