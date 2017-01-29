#include <iostream>
#include <vector>
#define inf 999999999
using namespace std;
int graph[501][501];
int isvisited[501];
int dist[501];
vector<int> path[501];
int bikenum[501];
int cmax, nums, spro, roads;
vector<int> finalpath, tmppath;
int minsend = inf, minback = inf;

void dijkstra(){
    dist[0] = 0;
    path[0].push_back(-1);
    while(1) {
        int minsidt = inf, minindex = -1;
        for (int i = 0; i <= nums ; ++i) {
            if(!isvisited[i] && dist[i] < minsidt){
                minsidt = dist[i];
                minindex = i;
            }
        }
        isvisited[minindex] = true;
        if(minindex == -1){
            break;
        }
        for (int i = 0; i <= nums; ++i) {
            if(graph[minindex][i] != inf && !isvisited[i]){
                if(dist[minindex] + graph[minindex][i] < dist[i]){
                    dist[i] = dist[minindex] + graph[minindex][i];
                    path[i].clear();
                    path[i].push_back(minindex);
                } else if(dist[minindex] + graph[minindex][i] == dist[i]){
                    path[i].push_back(minindex);
                }

            }
        }
    }
}
void dfs(int v){
    if(v == 0){
        tmppath.push_back(v);
        int tmpsend = 0, tmpback = 0;
        int midbike = cmax/2;
        for (int i = tmppath.size() - 2; i >= 0; --i) {
            if(bikenum[tmppath[i]] >= midbike){
                tmpback += bikenum[tmppath[i]] - midbike;
            } else if (tmpback >= (midbike - bikenum[tmppath[i]])){
                tmpback -= midbike - bikenum[tmppath[i]];
            } else{
                tmpsend += midbike - bikenum[tmppath[i]] - tmpback;
                tmpback = 0;
            }
        }
        if(tmpsend < minsend){
            minback = tmpback;
            minsend = tmpsend;
            finalpath = tmppath;
        }else if(tmpsend == minsend && tmpback < minback){
            minback = tmpback;
            finalpath = tmppath;
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(v);
    for (int i = 0; i < path[v].size(); ++i) {
        dfs(path[v][i]);
    }
    tmppath.pop_back();
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1018/in1018", "r", stdin);
    for (int i = 0; i < 501; ++i) {
        isvisited[i] = false;
        dist[i] = inf;
        bikenum[i] = 0;
        for (int j = 0; j < 501; ++j) {
            graph[i][j] = inf;
        }
    }
    scanf("%d %d %d %d\n", &cmax, &nums, &spro, &roads);
    for (int i = 0; i < nums; ++i) {
        scanf("%d", &bikenum[i + 1]);
    }
    for (int i = 0; i < roads; ++i) {
        int v1, v2, tmpdist;
        scanf("%d%d%d", &v1, &v2, &tmpdist);
        graph[v1][v2] = tmpdist;
        graph[v2][v1] = tmpdist;
    }

//    for (int i = 0; i <= nums; ++i) {
//        for (int j = 0; j <= nums; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
    dijkstra();
//    for (int i = 0; i <= nums; ++i) {
//        for (int j = 0; j < path[i].size(); ++j) {
//            cout << path[i][j] << " ";
//        }
//        cout << endl;
//    }
    dfs(spro);
    printf("%d ", minsend);
    printf("0");
    for (int i = finalpath.size() - 2; i >= 0; --i) {
        printf("->%d", finalpath[i]);
    }
    printf(" %d", minback);
    return 0;
}