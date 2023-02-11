//시간복잡도 O(N*M)

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;


int M,N;
int tomato[MAX][MAX];//토마토 지도
int noripen, day;//익지 않은 토마토 개수, 날짜
deque<pair<int,int>> q; //탐색할 때 쓸 큐.

int dx[4] = { -1, 1, 0, 0 };// 상, 하, 좌, 우로 가기 위한 배열
int dy[4] = { 0, 0, -1, 1 };// 상, 하, 좌, 우로 가기 위한 배열


//M,N 입력받고 토마토 배열 입력받는 함수
void input(){
    cin >>M>>N;
    noripen = 0;//익지 않은 토마토 개수
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> tomato[i][j];
            //0이면 익지 않은 토마토로 count
            if(tomato[i][j] == 0){
                noripen++;
            }
            //1이면 큐에 집어넣고 방문체크 해주기
            if(tomato[i][j] == 1){
                q.push_back({i,j});
            }
        }
    }
}

void graph(){

    while(!q.empty()){
        deque<pair<int,int>> q2; //날짜 세기 위한 큐
        while (!q.empty()){
            int front_x = q.front().first; //큐에서 맨 앞에 있는 거 x좌표
            int front_y = q.front().second;//큐에서 맨 앞에 있는 거 y좌표
            q.pop_front(); //삭제 해줌
            for (int i = 0; i < 4; i++)
            {
                // next_x, next_y는 다음으로 push할 인덱스 후보
                int next_x = front_x + dx[i];
                int next_y = front_y + dy[i];
                if (0 < next_x && next_x <=N && 0 < next_y && next_y <= M // 범위는 지도를 넘어가면 안됨
                     && tomato[next_x][next_y] == 0) //next 좌표가 토마토가 0상태라면
                {
                    noripen--;
                    q2.push_back(make_pair(next_x, next_y));//push해줌
                    tomato[next_x][next_y] = 1;// 이제 익은 토마토가 될 거니까 1로 바꿔줌.
                }
            }
        }
        day++;
        q=q2;
    }
    
    day--;
    
    
    
    if(noripen > 0){ //익지 않은 토마토가 있다면
        cout << "-1\n";
    }
    else{
        cout << day << "\n";
    }
}


int main(){
    input();
    graph();
    return 0;
}
