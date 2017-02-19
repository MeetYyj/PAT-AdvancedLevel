//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#define maxx 10000000
//using namespace std;
//int graph[1011][1011];
//int dis[1011][1011];
//struct gas{
//    int id;
//    double mindis;
//    double ave;
//};
//
//bool sort1(const gas &a, const gas &b){
//    if (a.mindis != b.mindis)
//        return a.mindis > b.mindis;
//    else if(a.ave != b.ave)
//        return a.ave < b.ave;
//    else
//        return a.id < b.id;
//}
//int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1072/in1072", "r", stdin);
//    int n, m, k1, ds;
//    scanf("%d%d%d%d", &n, &m, &k1, &ds);
//    for (int i = 1; i <= n + m; ++i) {
//        for (int j = 1; j <= n + m ; ++j) {
//            if(i == j){
//                graph[i][j] = 0;
//            } else{
//                graph[i][j] = maxx;
//            };
//        }
//    }
//    for (int i = 0; i < k1; ++i) {
//        char tmp1[5], tmp2[5];
//        int tmpdis;
//        scanf("%s%s%d", tmp1, tmp2, &tmpdis);
//        int v1, v2;
//        if(tmp1[0] == 'G'){
//            string ts = tmp1;
//            v1 = stoi(ts.substr(1))+ n;
//        }else{
//            string ts = tmp1;
//            v1 = stoi(ts);
//        }
//        if(tmp2[0] == 'G'){
//            string ts = tmp2;
//            v2 = stoi(ts.substr(1))+ n;
//        }else{
//            string ts = tmp2;
//            v2 = stoi(ts);
//        }
//        graph[v1][v2] = tmpdis;
//        graph[v2][v1] = tmpdis;
//    }
//    for (int i = 1; i <= n + m; ++i) {
//        for (int j = 1; j <= n + m ; ++j) {
//            dis[i][j] = graph[i][j];
//        }
//    }
//
//    for (int k = 1; k <= n + m; ++k) {
//        for (int i = 1; i <= n + m; ++i) {
//            for (int j = 1; j <= n + m ; ++j) {
//                if(dis[i][k] + dis[k][j] < dis[i][j])
//                    dis[i][j] = dis[i][k] + dis[k][j];
//            }
//        }
//    }
//
//    vector<gas> gvec;
//    for (int i = n + 1; i <= n + m ; ++i) {
//        double mindis = maxx;
//        double sumdis = 0;
//        bool flg = true;
//        for (int j = 1; j <= n ; ++j) {
//            if(dis[i][j] <= ds){
//                if(mindis > dis[i][j]){
//                    mindis = dis[i][j];
//                }
//                sumdis += dis[i][j];
////                cout << sumdis << " ";
//            }else{
//                flg = false;
//                break;
//            }
//        }
////        cout << endl;
//        if(flg){
//            gas tmpgas;
//            tmpgas.id = i - n;
//            tmpgas.ave = sumdis / n;
//            tmpgas.mindis = mindis;
//            gvec.push_back(tmpgas);
//        }
//    }
//    if(gvec.empty()){
//        printf("No Solution");
//    }else{
//        sort(gvec.begin(), gvec.end(), sort1);
//        printf("G%d\n", gvec[0].id);
//        printf("%.1lf %.1lf\n", gvec[0].mindis, gvec[0].ave);
//    }
//
//
////    for (int i = 1; i <= n + m; ++i) {
////        for (int j = 1; j <= n + m ; ++j) {
////            cout << dis[i][j] << " ";
////        }
////        cout << endl;
////    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#define maxx 10000000
using namespace std;
int graph[1011][1011];
int dis[1011][11];
bool iscollected[1011];
struct gas{
    int id;
    double mindis;
    double ave;
};

bool sort1(const gas &a, const gas &b){
    if (a.mindis != b.mindis)
        return a.mindis > b.mindis;
    else if(a.ave != b.ave)
        return a.ave < b.ave;
    else
        return a.id < b.id;
}


void dijkstra(int n, int m, int gasnum){
    for (int i = 1; i <= n + m; ++i) {
        dis[i][gasnum] = maxx;
        iscollected[i] = false;
    }
    int index = n + gasnum;
    int mindis = maxx;
    int minindex = -1;
    iscollected[index] = true;
    dis[index][gasnum] = 0;
    for (int i = 1; i <= n + m; ++i) {
        if(dis[index][gasnum] + graph[index][i] < dis[i][gasnum]){
            dis[i][gasnum] = dis[index][gasnum] + graph[index][i];
        }
    }
    while(1){
        for (int i = 1; i <= n+m ; ++i) {
            if(!iscollected[i] && dis[i][gasnum] < mindis){
                mindis = dis[i][gasnum];
                minindex = i;
            }
        }
        if(minindex == -1){
            break;
        }
        iscollected[minindex] = true;
        for (int i = 1; i <= n + m ; ++i) {
            if(dis[minindex][gasnum] + graph[minindex][i] < dis[i][gasnum]){
                dis[i][gasnum] = dis[minindex][gasnum] + graph[minindex][i];
            }
        }
        index = minindex;
        mindis = maxx;
        minindex = -1;
    }
}

int main(){
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1072/in1072", "r", stdin);
    int n, m, k1, ds;
    scanf("%d%d%d%d", &n, &m, &k1, &ds);
    for (int i = 1; i <= n + m; ++i) {
        for (int j = 1; j <= n + m ; ++j) {
            graph[i][j] = maxx;
        }
    }
    for (int i = 0; i < k1; ++i) {
        char tmp1[5], tmp2[5];
        int tmpdis;
        scanf("%s%s%d", tmp1, tmp2, &tmpdis);
        int v1, v2;
        if(tmp1[0] == 'G'){
            string ts = tmp1;
            v1 = stoi(ts.substr(1))+ n;
        }else{
            string ts = tmp1;
            v1 = stoi(ts);
        }
        if(tmp2[0] == 'G'){
            string ts = tmp2;
            v2 = stoi(ts.substr(1))+ n;
        }else{
            string ts = tmp2;
            v2 = stoi(ts);
        }
        graph[v1][v2] = tmpdis;
        graph[v2][v1] = tmpdis;
    }


    for (int i = 1; i <= m ; ++i) {
        dijkstra(n, m, i);
    }

    vector<gas> gvec;
    for (int i = 1; i <= m; ++i) {
        double mindis = maxx;
        double sumdis = 0;
        bool flg = true;
        for (int j = 1; j <= n ; ++j) {
            if(dis[j][i] <= ds){
                if(mindis > dis[j][i]){
                    mindis = dis[j][i];
                }
                sumdis += dis[j][i];
            }else{
                flg = false;
                break;
            }
        }
        if(flg){
            gas tmpgas;
            tmpgas.id = i;
            tmpgas.ave = sumdis / n;
            tmpgas.mindis = mindis;
            gvec.push_back(tmpgas);
        }
    }
    if(gvec.empty()){
        printf("No Solution");
    }else{
        sort(gvec.begin(), gvec.end(), sort1);
        printf("G%d\n", gvec[0].id);
        printf("%.1lf %.1lf\n", gvec[0].mindis, gvec[0].ave);
    }


    return 0;
}