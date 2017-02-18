#include <iostream>
#include <vector>
#include <algorithm>
int dp[100001][101];
int book[100001][101];
int coins[100001];
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1068/in1068", "r", stdin);
    int num, value;
    scanf("%d%d", &num, &value);
    for (int i = 1; i <= num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        coins[i] = tmp;
    }
    sort(coins + 1, coins + num + 1, cmp);
    for (int i = 0; i <= num; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= num; ++i) {
        for (int j = coins[i]; j <= value; ++j) {
            if(dp[i - 1][j - coins[i]] == 1){
                dp[i][j] = 1;
                book[i][j] = 1;
            } else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
//    for (int i = 0; i <= num ; ++i) {
//        for (int j = 0; j <= value; ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i = 0; i <= num ; ++i) {
//        for (int j = 0; j <= value; ++j) {
//            cout << book[i][j] << " ";
//        }
//        cout << endl;
//    }

    if(dp[num][value] == 0){
        printf("No Solution\n");
    }else{
        vector<int> vout;
        while(value){
            if(book[num][value]){
                value -= coins[num];
                vout.push_back(coins[num]);
            }
            num--;
        }
        for (int i = 0; i < vout.size(); ++i) {
            if(i != 0)
                printf(" ");
            printf("%d", vout[i]);
        }
    }
    return 0;
}