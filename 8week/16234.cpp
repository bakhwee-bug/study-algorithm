#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 51
using namespace std;

int N, L, R, day;
int A[MAX][MAX];
bool visited[MAX][MAX] = {false};
deque<pair<int, int>> q; //Ž���� �� �� ť

int dx[4] = { -1, 1, 0, 0 };// ��, ��, ��, ��� ���� ���� �迭
int dy[4] = { 0, 0, -1, 1 };// ��, ��, ��, ��� ���� ���� �迭

void input(){
    //N, L, R �Է¹ޱ�
    cin >> N >> L >> R;
    //�α� �� �Է¹ޱ�
    for(int i = 1; i<=N ; i++){
        for(int j = 1;j<=N;j++){
            cin >> A[i][j];
        }
    }
}

void bfs(int r, int c){
    //ť�� �ִ´�.
    q.push_back(make_pair(r, c));
    //���� �� �� ? �� ť
    deque<pair<int, int>> q2;
    //�� ������
    while(!q.empty()){
        int front_x = q.front().first; //ť���� �� �տ� �ִ� �� x��ǥ
        int front_y = q.front().second; //ť���� �� �տ� �ִ� �� y��ǥ
        q.pop_front(); //���� ����
        //���� �¿� ����
        for(int i = 0;i<4;i++){
            // next_x, next_y�� �������� push�� �ε��� �ĺ�
            int next_x = front_x + dx[i];
            int next_y = front_y + dy[i];
            int sub = abs(A[front_x][front_y] - A[next_x][next_y]);
            if(0<next_x && next_x<=N && 0<next_y&&next_y<=N && L<=sub && sub<=R && visited[next_x][next_y] == 0){
                //������ ���� ���̰�,���̰� L�̻�R�����̰�, �湮 �� ������
                q.push_back(make_pair(next_x, next_y)); //ť�� �ֱ�
                visited[next_x][next_y] = true;//�湮 üũ
            }
        }
        //q2�� front ��ǥ ����(���� ����?�� �ִ� ������ ���� �ε��� ��� �����ϱ� ���ؼ�)
        q2.push_back(make_pair(front_x, front_y));
    }
    //q2����� 1���� Ŀ�� ���漱�� �� ���� �ִ� ���̹Ƿ� ���� �߰�.
    if(q2.size()>1){
        //sum ���ϱ�
        int sum=0;
        //q2�� ����ִ� ������� �α� �� �� ���ϱ�
        for(int i=0;i<q2.size();i++){
            sum+=A[q2[i].first][q2[i].second];
        }
        //���� �� ���� ���� ������
        int move = sum/q2.size();
        //q2�� �ִ� ������ �α����� ���� ���� �� �ٲٱ�
        while(!q2.empty()){
            A[q2.front().first][q2.front().second] = move;
            //q2���� �� ����
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
        //�Ϸ� ��
        //cnt�� N*N�̸� �α� �̵� �� ���� ���ٴ� ���̹Ƿ� while���� �����.
        if(cnt == N*N) break;
        else{
            day++;
        }
        //�湮 üũ �迭 �ʱ�ȭ �ؾ� ��.
        for(int r = 1;r<=N;r++){
            for(int c=1;c<=N;c++){
                    visited[r][c]=false;
            }
        }
    }
    //day ���
    cout << day;
    return 0;
}
