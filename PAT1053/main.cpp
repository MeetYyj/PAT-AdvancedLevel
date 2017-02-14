#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct node{
    int w;
    vector<int> v;
}nodes[100];
vector<int> sta;
vector<vector<int>> vo;
int sumtmp = 0;
void dfs(int index, int s){
    sumtmp += nodes[index].w;
    sta.push_back(index);
    bool flg = true;
//    cout << index << endl;
    for (int i = 0; i < nodes[index].v.size(); ++i) {
        dfs(nodes[index].v[i], s);
        flg = false;
    }
    if(flg && sumtmp == s){
        vo.push_back(sta);
    }
    sumtmp -= nodes[index].w;
//    sumtmp -= sta[sta.size() - 1];
    sta.pop_back();
}

bool sort1(const vector<int> &a, vector<int> &b){
    int i = 0;
    for (; i < a.size() && i < b.size(); ++i) {
        if(nodes[a[i]].w < nodes[b[i]].w){
            return false;
        } else if(nodes[a[i]].w > nodes[b[i]].w){
            return true;
        }
    }
    if(i == a.size()){
        return false;
    } else {
        return true;
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1053/in1053", "r", stdin);
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; ++i) {
        int tmpw;
        scanf("%d", &tmpw);
        nodes[i].w = tmpw;
    }
    for (int i = 0; i < m; ++i) {
        int index, lnum;
        scanf("%d%d", &index, &lnum);
        for (int j = 0; j < lnum; ++j) {
            int lcode;
            scanf("%d", &lcode);
            nodes[index].v.push_back(lcode);
        }
//        sort(nodes[index].v.rbegin(), nodes[index].v.rend());
    }
    dfs(0, s);
    sort(vo.begin(), vo.end(), sort1);
    for (int i = 0; i < vo.size(); ++i) {
        for (int j = 0; j < vo[i].size(); ++j) {
            if(j != 0){
                printf(" ");
            }
            printf("%d", nodes[vo[i][j]].w);
        }
        printf("\n");
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < nodes[i].v.size(); ++j) {
//            cout << nodes[i].v[j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}