#include <iostream>
#include <string>
#define MAX 81
using namespace std;

int T;



int main(){
    
    cin >> T;//테스트 케이스 입력 받기
    for(int i=0;i<T;i++){
        string OX;
        cin >> OX;//OXOXO입력받기
        char arr[MAX]={0};
        int sum =0;
        for(int j=0;j<OX.length();j++){
            if(OX.substr(j,1)=="O"){
                arr[j]++;
                if(j>0 && arr[j-1]>0){
                    arr[j]+=arr[j-1];
                }
            }
            sum+=arr[j];
        }
        
        cout << sum <<"\n";
    }
    
    return 0;
}
