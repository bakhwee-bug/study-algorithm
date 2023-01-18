#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 시간복잡도
// 공간복잡도
// 어려웠던 점: 너비 우선 탐색
/**********************************
지도를 입력받고 전체 지도 훑는다!!
이때 1이면서 방문하지 않은 곳을 찾고
찾으면 그 집을 시작으로 그 집이 있는 단지의 집의 수를 구함
그리고 전체 지도 데이터 탐색 다 끝나면
각각의 단지 내 집의 수를 오름차순으로 정렬 후 출력
**********************************/

int n;
int map[26][26]; //입력 받을 지도 배열
vector<int> ans; //단지 크기 입력할 벡터. 단지가 몇 개 나올 지 모르니까 벡터로 함
bool visited[26][26] = { false }; //방문 체크 배열 false로 초기화


int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열

void bfs(int row, int col)//너비우선탐색....
{
    queue<pair<int, int>> q; //지도의 행과 열 넣어줘야하므로 벡터에 두 쌍 넣어줄거임
    q.push(make_pair(row, col));//큐에 행이랑 열 쌍 지어서 push
    visited[row][col] = true; // 그리고 방문 체크 배열에 true로 만들어줌
    int cnt = 0; //단지수 
    cnt++;//단지수 plus
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
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    // 지도 탐색
    for (int i = 0; i < n; i++)
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
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}