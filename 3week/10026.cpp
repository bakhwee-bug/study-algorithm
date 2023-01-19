#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
// 시간복잡도
// 공간복잡도
// 어려웠던 점: 구역 수를 언제 count 할 지가 어려웠다.
/**********************************
미로탐색 문제랑 비슷한 거 같다.
1. 그냥 사람이 보는 구역 정하기
-->미로 탐색
첫번째칸에서 상하좌우를 돌았을 때 같은 게 있으면 큐에 넣고 현재 칸은 pop.
갔다 온 칸은 0으로 바꾸든 visited 쓰든 해서 표시.
구역이 끝날 때 까지(큐가 빌 때까지) 돌리고 큐가 비면 구역 수에 +1을 한다.
지도 전체에 방문한 곳이 없을 때까지 반복한다.

2. 생맹 사람이 보는 구역 정하기
-->R을 G로 바꾸든 G를 R로 바꾸든 해서 위랑 똑같이 하거나
조건을 추가.해서 탐색
**********************************/
int n;
char map[MAX][MAX]; //입력 받을 그림 배열
bool visited[MAX][MAX] = { false }; //방문 체크 배열 false로 초기화
vector<int> ans; //구역 크기 입력할 벡터.

int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열

void bfs(int row, int col)
{
    queue<pair<int, int>> q; //지도의 행과 열 넣어줘야하므로 벡터에 두 쌍 넣어줄거임
    q.push(make_pair(row, col));//큐에 행이랑 열 쌍 지어서 push
    visited[row][col] = true; // 그리고 방문 체크 배열에 true로 만들어줌
    
    
    while (!q.empty()) {
        int front_x = q.front().first; //큐에서 맨 앞에 있는 거 x좌표
        int front_y = q.front().second;//큐에서 맨 앞에 있는 거 y좌표
        q.pop(); //삭제 해줌

        for (int i = 0; i < 4; i++) {
            // next_x, next_y는 다음으로 push할 인덱스 후보
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n // 범위는 지도를 넘어가면 안됨
                && visited[next_x][next_y] == false && map[next_x][next_y] == map[front_x][front_y]) //next 좌표가 방문하지 않은 곳이고, 알파벳이 같다면
            {
                q.push(make_pair(next_x, next_y));//push해줌
                visited[next_x][next_y] = true;// 그리고 방문 체크 배열에 true로 만들어줌
                
            }
        }
    }
    

}


int main()
{
    int cnt = 0;
    cin >> n;
    // 그림 입력받기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    //탐색 1 : 그냥 사람
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {//방문 안 했고 0이 아니면 탐색 시작
            if (visited[i][j] == false && map[i][j] != 0)
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    ans.push_back(cnt);//구역 수 ans에 넣어줌

    //R->G
    //탐색 2: 적록 색맹

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
        {//방문 안 했고 0이 아니면 탐색 시작
            if (visited[i][j] == false && map[i][j] != 0)
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    ans.push_back(cnt);//구역 수 ans에 넣어줌
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] <<' ';

    return 0;
}