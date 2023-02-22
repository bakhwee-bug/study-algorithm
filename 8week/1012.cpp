#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int dp[MAX][MAX];
bool visited[MAX][MAX];
int T,M,N,K;
deque<pair<int, int>> q;
int cnt;

int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열

void dynamic(int j, int l){
    q.push_back({j,l});
    visited[j][l]=true;
    while(!q.empty()){
        int front_x = q.front().second;
        int front_y = q.front().first;
        q.pop_front();
        for(int i=0;i<4;i++){
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            if(0<=next_x && next_x<M && 0<=next_y && next_y<N && dp[next_y][next_x] == 1 && visited[next_y][next_x]==false){
                q.push_back({next_y, next_x});
                visited[next_y][next_x]=true;
            }
        }
    }
    cnt++;
}
void input(){
    cin >> T;
    for(int i=1;i<=T;i++){
        cnt = 0; //cnt초기화
        //방문체크 배열이랑 양배추 밭 초기화
        for(int j=0;j<N;j++){
            for(int l=0;l<M;l++){
                dp[j][l]=0;
                visited[j][l]=false;
            }
        }
        //가로 세로 좌표 개수 입력받기
        cin >> M >> N >> K;
        for(int j=1;j<=K;j++){
            //양배추 심을 좌표 K번만큼 입력받고 1 넣어주기
            int x,y;
            cin >> x >> y;
            dp[y][x] = 1;
        }
        for(int j=0;j<N;j++){
            for(int l=0;l<M;l++){
                //다 돌면서 양배추 심어져있고 방문 안 했으면 함수 돌리기
                if(dp[j][l]==1&&visited[j][l]==false){
                    dynamic(j,l);
                }
            }
        }
        cout << cnt << "\n";
    }
}

int main() {
    input();
    return 0;
}


