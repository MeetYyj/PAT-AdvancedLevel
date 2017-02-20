#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int num;
double price, rate, sump = 0;
bool isretailers[100001];
vector<int> vec[100001];
void dfs(int index, int level){
    if(isretailers[index]){
        sump += price * vec[index][0] * pow((1 + rate/100), level);
    }else{
        for (int i = 0; i < vec[index].size(); ++i) {
            dfs(vec[index][i], level + 1);
        }
    }
    return;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1079/in1079", "r", stdin);
    scanf("%d %lf %lf\n", &num, &price, &rate);
    for (int i = 0; i < num; ++i) {
        int tmpnum;
        scanf("%d", &tmpnum);
        if(tmpnum == 0){
            isretailers[i] = true;
            int tmp;
            scanf("%d", &tmp);
            vec[i].push_back(tmp);
        } else{
            for (int j = 0; j < tmpnum; ++j) {
                int tmp;
                scanf("%d", &tmp);
                vec[i].push_back(tmp);
            }
        }
    }
    dfs(0, 0);
    printf("%.1lf", sump);
//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < vec[i].size(); ++j) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}