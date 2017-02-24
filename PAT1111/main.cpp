#include <iostream>
#include <vector>
#include <algorithm>
#define maxx 100000000
using namespace std;
struct vertex{
    int lengthcost;
    int timecost;
};
vertex graph[501][501];
bool iscollectedlen[501];
bool iscollectedtime[501];

int distlen[501];
int disttime[501];
vector<int> pathlen[501];
vector<int> pathtime[501];
int num, streets;

void dijkstra(int st){
    for (int i = 0; i < num; ++i) {
        distlen[i] = maxx;
        disttime[i] = maxx;
    }
    iscollectedlen[st] = true;
    iscollectedtime[st] = true;

    for (int i = 0; i < num; ++i) {
        if(graph[st][i].lengthcost != 0){
            pathlen[i].push_back(st);
            distlen[i] = graph[st][i].lengthcost;
//            if(distlen[i] < minlen){
//                minlen = distlen[i];
//                minlenindex = i;
//            }
        }
        if(graph[st][i].timecost != 0){
            pathtime[i].push_back(st);
            disttime[i] = graph[st][i].timecost;
//            if(disttime[i] < mintime){
//                mintime = disttime[i];
//                mintimeindex = i;
//            }
        }
    }

    while(1){
        int minlen = maxx;
        int minlenindex = -1;
        for (int i = 0; i < num; ++i) {
            if(!iscollectedlen[i] && distlen[i] < minlen){
                minlen = distlen[i];
                minlenindex = i;
            }
        }
        if(minlenindex == -1){
            break;
        }else{
            iscollectedlen[minlenindex] = true;
            for (int i = 0; i < num; ++i) {
                if(!iscollectedlen[i] && graph[minlenindex][i].lengthcost != 0){
                    if(graph[minlenindex][i].lengthcost + distlen[minlenindex] < distlen[i]){
                        distlen[i] = graph[minlenindex][i].lengthcost + distlen[minlenindex];
                        pathlen[i].clear();
                        pathlen[i].push_back(minlenindex);
                    }else if(graph[minlenindex][i].lengthcost + distlen[minlenindex] == distlen[i]){
                        pathlen[i].push_back(minlenindex);
                    }
                }
            }
        }
    }

    while(1){
        int mintime = maxx;
        int mintimeindex = -1;
        for (int i = 0; i < num; ++i) {
            if(!iscollectedtime[i] && disttime[i] < mintime){
                mintime = disttime[i];
                mintimeindex = i;
            }
        }
        if(mintimeindex == -1){
            break;
        }else{
            iscollectedtime[mintimeindex] = true;
            for (int i = 0; i < num; ++i) {
                if(!iscollectedtime[i] && graph[mintimeindex][i].timecost != 0){
                    if(graph[mintimeindex][i].timecost + disttime[mintimeindex] < disttime[i]){
                        disttime[i] = graph[mintimeindex][i].timecost + disttime[mintimeindex];
                        pathtime[i].clear();
                        pathtime[i].push_back(mintimeindex);
                    }else if(graph[mintimeindex][i].timecost + disttime[mintimeindex] == disttime[i]){
                        pathtime[i].push_back(mintimeindex);
                    }
                }
            }
        }
    }
}
int curr, dest;
vector<vector<int>> finallen;
vector<int> tmplenv;
void dfslen(int root){
    if(root == curr){
        tmplenv.push_back(curr);
        finallen.push_back(tmplenv);
        tmplenv.pop_back();
    }else{
        tmplenv.push_back(root);
        for (int i = 0; i < pathlen[root].size(); ++i) {
            dfslen(pathlen[root][i]);
        }
        tmplenv.pop_back();
    }
}


vector<vector<int>> finaltime;
vector<int> tmptimev;
void dfstime(int root){
    if(root == curr){
        tmptimev.push_back(curr);
        finaltime.push_back(tmptimev);
        tmptimev.pop_back();
    }else{
        tmptimev.push_back(root);
        for (int i = 0; i < pathtime[root].size(); ++i) {
            dfstime(pathtime[root][i]);
        }
        tmptimev.pop_back();
    }
}

bool sortlen(const vector<int> &a, const vector<int> &b){
    int suma = 0, sumb = 0;
    for (int i = (int)a.size() - 1; i > 0; --i) {
        suma += graph[a[i]][a[i - 1]].timecost;
    }
    for (int i = (int)b.size() - 1; i > 0; --i) {
        sumb += graph[b[i]][b[i - 1]].timecost;
    }
//    cout << suma << endl;
    return suma < sumb;
}

bool sorttime(const vector<int> &a, const vector<int> &b){
    return a.size() < b.size();
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1111/in1111", "r", stdin);
    scanf("%d %d\n", &num, &streets);
    for (int i = 0; i < streets; ++i) {
        int v1, v2, isoneway, tlen, ttime;
        scanf("%d %d %d %d %d", &v1, &v2, &isoneway, &tlen, &ttime);
        if(isoneway){
            graph[v1][v2].lengthcost = tlen;
            graph[v1][v2].timecost = ttime;
        }else{
            graph[v1][v2].lengthcost = tlen;
            graph[v1][v2].timecost = ttime;
            graph[v2][v1].lengthcost = tlen;
            graph[v2][v1].timecost = ttime;
        }
    }
    scanf("%d %d", &curr, &dest);
    dijkstra(curr);
    dfslen(dest);
    dfstime(dest);
    sort(finallen.begin(), finallen.end(), sortlen);
    sort(finaltime.begin(), finaltime.end(), sorttime);
    if(finaltime[0] == finallen[0]){
        printf("Distance = %d; Time = %d: ", distlen[dest], disttime[dest]);
        for (int i = finallen[0].size() - 1; i >= 0; --i) {
            printf("%d", finallen[0][i]);
            if(i){
                printf(" -> ");
            }

        }
    }else{
        printf("Distance = %d: ", distlen[dest]);
        for (int i = finallen[0].size() - 1; i >= 0; --i) {
            printf("%d", finallen[0][i]);
            if(i){
                printf(" -> ");
            }

        }
        printf("\n");
        printf("Time = %d: ", disttime[dest]);
        for (int i = finaltime[0].size() - 1; i >= 0; --i) {
            printf("%d", finaltime[0][i]);
            if(i){
                printf(" -> ");
            }

        }
    }
//    for (int i = 0; i < finallen.size(); ++i) {
//        for (int j = 0; j < finallen[i].size(); ++j) {
//            cout << finallen[i][j] << " ";
//        }
//        cout << endl;
//    }

//
//    for (int i = 0; i < finaltime.size(); ++i) {
//        for (int j = 0; j < finaltime[i].size(); ++j) {
//            cout << finaltime[i][j] << " ";
//        }
//        cout << endl;
//    }

//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < num; ++j) {
//            printf("%d ", graph[i][j].lengthcost);
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < num; ++j) {
//            printf("%d ", graph[i][j].timecost);
//        }
//        cout << endl;
//    }
//    cout << endl;
    return 0;
}