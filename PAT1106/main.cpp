#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int num;
vector<vector<int>> vec;
int level[100001];
int minlevel = 10000000;
int cnt = 0;
void dfs(int root, int l){
    level[root] = l;
    if(vec[root].size() == 0){
        if(l < minlevel){
            minlevel = l;
            cnt= 1;
        } else if(l == minlevel){
            cnt++;
        }
    }
    for (int i = 0; i < vec[root].size(); ++i) {
        dfs(vec[root][i], l + 1);
    }
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1106/in1106", "r", stdin);
    double p, r;
    scanf("%d%lf%lf", &num, &p, &r);
    vec.resize(num);
    for (int i = 0; i < num; ++i) {
        int tmpnum;
        scanf("%d", &tmpnum);
        for (int j = 0; j < tmpnum; ++j) {
            int tmp;
            scanf("%d", &tmp);
            vec[i].push_back(tmp);
        }
    }
    dfs(0, 0);
    printf("%.4lf %d", pow((r/100 + 1), minlevel) * p, cnt);
//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < vec[i].size(); ++j) {
//            cout << vec[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}