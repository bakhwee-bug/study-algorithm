#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N; //�α��̰� ������ ī�� ����
int num[MAX];//�Է� ���� ī�� ��
int dp[MAX];//�տ� �ڽź��� ū �� ������ dp

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

