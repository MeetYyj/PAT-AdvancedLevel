#include <iostream>
#include <queue>
using namespace std;
int graph[1287][129][61];
bool iscollected[1287][129][61];
int cnt = 0;
int m, n, l, t;
struct vertex{
    int j;
    int k;
    int i;
};

void bfs(){
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if(!iscollected[j][k][i] && graph[j][k][i]){
                    iscollected[j][k][i] = true;
                    int partcnt = 0;
                    queue<vertex> q;
                    vertex tmp;
                    tmp.i = i;
                    tmp.j = j;
                    tmp.k = k;
                    q.push(tmp);
                    while(!q.empty()){
                        vertex fronttmp = q.front();
                        q.pop();
                        partcnt++;
                        int fi = fronttmp.i;
                        int fj = fronttmp.j;
                        int fk = fronttmp.k;
                        if(fi != 0 && graph[fj][fk][fi - 1] && !iscollected[fj][fk][fi - 1]){
                            iscollected[fj][fk][fi - 1] = true;
                            tmp.i = fi - 1;
                            tmp.j = fj;
                            tmp.k = fk;
                            q.push(tmp);
                        }
                        if(fi != l - 1 && graph[fj][fk][fi + 1] && !iscollected[fj][fk][fi + 1]){
                            iscollected[fj][fk][fi + 1] = true;
                            tmp.i = fi + 1;
                            tmp.j = fj;
                            tmp.k = fk;
                            q.push(tmp);
                        }
                        if(fj != 0 && graph[fj - 1][fk][fi] && !iscollected[fj - 1][fk][fi]){
                            iscollected[fj - 1][fk][fi] = true;
                            tmp.i = fi;
                            tmp.j = fj - 1;
                            tmp.k = fk;
                            q.push(tmp);
                        }
                        if(fj != m - 1 && graph[fj + 1][fk][fi] && !iscollected[fj + 1][fk][fi]){
                            iscollected[fj + 1][fk][fi] = true;
                            tmp.i = fi;
                            tmp.j = fj + 1;
                            tmp.k = fk;
                            q.push(tmp);
                        }
                        if(fk != 0 && graph[fj][fk - 1][fi] && !iscollected[fj][fk - 1][fi]){
                            iscollected[fj][fk - 1][fi] = true;
                            tmp.i = fi;
                            tmp.j = fj;
                            tmp.k = fk - 1;
                            q.push(tmp);
                        }
                        if(fk != n - 1 && graph[fj][fk + 1][fi] && !iscollected[fj][fk + 1][fi]){
                            iscollected[fj][fk + 1][fi] = true;
                            tmp.i = fi;
                            tmp.j = fj;
                            tmp.k = fk + 1;
                            q.push(tmp);
                        }
                    }
                    if(partcnt >= t){
//                        cout << "part: " << partcnt << endl;
//                        for (int i1 = 0; i1 < l; ++i1) {
//                            for (int j1 = 0; j1 < m; ++j1) {
//                                for (int k1 = 0; k1 < n; ++k1) {
//                                    cout << iscollected[j1][k1][i1] << " ";
//                                }
//                                cout << endl;
//                            }
//                        }
                        cnt += partcnt;
                    }
                }
            }
        }
    }

}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1091/in1091", "r", stdin);
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d", &graph[j][k][i]);
            }
        }
    }
    bfs();
    cout << cnt;
    return 0;
}