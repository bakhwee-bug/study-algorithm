/*#include <iostream>
#include <string>
using namespace std;

int t,n;

string st;
char ch[2001];

void PA(){
    cin >> t;
    for(int i =0;i<t;i++){
        cin >> n;
        cin >> st;
        strcpy(ch,st.c_str());
        int cnt = n;
        
        for(int k=0;k<(n/2);k++){
            if(ch[k]!=ch[n-1-k]){
                cnt-=2;
            }
            else break;
        }
        cout << cnt<<"\n";
    }
    
}




int main(){
    PA();
    return 0;
}
*/
