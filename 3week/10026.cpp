#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
// �ð����⵵
// �������⵵
// ������� ��: ���� ���� ���� count �� ���� �������.
/**********************************
�̷�Ž�� ������ ����� �� ����.
1. �׳� ����� ���� ���� ���ϱ�
-->�̷� Ž��
ù��°ĭ���� �����¿츦 ������ �� ���� �� ������ ť�� �ְ� ���� ĭ�� pop.
���� �� ĭ�� 0���� �ٲٵ� visited ���� �ؼ� ǥ��.
������ ���� �� ����(ť�� �� ������) ������ ť�� ��� ���� ���� +1�� �Ѵ�.
���� ��ü�� �湮�� ���� ���� ������ �ݺ��Ѵ�.

2. ���� ����� ���� ���� ���ϱ�
-->R�� G�� �ٲٵ� G�� R�� �ٲٵ� �ؼ� ���� �Ȱ��� �ϰų�
������ �߰�.�ؼ� Ž��
**********************************/
int n;
char map[MAX][MAX]; //�Է� ���� �׸� �迭
bool visited[MAX][MAX] = { false }; //�湮 üũ �迭 false�� �ʱ�ȭ
vector<int> ans; //���� ũ�� �Է��� ����.

int dx[4] = { -1, 1, 0, 0 };// ��, ��, ��, ��� ���� ���� �迭
int dy[4] = { 0, 0, -1, 1 };// ��, ��, ��, ��� ���� ���� �迭

void bfs(int row, int col)
{
    queue<pair<int, int>> q; //������ ��� �� �־�����ϹǷ� ���Ϳ� �� �� �־��ٰ���
    q.push(make_pair(row, col));//ť�� ���̶� �� �� ��� push
    visited[row][col] = true; // �׸��� �湮 üũ �迭�� true�� �������
    
    
    while (!q.empty()) {
        int front_x = q.front().first; //ť���� �� �տ� �ִ� �� x��ǥ
        int front_y = q.front().second;//ť���� �� �տ� �ִ� �� y��ǥ
        q.pop(); //���� ����

        for (int i = 0; i < 4; i++) {
            // next_x, next_y�� �������� push�� �ε��� �ĺ�
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n // ������ ������ �Ѿ�� �ȵ�
                && visited[next_x][next_y] == false && map[next_x][next_y] == map[front_x][front_y]) //next ��ǥ�� �湮���� ���� ���̰�, ���ĺ��� ���ٸ�
            {
                q.push(make_pair(next_x, next_y));//push����
                visited[next_x][next_y] = true;// �׸��� �湮 üũ �迭�� true�� �������
                
            }
        }
    }
    

}


int main()
{
    int cnt = 0;
    cin >> n;
    // �׸� �Է¹ޱ�
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    //Ž�� 1 : �׳� ���
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {//�湮 �� �߰� 0�� �ƴϸ� Ž�� ����
            if (visited[i][j] == false && map[i][j] != 0)
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    ans.push_back(cnt);//���� �� ans�� �־���

    //R->G
    //Ž�� 2: ���� ����

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'R') {
                map[i][j] = 'G';
            }
        }
    }

    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {//�湮 �� �߰� 0�� �ƴϸ� Ž�� ����
            if (visited[i][j] == false && map[i][j] != 0)
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    ans.push_back(cnt);//���� �� ans�� �־���
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] <<' ';

    return 0;
}