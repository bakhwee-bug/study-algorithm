#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
// 시간복잡도
// 공간복잡도
// 어려웠던 점: for문을 어디까지 돌릴 지 결정하는 게 어려운 거 같다.
/**********************************
처음에는 수학적으로 접근해서 너무 힘들었는데
다시 생각해보니까 그냥 모든 경우를 세어보면 되겠다고 생각해서
BFS를 해서 모든 경우를 해보면 터질수도 있지만 일단 해보자 라고 생각했다.
**********************************/

int N, K;// 입력받을 N하고 K
bool visited[MAX];//방문 체크 배열

void bfs(int floor)
{
    visited[floor] = true;
    queue<pair<int, int>> q;//층이랑 몇번째 층의 노드인 지를 쌍으로 받는 큐 생성
    q.push(make_pair(floor, 0));//0부터 시작
    while (!q.empty()) {//큐가 비지 않는 동안
        int a = q.front().first; // 몇 층인지.
        int cnt = q.front().second;//몇 번째 층의 노드인 지
        q.pop();
        //동생이 있는 층이 나오면 몇번째 층의 노드인 지를 출력하고 while문 끝내기.
        if (a == K) {
            cout << cnt;
            break;
        }
        //현재 층에서 +1, -1, *2 간 층이 층 범위 안에 있고 방문 안 했으면 큐에 넣어주기.
        if (a + 1 >= 0 && a + 1 < MAX) {
            if (!visited[a + 1]) {
                visited[a + 1] = true;
                q.push(make_pair(a + 1, cnt + 1));
            }
        }
        if (a - 1 >= 0 && a - 1 < MAX) {
            if (!visited[a - 1]) {
                visited[a - 1] = true;
                q.push(make_pair(a - 1, cnt + 1));
            }
        }
        if (2 * a >= 0 && 2 * a < MAX) {
            if (!visited[2 * a]) {
                visited[2 * a] = true;
                q.push(make_pair(2 * a, cnt + 1));
            }
        }
    }


}


int main()
{
    cin >> N >> K;
    bfs(N);

    return 0;
}