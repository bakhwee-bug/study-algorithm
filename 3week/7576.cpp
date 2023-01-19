#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// �ð����⵵
// �������⵵
// ������� ��: day�� ���� ī��Ʈ �� �� ���ϴ� �� ��������ϴ�. �׸��� ���� ������ �� �� ...
/**********************************
�丶�� ���� ĭ ��, ���� ĭ �� �Է� �ް� �װʹ�� �迭�� ����ϴ�.
�׸��� ��° �ٺ��� �־����� ������ �迭�� �ֽ��ϴ�.
�׸��� ���� �� ���鼭 1�� ������ ť�� �ֽ��ϴ�
�׸��� ť�� ���� ������ BFS ���� �ؼ� ���� �丶�䰡 0�̰� �湮�� �� ������ ť�� �ֽ��ϴ�.
�׸��� ť�� �� ������ BFS�� �����ϴ�.
**********************************/

int n, m;
int map[1000][1000]; //�Է� ���� �丶�� �迭
vector<int> ans; //�丶�� ��¥ �Է��� ����. 
bool visited[1000][1000] = { false }; //�湮 üũ �迭 false�� �ʱ�ȭ


int dx[4] = { -1, 1, 0, 0 };// ��, ��, ��, ��� ���� ���� �迭
int dy[4] = { 0, 0, -1, 1 };// ��, ��, ��, ��� ���� ���� �迭

void bfs(int row, int col)//�ʺ�켱Ž��....
{
    queue<pair<int, int>> q; //�丶���� ��� �� �־�����ϹǷ� ���Ϳ� �� �� �־��ٰ���
    q.push(make_pair(row, col));//ť�� ���̶� �� �� ��� push
    visited[row][col] = true; // �׸��� �湮 üũ �迭�� true�� �������
    int cnt = 0; //��¥�� 
    cnt++;//��¥�� plus
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
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n // ������ ������ �Ѿ�� �ȵ�
                && visited[next_x][next_y] == false && map[next_x][next_y] == 0) //next ��ǥ�� �湮���� ���� ���̰�, �丶�䰡 0���¶��
            {
                q.push(make_pair(next_x, next_y));//push����
                visited[next_x][next_y] = true;// �׸��� �湮 üũ �迭�� true�� �������
                cnt++;
            }
        }
    }
    //queue�� �� ������ �ݺ�
    ans.push_back(cnt);//��¥ �� ans�� �־���
}


int main()
{

    cin >> n >> m;
    // �丶�� �Է¹ޱ�
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    // ���� Ž��
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {//�湮 �� �߰� ���� ������ bfs ����
            if (visited[i][j] == false && map[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    // ��� ���
    sort(ans.begin(), ans.end());//���� �� ����
    cout << ans[0] << '\n';

    return 0;
}