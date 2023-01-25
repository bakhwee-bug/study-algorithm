#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000001
using namespace std;

// 시간복잡도
// 공간복잡도
// 어려웠던 점: 
/**********************************
F: 스타트링크 총 수 <= 1,000,000
S: 지금 있는 층 >= 1
G: 스타트링크가 있는 곳의 위치 <= 1,000,000
U: 0 <= 위층으로 얼마나 가는 지 <= 1,000,000
D: 0 <= 아래층으로 얼마나 가는 지 <= 1,000,000

S층에서 G층으로 가기 위해 눌러야 하는 버튼의 수의 최솟값

 s + ( N * u ) - ( M * d ) = g
 N + M이 최솟값 되는 걸 구하면 됨
 -> 처음에 이렇게 수학적으로 접근했다가 bfs를 써야한다고 깨닫게 됨


**********************************/

int f, s, g, u, d;


void input() {
    cin >> f >> s >> g >> u >> d;//수 5개 입력 받는다.
}

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
        //스타트링크가 있는 층이 나오면 몇번째 층의 노드인 지를 출력하고 while문 끝내기.
        if (a == g) {
            cout << cnt;
            return;
        }
        //현재 층에서 +u / -d 간 층이 층 범위 안에 있고 방문 안 했으면 큐에 넣어주기.
        if (a + u >= 1 && a + u <= f) {
            if (!visited[a + u]) {
                visited[a + u] = true;
                q.push(make_pair(a + u, cnt + 1));
            }
        }
        if (a - d >= 1 && a - d <= f) {
            if (!visited[a - d]) {
                visited[a - d] = true;
                q.push(make_pair(a - d, cnt + 1));
            }
        }
    }
    
    cout << "use the stairs";
    
    
}

int main()
{
    input();
    bfs(s);

    return 0;
}