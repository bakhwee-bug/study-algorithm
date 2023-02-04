/*#include <iostream>
#include <string>
using namespace std;

int t,n;

string st;
char ch[51];

void FD(){
    cin >> t;
    for(int i =0;i<t;i++){
        int x=0, y=0;
        cin >> n;
        cin >> st;
        strcpy(ch,st.c_str());
        for(int j=0;j<n;j++){
            if(ch[j] == 'U') y++;
            else if(ch[j]=='R') x++;
            else if(ch[j]=='L') x--;
            else if(ch[j]=='D') y--;
            if(x==1 && y==1){
                cout << "YES"<<"\n";
                break;
            }
        }
        if(x!=1 || y!=1){cout << "NO"<<"\n";}
    }
    
}




int main(){
    FD();
    return 0;
}
*/
