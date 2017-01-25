#include <iostream>
#include <queue>

using namespace std;
int graph[1001][1001];
bool isvisited[1001];
int cities, roads, numk;

void bfs(int occupyCity){
    fill(isvisited, isvisited+1001, false);
    int cnt = -1;
    queue<int> q;
    isvisited[occupyCity] = true;
    for (int i = 1; i <= cities; ++i) {
        if(!isvisited[i]){
            q.push(i);
            isvisited[i] = true;
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                for (int j = 1; j <= cities; ++j) {
                    if(!isvisited[j] && graph[tmp][j] == 1){
                        q.push(j);
                        isvisited[j] = true;
                    }
                }
            }
            cnt++;
        }
//        if(isvisited[i])
//            cnt--;

    }
    printf("%d\n", cnt);
}
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1013/in1013", "r", stdin);
    fill(graph[0], graph[1001], 0);
    scanf("%d%d%d", &cities, &roads, &numk);
    for (int i = 0; i < roads; ++i) {
        int v1,v2;
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    for (int i = 0; i < numk; ++i) {
        int occupyCity;
        scanf("%d", &occupyCity);
        bfs(occupyCity);
    }

//    for (int j = 1; j <= cities; ++j) {
//        for (int i = 1; i <= cities; ++i) {
//            cout << graph[j][i] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}