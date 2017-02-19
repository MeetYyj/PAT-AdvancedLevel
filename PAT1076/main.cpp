#include <iostream>
#include <queue>
using namespace std;
int graph[1001][1001];
bool iscollected[1001];
int layer[1001];
int num, l;
int cnt = 0;

//void dfs(int asknum, int level){
//    if(level > l){
//        return;
//    }
//    iscollected[asknum] = true;
//    cnt++;
//    for (int i = 1; i <= num ; ++i) {
//        if(graph[asknum][i] != 0 && !iscollected[i]){
//            dfs(i, level + 1);
//        }
//    }
//    return;
//}

void bfs(int index){
    queue<int> q;
    q.push(index);
    iscollected[index] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for (int i = 1; i <= num; ++i) {
            if(graph[top][i] != 0 && !iscollected[i]){
                if(layer[top] < l){
                    q.push(i);
                    cnt++;
                    iscollected[i] = true;
                    layer[i] = layer[top] + 1;
                }
            }
        }
    }

}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1076/in1076", "r", stdin);
    scanf("%d%d", &num, &l);
    for (int v = 1; v <= num; ++v) {
        int tmp;
        scanf("%d", &tmp);
        for (int j = 0; j < tmp; ++j) {
            int w;
            scanf("%d", &w);
            graph[w][v] = 1;
        }
    }
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; ++i) {
        int asknum;
        scanf("%d", &asknum);
        for (int j = 0; j < 1001; ++j) {
            iscollected[j] = false;
            layer[j] = 0;
        }
//        dfs(asknum, 0);
//        cout << cnt - 1 << endl;
        bfs(asknum);
        cout << cnt << endl;
        cnt = 0;
    }

//    for (int i = 1; i <= 200 ; ++i) {
//        for (int j = 1; j <= 200 ; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}