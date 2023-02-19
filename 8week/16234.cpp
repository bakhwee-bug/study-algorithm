#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 51
using namespace std;

int N, L, R, day;
int A[MAX][MAX];
bool visited[MAX][MAX] = {false};
deque<pair<int, int>> q; //탐색할 때 쓸 큐

int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열

void input(){
    //N, L, R 입력받기
    cin >> N >> L >> R;
    //인구 수 입력받기
    for(int i = 1; i<=N ; i++){
        for(int j = 1;j<=N;j++){
            cin >> A[i][j];
        }
    }
}

void bfs(int r, int c){
    //큐에 넣는다.
    q.push_back(make_pair(r, c));
    //구역 셀 때 ? 쓸 큐
    deque<pair<int, int>> q2;
    //한 구역당
    while(!q.empty()){
        int front_x = q.front().first; //큐에서 맨 앞에 있는 거 x좌표
        int front_y = q.front().second; //큐에서 맨 앞에 있는 거 y좌표
        q.pop_front(); //삭제 해줌
        //상하 좌우 돈다
        for(int i = 0;i<4;i++){
            // next_x, next_y는 다음으로 push할 인덱스 후보
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            int sub = abs(A[front_x][front_y] - A[next_x][next_y]);
            if(0<next_x && next_x<=N && 0<next_y&&next_y<=N && L<=sub && sub<=R && visited[next_x][next_y] == 0){
                //범위가 지도 안이고,차이가 L이상R이하이고, 방문 안 했으면
                q.push_back(make_pair(next_x, next_y)); //큐에 넣기
                visited[next_x][next_y] = true;//방문 체크
            }
        }
        //q2에 front 좌표 저장(같은 구역?에 있는 나라의 수랑 인덱스 등등 저장하기 위해서)
        q2.push_back(make_pair(front_x, front_y));
    }
    //q2사이즈가 1보다 커야 국경선을 연 곳이 있는 것이므로 조건 추가.
    if(q2.size()>1){
        //sum 구하기
        int sum=0;
        //q2에 들어있는 나라들의 인구 수 다 더하기
        for(int i=0;i<q2.size();i++){
            sum+=A[q2[i].first][q2[i].second];
        }
        //더한 걸 나라 수로 나누기
        int move = sum/q2.size();
        //q2에 있는 나라의 인구수를 나눈 수로 다 바꾸기
        while(!q2.empty()){
            A[q2.front().first][q2.front().second] = move;
            //q2에서 다 빼기
            q2.pop_front();
        }
    }
}

int main(){
    input();
    
    while(1){
        int cnt=0;
        for(int r = 1;r<=N;r++){
            for(int c=1;c<=N;c++){
                if(visited[r][c] == false){
                    visited[r][c]=true;
                    bfs(r, c);
                    cnt++;
                }
            }
        }
        //하루 끝
        //cnt가 N*N이면 인구 이동 할 나라가 없다는 뜻이므로 while문을 멈춘다.
        if(cnt == N*N) break;
        else{
            day++;
        }
        //방문 체크 배열 초기화 해야 함.
        for(int r = 1;r<=N;r++){
            for(int c=1;c<=N;c++){
                    visited[r][c]=false;
            }
        }
    }
    //day 출력
    cout << day;
    return 0;
}
