#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int r,c;
int map[MAX][MAX];
bool visited[MAX][MAX];
int cnt;

int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};// 상, 하, 좌, 우, 대각선으로 가기 위한 배열
int dy[8] = { 0, 0, -1, 1, -1, -1, 1, 1};// 상, 하, 좌, 우, 대각선로 가기 위한 배열

void island(int i, int j){
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int front_x = q.front().first; //큐에서 맨 앞에 있는 거 x좌표
        int front_y = q.front().second;//큐에서 맨 앞에 있는 거 y좌표
        q.pop(); //삭제 해줌
        for(int k=0;k<8;k++){
            int next_x = front_x + dx[k];
            int next_y = front_y + dy[k];
            if(0<next_x && next_x<=c && 0<next_y && next_y<=r && map[next_x][next_y]==1 && visited[next_x][next_y]==false){
                q.push({next_x, next_y});
                visited[next_x][next_y]=true;
            }
        }
    }
    
}

int main(){
    while(1){
        cnt = 0;
        cin >> r >> c; //가로 세로
        if(r==0 && c==0){//둘다 0이면 종료
            break;
        }
        else{//지도 입력 받기
            for(int i=1;i<=c;i++){
                for(int j=1;j<=r;j++){
                    visited[i][j] = false;
                    map[i][j]=0;
                }
            }
            for(int i=1;i<=c;i++){
                for(int j=1;j<=r;j++){
                    cin >> map[i][j];
                }
            }
        }
        for(int i=1;i<=c;i++){
            for(int j=1;j<=r;j++){
                if(map[i][j]==1 && visited[i][j]==false){
                    island(i,j);
                    cnt++;
                }
            }
        }
       
        cout << cnt << "\n";
    }
    return 0;
}

