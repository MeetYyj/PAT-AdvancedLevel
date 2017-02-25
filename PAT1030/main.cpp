#include <iostream>
#include <vector>
#include <algorithm>
#define maxx 1<<30
using namespace std;
struct wayinfo{
    int len;
    int cost;
};
wayinfo graph[501][501];
vector<int> path[501];
int dist[501];
bool iscollected[501];
int city, street, st, dst;
void dijkstra(){
    for (int i = 0; i < city; ++i) {
        dist[i] = maxx;
        iscollected[i] = false;
    }
    dist[st] = 0;
    while(1){
        int mindis = maxx, minindex = -1;
        for (int i = 0; i < city; ++i) {
            if(!iscollected[i] && dist[i] < mindis){
                mindis = dist[i];
                minindex = i;
            }
        }
        if(minindex == -1){
            break;
        }
        iscollected[minindex] = true;
        for (int i = 0; i < city; ++i) {
            if(!iscollected[i] && graph[minindex][i].len != 0){
                if(graph[minindex][i].len + dist[minindex] < dist[i]){
                    dist[i] = graph[minindex][i].len + dist[minindex];
                    path[i].clear();
                    path[i].push_back(minindex);
                }else if(graph[minindex][i].len + dist[minindex] == dist[i]){
                    path[i].push_back(minindex);
                }
            }
        }
    }
};
vector<vector<int>> allpath;
vector<int> tmppath;
void dfs(int index){
    if(index == st){
        tmppath.push_back(index);
        allpath.push_back(tmppath);
        tmppath.pop_back();
    }else{
        tmppath.push_back(index);
        for (int i = 0; i < city; ++i) {
            if(graph[index][i].len != 0){
                dfs(i);
            }
        }
        tmppath.pop_back();
    }
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1030/in1030", "r", stdin);
    scanf("%d%d%d%d", &city, &street, &st, &dst);
    for (int i = 0; i < street; ++i) {
        int v1, v2, tmplen, tmpcost;
        scanf("%d%d%d%d", &v1, &v2, &tmplen, &tmpcost);
        graph[v1][v2].len = tmplen;
        graph[v1][v2].cost = tmpcost;
        graph[v2][v1].len = tmplen;
        graph[v2][v1].cost = tmpcost;
    }
    dijkstra();
    dfs(dst);
    for (int i = 0; i < allpath.size(); ++i) {
        for (int j = 0; j < allpath[i].size(); ++j) {
            cout << allpath[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}