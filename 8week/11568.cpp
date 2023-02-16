#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N; //민균이가 제시한 카드 개수
int num[MAX];//입력 받을 카드 수
int dp[MAX];//앞에 자신보다 큰 수 나오면 dp

void input(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }
}

void dynamic(){
    for(int i = 1;i<=N;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(num[i]>num[j] && dp[i]<=dp[j]){
                dp[i] = dp[j]+1;
            }
        }
    }
    int max = *max_element(begin(dp),end(dp));
    cout << max;
}



int main(){
    input();
    dynamic();
    return 0;
}

