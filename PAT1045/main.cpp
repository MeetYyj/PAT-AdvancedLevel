#include <iostream>
#include <vector>
#include <map>
using namespace std;
int book[201];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1045/in1045", "r", stdin);
    int num;
    scanf("%d", &num);
    int favoritenum;
    scanf("%d", &favoritenum);
    for (int i = 1; i <= favoritenum; ++i) {
        int tmp;
        scanf("%d", &tmp);
        book[tmp] = i;
    }
    int allnum;
    scanf("%d", &allnum);
    vector<int> allvec;
    for (int i = 0; i < allnum; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if(book[tmp] >= 1)
            allvec.push_back(book[tmp]);
    }
    int dp[10001];
    int maxlen = 0;
    for (int i = 0; i < allvec.size(); ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if(allvec[j] <= allvec[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        maxlen = max(maxlen, dp[i]);
    }
    printf("%d", maxlen);




//    for (int i = 0; i < ivec.size(); ++i) {
//        cout << ivec[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < allvec.size(); ++i) {
//        cout << allvec[i] << " ";
//    }
//    cout << endl;

    return 0;
}