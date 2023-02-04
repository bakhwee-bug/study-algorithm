#include <iostream>
#define MAX 200001
using namespace std;

int t,n;
int arr[MAX];
int sum=0;

void NP(){
    cin >>t;
    for(int i = 0;i<t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>arr[j];
        }
        for(int j=1;j<=n;j++){
            sum+=arr[j];//원래합.
        }
        for(int j=1;j<n;j++){
            if(arr[j]<0){
                //0보다 작으면
                if(arr[j-1]>0 && abs(arr[j-1])<abs(arr[j])){//전에꺼랑 비교
                    
                    //전에꺼 마이너스로 바꾸고 내꺼 플러스로 바꾸기
                    arr[j-1]=~arr[j-1]+1;
                    arr[j]=~arr[j]+1;
                    break;
                }
                
                
                
                if(abs(arr[j+1])<abs(arr[j])){
                    //부호바꾸기
                    
                }
            }
        }
    }
}

int main(){
    NP();
    return 0;
}
