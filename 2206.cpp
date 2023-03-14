#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define MAX 1001
using namespace std;

//변수들
int N, M;
int map[MAX][MAX];
int dis[MAX][MAX];
bool visited[MAX][MAX];
deque<pair<int, int>> q;//1인 것들 넣기(벽이면 넣기)
vector<int> ans; // 거리들 넣을 벡터
int cnt;

/*상하 좌우 가기 위한 배열*/
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//입력 함수
void input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        string s;
        cin >> s;
        for(int j=1;j<=M;j++){
            map[i][j]=s[j-1]-'0';
            if(map[i][j]==1){
                q.push_back({i, j});
            }
        }
    }
}

void init(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            visited[i][j] = 0;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dis[i][j]=0;
        }
    }
    dis[1][1]=1;
}

int bfs(int a, int b, int c, int d){
    deque<pair<int, int>> q2;
    q2.push_back({a, b});
    while(!q2.empty()){
        int front_x = q2.front().first;
        int front_y = q2.front().second;
        if(front_x == c && front_y == d) break;
        for(int i=0;i<4;i++){
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            
            if(next_x>0 && next_x<=N && next_y>0 && next_y<=M && map[next_x][next_y]==0 && visited[next_x][next_y]==false){
                q2.push_back({next_x, next_y});
                visited[next_x][next_y] = true;
                dis[next_x][next_y] = dis[front_x][front_y] + 1;//거리 저장
            }
            else if(next_x == c && next_y == d){
                q2.push_back({next_x, next_y});
                visited[next_x][next_y] = true;
                dis[next_x][next_y] = dis[front_x][front_y] + 1;//거리 저장
            }
            
        }
        q2.pop_front();
    }
    return dis[c][d];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    dis[1][1]=1;
    if(bfs(1,1,N,M)>0) ans.push_back(dis[N][M]);
    while(!q.empty()){
        init();//거리, 방문배열 초기화
        int one = bfs(1, 1, q.front().first, q.front().second);
        int two = bfs(q.front().first, q.front().second, N, M);
        if(one>0 && two>0) ans.push_back(dis[N][M]);
        q.pop_front();
    }
    if(ans.empty()) cout << "-1\n";
    else{
        sort(ans.begin(), ans.end());
        cout << ans[0] << "\n";
    }
    return 0;
}
