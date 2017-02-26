#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct node{
    bool isexit = false;
    set<int> pset;
    set<int> cset;
//    vector<int> parent;
//    vector<int> children;
    int sets = 0;
    int area = 0;
}nodes[10001];
bool iscollected[10001];
bool iscnted[10001];
struct record{
    vector<int> id;
    int rmem = 0;
    int rsetall = 0;
    double rareaall = 0;
};

vector<int> tmpvid;
int sumset = 0;
int sumarea = 0;
int mem = 0;
void dfs(int index){
    if(!iscollected[index]){
        iscollected[index] = true;
        if(nodes[index].isexit){
            sumset += nodes[index].sets;
            sumarea += nodes[index].area;
        }
        if(!iscnted[index]){
            mem++;
            tmpvid.push_back(index);
            iscnted[index] = true;
        }
        for (auto a : nodes[index].pset) {
            if(!iscollected[a]){
                dfs(a);
            }
        }
        for (auto a : nodes[index].cset) {
            if(!iscollected[a]){
                dfs(a);
            }
        }
    }
};

bool sort1(const record &a, const record &b){
    if(a.rareaall / a.rmem != b.rareaall / b.rmem){
        return a.rareaall / a.rmem > b.rareaall / b.rmem;
    }else{
        return a.id[0] < b.id[0];
    }
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1114/in1114", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<int> pers;
    for (int i = 0; i < num; ++i) {
        int id, fa, mo, cnum;
        scanf("%d%d%d%d", &id, &fa, &mo, &cnum);
        nodes[id].isexit = true;
        if(fa != -1){
            nodes[id].pset.insert(fa);
            nodes[fa].cset.insert(id);
        }
        if(mo != -1){
            nodes[id].pset.insert(mo);
            nodes[mo].cset.insert(id);
        }
        for (int j = 0; j < cnum; ++j) {
            int tmpc;
            scanf("%d", &tmpc);
            nodes[id].cset.insert(tmpc);
            nodes[tmpc].pset.insert(id);
        }
        int tset, tarea;
        scanf("%d %d", &tset, &tarea);
        nodes[id].sets = tset;
        nodes[id].area = tarea;
        pers.push_back(id);
    }
    vector<record> vout;
    for (int i = 0; i < pers.size(); ++i) {
        if(!iscollected[pers[i]]){
            tmpvid.clear();
            sumset = 0;
            sumarea = 0;
            mem = 0;
            dfs(pers[i]);

            record tmprec;
            tmprec.id = tmpvid;
            tmprec.rareaall = sumarea;
            tmprec.rmem = mem;
            tmprec.rsetall = sumset;
            vout.push_back(tmprec);
        }
    }
    for (int i = 0; i < vout.size(); ++i) {
        sort(vout[i].id.begin(), vout[i].id.end());
    }
    sort(vout.begin(), vout.end(), sort1);
    printf("%ld\n", vout.size());
    for (int i = 0; i < vout.size(); ++i) {
        printf("%04d %d %.3lf %.3lf\n", vout[i].id[0], vout[i].rmem, (double)vout[i].rsetall / vout[i].rmem, vout[i].rareaall / vout[i].rmem);
    }
    return 0;
}