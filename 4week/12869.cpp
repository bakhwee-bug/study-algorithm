#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX 61
using namespace std;

// 시간복잡도
// 공간복잡도
// 어려웠던 점: 조합. / 방문 체크 배열 어떻게 쓸 지.
/**********************************
이 문제도 앞 2문제와 비슷하게 풀면 된다고 생각.
다만 순열을 써야 하는 것이 차이점?

큐에 배열 넣고 각 경우마다 -9 -3 -1 해서 다 넣음
-이면 0으로 바꿔줌
다 0이면 탐색 중지
**********************************/

int N;//입력 받을 체력 수
bool visited[MAX][MAX][MAX];//방문 체크 배열

struct NODE {
    int scv[3];
    int depth;
};//체력 3개랑 노드 층 넣어 줄 구조체 생성

NODE node;
deque<NODE> q; //노드를 넣는 덱 생성

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> node.scv[i];
    }
    
    node.depth = 0;
}//체력 입력받는 함수

int iszero(int a) {
    if (a <= 0) return 0;
    else return a;
}//0보다 작으면 0으로 만들어주는 함수

void bfs(NODE hp)
{
    q.push_back(hp);
    visited[hp.scv[0]][hp.scv[1]][hp.scv[2]] = true;//방문 체크
    
    sort(hp.scv[0], hp.scv[2]); // 오름차순 정렬

    do {
        while (!q.empty()) {
            NODE s = q.front();
            q.pop_front();
            for (int i = 0; i < 3; i++) {
                s.scv[i] = iszero[s.scv[i]];
            }
            
        }
    } while (next_permutation(hp.scv[0], hp.scv[2]));

}

int main()
{
  
    return 0;
}