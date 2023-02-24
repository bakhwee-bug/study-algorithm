#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int r,c;
int map[MAX][MAX];
bool visited[MAX][MAX];
int cnt;

int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};// ��, ��, ��, ��, �밢������ ���� ���� �迭
int dy[8] = { 0, 0, -1, 1, -1, -1, 1, 1};// ��, ��, ��, ��, �밢���� ���� ���� �迭

void island(int i, int j){
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int front_x = q.front().first; //ť���� �� �տ� �ִ� �� x��ǥ
        int front_y = q.front().second;//ť���� �� �տ� �ִ� �� y��ǥ
        q.pop(); //���� ����
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
        cin >> r >> c; //���� ����
        if(r==0 && c==0){//�Ѵ� 0�̸� ����
            break;
        }
        else{//���� �Է� �ޱ�
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

