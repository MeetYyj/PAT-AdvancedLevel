#include <iostream>
using namespace std;
int graph[500][500];
int team[500];
int cnt[500];
int dis[500];
int teamAll[500];
bool isVisited[500];
#define maxI 1000000

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1003/in1003", "r", stdin);
    int city, road, p1, p2;
    scanf("%d %d %d %d", &city, &road, &p1, &p2);
    //graph and team init
    for (int i = 0; i < city; ++i) {
        team[i] = 0;
        teamAll[i] = 0;
        cnt[i] = 0;
        dis[i] = maxI;
        isVisited[i] = false;
        for (int j = 0; j < city; ++j) {
            graph[i][j] = maxI;
        }
    }
    //input team and graph's roads
    for (int i = 0; i < city; ++i) {
        scanf("%d", &team[i]);
    }
    for (int i = 0; i < road; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        scanf("%d", &graph[v1][v2]);
        graph[v2][v1] = graph[v1][v2];
    }
//    for (int i = 0; i < city; ++i) {
//        for (int j = 0; j < city; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
    //dijkstra algorithm
    dis[p1] = 0;
    teamAll[p1] = team[p1];
    cnt[p1] = 1;
    for (int i = 0; i < city; ++i) {
        int vis = -1;
        int minDis = maxI;
        for(int j = 0; j < city; ++j) {
            if(!isVisited[j] && dis[j] < minDis){
                vis = j;
                minDis = dis[j];
            }
        }
        if(vis == -1)
            break;
        isVisited[vis] = true;
        for (int k = 0; k < city; ++k) {
            if(!isVisited[k] && graph[vis][k] != maxI){
                if(dis[vis] + graph[vis][k] < dis[k]){
                    dis[k] = dis[vis] + graph[vis][k];
                    cnt[k] = cnt[vis];
                    teamAll[k] = teamAll[vis] + team[k];
                } else if(dis[vis] + graph[vis][k] == dis[k]){
                    cnt[k] += cnt[vis];
                    if(teamAll[vis] + team[k] > teamAll[k])
                    teamAll[k] = teamAll[vis] + team[k];
                }
            }
        }
    }

    printf("%d %d", cnt[p2], teamAll[p2]);

    return 0;
}