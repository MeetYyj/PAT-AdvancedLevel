#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;
vector<int> iv[100];
int maxlevel = -1;
int level[100];
int res[100];

void bfs(){
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while (!q.empty()){
        int idtmp = q.front();
        q.pop();
        maxlevel = max(maxlevel, level[idtmp] + 1);
        if (iv[idtmp].size() == 0){
            res[level[idtmp]]++;
        }
        for (int i = 0; i < iv[idtmp].size(); ++i) {
            q.push(iv[idtmp][i]);
            level[iv[idtmp][i]] = level[idtmp] + 1;
        }
    }

}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1004/in1004", "r", stdin);
    int num, times;
    scanf("%d %d", &num, &times);
    for (int i = 0; i < times; ++i) {
        int id, childrenNum;
        scanf("%d %d", &id, &childrenNum);
        for (int j = 0; j < childrenNum; ++j) {
            int childID;
            scanf("%d", &childID);
            iv[id].push_back(childID);
        }
    }

//    for (int l = 0; l < times; ++l) {
//        for (int i = 0; i < iv[l]; ++i) {
//
//        }
//    }
    bfs();
    for (int k = 0; k < maxlevel; ++k) {
        if (k != 0)
            printf(" ");
        printf("%d", res[k]);
    }
    return 0;
}