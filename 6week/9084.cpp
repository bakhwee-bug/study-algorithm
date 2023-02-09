#include <iostream>
#include <string>
#define MAX 21
#define MAX2 10001
using namespace std;

int T,N,M;

int main(){
    cin >> T;//테스트 케이스 입력 받기
    for(int k=0;k<T;k++){
        int coin[MAX]={0};
        int arr[MAX][MAX2]={0};
        cin >> N; //동전의 가지 수(1~20)
        for(int i=1;i<=N;i++){
            cin >> coin[i];//N가지 동전의 각 금액(1~10000)
        }
        cin >> M;//주어진 N가지 동전으로 만들어야 할 금액 M(1 ≤ M ≤ 10000)
        
        for(int i=1;i<=N;i++){
            arr[coin[i]][0]=1;
            for(int j=1;j<=M;j++){
                if(j<coin[i]){
                    arr[coin[i]][j]=arr[coin[i-1]][j];
                }
                else{
                    arr[coin[i]][j] = arr[coin[i-1]][j] + arr[coin[i]][j-coin[i]];
                }
            }
        }
        cout<<arr[coin[N]][M]<<"\n";
    }
    
    return 0;
}
