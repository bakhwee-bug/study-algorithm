#include<iostream>
using namespace std;
//시간 복잡도 O(n)..? 
//공간 복잡도 O(1)
/*어려웠던 점: 저 5에 a를 곱해서 빼고 이런 과정을 생각해내는 것이 어려웠습니다*/ 
int main() {
    int number; // 설탕무게
    cin >> number; //설탕 무게를 입력받습니다
    int a = number / 5; //입력받은 값을 5로 나눕시다(5kg 봉지의 개수)
    int b; //b 초기화 (3kg 봉지의 개수)
    while (1)
    {
        //아래에서 a의 개수를 하나 낮추었는데 0보다 작아졌다면 정확히 N킬로그램으로 나누어 떨어지지
        //않는 경우이기 때문에 -1을 출력하고  프로그램을 종료합니다
        if (a < 0)
        {
            cout << "-1";
            return 0;
        }
        //음.. 이걸 뭐라 해야하지 그니까 5로 나눈 몫에 5를 곱해서 빼면 남은 설탕의 무게가 되겠죠?
        //그래서 그 남은 설탕의 무게를 3으로 나눴을 때 나누어 떨어지면 ~
        if ((number - (5 * a)) % 3 == 0) 
        {
            // b는 그 값을 3으로 나눈 몫이 되겠죠?
            b = (number - (5 * a)) / 3;
            break;
        }
        //만약에 3으로 안 나누어 떨어지면 a의 개수를 하나 낮추어서 
        //다시 위의 과정을 반복합니다
        a--;
    }
    cout << a + b;
    return 0;
}
