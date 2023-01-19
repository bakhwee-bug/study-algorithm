#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 시간복잡도
// 공간복잡도
// 어려웠던 점: day를 언제 카운트 할 지 정하는 게 어려웠습니다. 그리고 언제 마무리 할 지 ...
/**********************************
토마토 가로 칸 수, 세로 칸 수 입력 받고 그것대로 배열을 만듭니다.
그리고 둘째 줄부터 주어지는 정보를 배열에 넣습니다.
그리고 이제 다 돌면서 1이 있으면 큐에 넣습니다
그리고 큐에 들어온 순으로 BFS ㄱㄱ 해서 다음 토마토가 0이고 방문을 안 했으면 큐에 넣습니다.
그리고 큐가 빌 때까지 BFS를 돌립니다.
**********************************/

int n, m;
int map[1000][1000]; //입력 받을 토마토 배열
vector<int> ans; //토마토 날짜 입력할 벡터. 
bool visited[1000][1000] = { false }; //방문 체크 배열 false로 초기화


int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열

void bfs(int row, int col)//너비우선탐색....
{
    queue<pair<int, int>> q; //토마토의 행과 열 넣어줘야하므로 벡터에 두 쌍 넣어줄거임
    q.push(make_pair(row, col));//큐에 행이랑 열 쌍 지어서 push
    visited[row][col] = true; // 그리고 방문 체크 배열에 true로 만들어줌
    int cnt = 0; //날짜수 
    cnt++;//날짜수 plus
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
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n // 범위는 지도를 넘어가면 안됨
                && visited[next_x][next_y] == false && map[next_x][next_y] == 0) //next 좌표가 방문하지 않은 곳이고, 토마토가 0상태라면
            {
                q.push(make_pair(next_x, next_y));//push해줌
                visited[next_x][next_y] = true;// 그리고 방문 체크 배열에 true로 만들어줌
                cnt++;
            }
        }
    }
    //queue가 빌 때까지 반복
    ans.push_back(cnt);//날짜 수 ans에 넣어줌
}


int main()
{

    cin >> n >> m;
    // 토마토 입력받기
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    // 지도 탐색
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {//방문 안 했고 집이 있으면 bfs 시작
            if (visited[i][j] == false && map[i][j] == 1)
            {
                bfs(i, j);
            }
        }
    }
    // 결과 출력
    sort(ans.begin(), ans.end());//단지 수 정렬
    cout << ans[0] << '\n';

    return 0;
}