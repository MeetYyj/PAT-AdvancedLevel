#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int graph[1001][1001];
bool iscollected[1001];
int mhid = 0;
int num;
int cnttmp = 0;
void dfs(int root){
    iscollected[root] = true;
    cnttmp++;
    for (int i = 1; i <= mhid; ++i) {
        if(graph[root][i]){
            for (int j = 1; j <= num; ++j) {
                if(!iscollected[j] && graph[j][i]){
                    dfs(j);
                }
            }
        }
    }

}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1107/in1107", "r", stdin);
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int hnum;
        scanf("%d:", &hnum);
        for (int j = 0; j < hnum; ++j) {
            int hid;
            scanf("%d", &hid);
            if(hid > mhid){
                mhid = hid;
            }
            graph[i][hid] = 1;
        }
    }
    int cnum = 0;
    vector<int> cnumall;
    for (int i = 0; i < num; ++i) {
        if(!iscollected[i]){
            cnum++;
            dfs(i);
            cnumall.push_back(cnttmp);
            cnttmp = 0;
        }
    }
    sort(cnumall.rbegin(), cnumall.rend());
    printf("%ld\n", cnumall.size());
    for (int i = 0; i < cnumall.size(); ++i) {
        if(i)
            printf(" ");
        printf("%d", cnumall[i]);
    }
//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < 11; ++j) {
//            printf("%d ", graph[i][j]);
//        }
//        cout << endl;
//    }
    return 0;
}