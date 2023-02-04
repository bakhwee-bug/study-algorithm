/*#include<iostream>
#include<algorithm>
using namespace std;
 
int n;

int main() {
    int t;
    cin >> t;
    int cnt=0;
    
    for(int j=0;j<t;j++){
        cin >> n;
        string S; // 단어 S
        cin >> S;
     
        int alp[26] = { 0, }; // 알파벳 개수 담는 배열
     
        for (int i = 0; i < n; i++)
        {
            alp[S[i] - 'a'] +=1;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if(alp[i]!=0){
                cnt++;
            }
        }
        cout << cnt << "\n";
        
    }
    return 0;
}
*/
