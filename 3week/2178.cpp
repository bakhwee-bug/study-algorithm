#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
// 시간복잡도
// 공간복잡도
// 어려웠던 점: 길이 있을 때 어디부터 탐색할지? 정하는 거랑 최단경로 찾는ㄱ ㅓ
/**********************************
n, m받고 지도 입력 받고 그걸 배열에 넣는다.
그리고 (1,1)부터 시작하므로 첫번째부터 BFS를 돈다.
그래서 다음 길이 1이고 방문 안 했으면 큐에 넣는다.
그래서 큐의 맨 위에 꺼 부터 BFS해서 끝에 도달하면 벡터에 경로 수를 넣는다.
그렇게 다 돌면 여러 경로가 나올 수도 있고 최단 경로만 나올 수도 있다.
최단 경로를 출력한다.
**********************************/
int n, m;
int map[MAX][MAX]; //입력 받을 지도 배열
vector<int> ans; //경로 수 넣을 벡터
bool visited[MAX][MAX] = { false }; //방문 체크 배열 false로 초기화


int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열

void bfs(int row, int col)//너비우선탐색....
{
    queue<pair<int, int>> q; //지도의 행과 열 넣어줘야하므로 벡터에 두 쌍 넣어줄거임
    q.push(make_pair(row, col));//큐에 행이랑 열 쌍 지어서 push
    visited[row][col] = true; // 그리고 방문 체크 배열에 true로 만들어줌
    int cnt = 0; //경로 수 
    cnt++;//경로 수 plus
    while (!q.empty())
    {
        int front_x = q.front().first; //큐에서 맨 앞에 있는 거 x좌표
        int front_y = q.front().second;//큐에서 맨 앞에 있는 거 y좌표
        q.pop(); //삭제 해줌
        for (int i = 0; i < 4; i++)
        {
            // next_x, next_y는 다음으로 push할 인덱스 후보
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m // 범위는 지도를 넘어가면 안됨
                && visited[next_x][next_y] == false && map[next_x][next_y] == 1) //next 좌표가 방문하지 않은 곳이고, 집이 있다면
            {
                q.push(make_pair(next_x, next_y));//push해줌
                visited[next_x][next_y] = true;// 그리고 방문 체크 배열에 true로 만들어줌
                cnt++;
            }
        }
    }
    //queue가 빌 때까지 반복
    ans.push_back(cnt);//단지 수 ans에 넣어줌
}


int main()
{

    cin >> n;
    // 지도 입력받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    // 지도 탐색
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {//방문 안 했고 집이 있으면 bfs 시작
            if (visited[i][j] == false && map[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    // 결과 출력
    sort(ans.begin(), ans.end());//경로 수 정렬
    cout << ans[0] << '\n';

    return 0;
}