//�ð����⵵ O(N*M*H)

#include <iostream>
#include <queue>
#include <tuple>
#define MAX 101
using namespace std;


int M, N, H;
int tomato[MAX][MAX][MAX];//�丶�� ����
int noripen, day;//���� ���� �丶�� ����, ��¥
deque<tuple<int, int, int>> q; //Ž���� �� �� ť.

int dx[6] = { -1, 1, 0, 0, 0, 0 };// ����, ������, ��, ��, ��, �Ʒ��� ���� ���� �迭
int dy[6] = { 0, 0, -1, 1, 0, 0 };// ����, ������, ��, ��, ��, �Ʒ��� ���� ���� �迭
int dz[6] = { 0, 0, 0, 0, -1, 1 };// ����, ������, ��, ��, ��, �Ʒ��� ���� ���� �迭


//M,N �Է¹ް� �丶�� �迭 �Է¹޴� �Լ�
void input() {
    cin >> M >> N >> H;
    noripen = 0;//���� ���� �丶�� ����
    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> tomato[k][i][j];
                //0�̸� ���� ���� �丶��� count
                if (tomato[k][i][j] == 0) {
                    noripen++;
                }
                //1�̸� ť�� ����ְ� �湮üũ ���ֱ�
                if (tomato[k][i][j] == 1) {
                    q.push_back({ k,i,j });
                }
            }
        }
    }

}

void graph() {

    while (!q.empty()) {
        deque<tuple<int, int, int>> q2; //��¥ ���� ���� ť
        while (!q.empty()) {
            int front_z = get<0>(q.front());//ť���� �� �տ� �ִ� �� z��ǥ
            int front_x = get<1>(q.front());//ť���� �� �տ� �ִ� �� x��ǥ
            int front_y = get<2>(q.front());//ť���� �� �տ� �ִ� �� y��ǥ
            q.pop_front(); //���� ����
            for (int i = 0; i < 6; i++)
            {
                // next_x, next_y�� �������� push�� �ε��� �ĺ�
                int next_z = front_z + dz[i];
                int next_x = front_x + dx[i];
                int next_y = front_y + dy[i];
                if (0 < next_x && next_x <= N && 0 < next_y && next_y <= M && 0 < next_z && next_z <= H /*������ ������ �Ѿ�� �ȵ� */ && tomato[next_z][next_x][next_y] == 0) //next ��ǥ�� �丶�䰡 0���¶��
                {
                    noripen--;
                    q2.push_back(make_tuple(next_z, next_x, next_y));//push����
                    tomato[next_z][next_x][next_y] = 1;// ���� ���� �丶�䰡 �� �Ŵϱ� 1�� �ٲ���.
                }
            }
        }
        day++;
        q = q2;
    }

    day--;

    if (noripen > 0) { //���� ���� �丶�䰡 �ִٸ�
        cout << "-1\n";
    }
    else {
        cout << day << "\n";
    }
}


int main() {
    input();
    graph();
    return 0;
}
