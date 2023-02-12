//시간복잡도 O(N*M*H)

#include <iostream>
#include <queue>
#include <tuple>
#define MAX 101
using namespace std;


int M, N, H;
int tomato[MAX][MAX][MAX];//토마토 지도
int noripen, day;//익지 않은 토마토 개수, 날짜
deque<tuple<int, int, int>> q; //탐색할 때 쓸 큐.

int dx[6] = { -1, 1, 0, 0, 0, 0 };// 왼쪽, 오른쪽, 앞, 뒤, 위, 아래로 가기 위한 배열
int dy[6] = { 0, 0, -1, 1, 0, 0 };// 왼쪽, 오른쪽, 앞, 뒤, 위, 아래로 가기 위한 배열
int dz[6] = { 0, 0, 0, 0, -1, 1 };// 왼쪽, 오른쪽, 앞, 뒤, 위, 아래로 가기 위한 배열


//M,N 입력받고 토마토 배열 입력받는 함수
void input() {
    cin >> M >> N >> H;
    noripen = 0;//익지 않은 토마토 개수
    for (int k = 1; k <= H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> tomato[k][i][j];
                //0이면 익지 않은 토마토로 count
                if (tomato[k][i][j] == 0) {
                    noripen++;
                }
                //1이면 큐에 집어넣고 방문체크 해주기
                if (tomato[k][i][j] == 1) {
                    q.push_back({ k,i,j });
                }
            }
        }
    }

}

void graph() {

    while (!q.empty()) {
        deque<tuple<int, int, int>> q2; //날짜 세기 위한 큐
        while (!q.empty()) {
            int front_z = get<0>(q.front());//큐에서 맨 앞에 있는 거 z좌표
            int front_x = get<1>(q.front());//큐에서 맨 앞에 있는 거 x좌표
            int front_y = get<2>(q.front());//큐에서 맨 앞에 있는 거 y좌표
            q.pop_front(); //삭제 해줌
            for (int i = 0; i < 6; i++)
            {
                // next_x, next_y는 다음으로 push할 인덱스 후보
                int next_z = front_z + dz[i];
                int next_x = front_x + dx[i];
                int next_y = front_y + dy[i];
                if (0 < next_x && next_x <= N && 0 < next_y && next_y <= M && 0 < next_z && next_z <= H /*범위는 지도를 넘어가면 안됨 */ && tomato[next_z][next_x][next_y] == 0) //next 좌표가 토마토가 0상태라면
                {
                    noripen--;
                    q2.push_back(make_tuple(next_z, next_x, next_y));//push해줌
                    tomato[next_z][next_x][next_y] = 1;// 이제 익은 토마토가 될 거니까 1로 바꿔줌.
                }
            }
        }
        day++;
        q = q2;
    }

    day--;

    if (noripen > 0) { //익지 않은 토마토가 있다면
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
