#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

int dp[MAX][MAX];
bool visited[MAX][MAX];
int T,M,N,K;
deque<pair<int, int>> q;
int cnt;

int dx[4] = { -1, 1, 0, 0 };// ��, ��, ��, ��� ���� ���� �迭
int dy[4] = { 0, 0, -1, 1 };// ��, ��, ��, ��� ���� ���� �迭

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
        cnt = 0; //cnt�ʱ�ȭ
        //�湮üũ �迭�̶� ����� �� �ʱ�ȭ
        for(int j=0;j<N;j++){
            for(int l=0;l<M;l++){
                dp[j][l]=0;
                visited[j][l]=false;
            }
        }
        //���� ���� ��ǥ ���� �Է¹ޱ�
        cin >> M >> N >> K;
        for(int j=1;j<=K;j++){
            //����� ���� ��ǥ K����ŭ �Է¹ް� 1 �־��ֱ�
            int x,y;
            cin >> x >> y;
            dp[y][x] = 1;
        }
        for(int j=0;j<N;j++){
            for(int l=0;l<M;l++){
                //�� ���鼭 ����� �ɾ����ְ� �湮 �� ������ �Լ� ������
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


