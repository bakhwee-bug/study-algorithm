#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N, dp[MAX];

void input(){
    cin >> N;
    for(int i = 2;i<=N;i++){
        vector<int> v;
        if(i%2 == 0){
            v.push_back(1+dp[i/2]);
        }
        if(i%3 == 0){
            v.push_back(1+dp[i/3]);
        }
        v.push_back(1+dp[i-1]);
        dp[i] = *min_element(v.begin(), v.end());
    }
    cout << dp[N];
}


int main(){
    input();
    return 0;
}

