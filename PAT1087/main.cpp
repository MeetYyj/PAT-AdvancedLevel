#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define maxx 10000000
using namespace std;
bool iscollected[201];
vector<int> path[201];
int dis[201];
int graph[201][201];
int happness[201];
map<string, int> map1;
int num, roads;

struct greatpath{
    int city = 0;
    int happninessall = 0;
    int id;
};

void dijkstra(){
    for (int i = 0; i < num; ++i) {
        dis[i] = maxx;
    }

    int dismin = maxx;
    for (int i = 0; i < num; ++i) {
        if(graph[0][i] != maxx){
            dis[i] = graph[0][i];
            path[i].push_back(0);
        }
    }
    iscollected[0] = true;
    for (int i = 0; i < num; ++i) {
        dismin = maxx;
        int minindex = -1;
        for (int j = 0; j < num; ++j) {
            if(!iscollected[j] && dis[j] < dismin){
                dismin = dis[j];
                minindex = j;
            }
        }
        if(minindex == -1){
            break;
        } else{
            iscollected[minindex] = true;
            for (int j = 0; j < num; ++j) {
                if(!iscollected[j] && graph[minindex][j] + dis[minindex] < dis[j]){
                    dis[j] = graph[minindex][j] + dis[minindex];
                    path[j].clear();
                    path[j].push_back(minindex);
                }else if(!iscollected[j] && graph[minindex][j] + dis[minindex] == dis[j]){
                    path[j].push_back(minindex);
                }
            }

        }
    }
}

vector<vector<int>> outpath;
vector<int> tmppath;
int pathcnt;
void dfs(int index){
    if(index == 0){
        outpath[pathcnt].push_back(index);
        pathcnt++;
        outpath.push_back(tmppath);
        return;
    }
    for (int i = 0; i < path[index].size(); ++i) {
        outpath[pathcnt].push_back(index);
        dfs(path[index][i]);
    }
}

bool sort1(const greatpath &a, const greatpath &b){
    if(a.happninessall != b.happninessall){
        return a.happninessall > b.happninessall;
    }else{
        return a.city < b.city;
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1087/in1087", "r", stdin);
    char start[4], tmp[4];
    scanf("%d %d %s\n", &num, &roads, start);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if(i != j )
                graph[i][j] = maxx;
        }
    }
    int cnt = 0;
    vector<string> name;
    name.push_back(start);
    map1[start] = cnt++;
    for (int i = 1; i < num; ++i) {
        scanf("%s %d\n", tmp, &happness[i]);
        map1[tmp] = cnt++;
        name.push_back(tmp);
    }
    for (int i = 0; i < roads; ++i) {
        char v1[4], v2[4];
        int miles;
        scanf("%s %s %d\n", v1, v2, &miles);
        graph[map1[v1]][map1[v2]] = miles;
        graph[map1[v2]][map1[v1]] = miles;
    }
    dijkstra();
//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < num; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
//    for (int i = 0; i < num; ++i) {
//        cout << dis[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < path[i].size(); ++j) {
//            cout << path[i][j] << " ";
//        }
//        cout << endl;
//    }
    int indexROM = map1["ROM"];
    int cost = dis[map1["ROM"]];
    outpath.push_back(tmppath);
    dfs(indexROM);
    vector<greatpath> vecgreatpath;
    for (int i = 0; i < pathcnt; ++i) {
        greatpath tmpgp;
        tmpgp.id = i;
        tmpgp.city = (int)outpath[i].size() - 1;
        for (int j = 0; j < outpath[i].size(); ++j) {
            tmpgp.happninessall += happness[outpath[i][j]];
        }
        vecgreatpath.push_back(tmpgp);
    }
    sort(vecgreatpath.begin(), vecgreatpath.end(), sort1);
    printf("%d %d %d %d\n", pathcnt, cost, vecgreatpath[0].happninessall, vecgreatpath[0].happninessall / vecgreatpath[0].city);
    vector<int> finalvec = outpath[vecgreatpath[0].id];
    for (int i = 0; i < finalvec.size(); ++i) {
        if(i != 0){
            printf("->");
        }
        cout << name[finalvec[finalvec.size() - 1 -i]];
    }
    return 0;
}