#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int pros[6];
struct stu{
    int id;
    int grades[6];
    bool permit[6];
    int scoreall = 0;
    int perfectnum = 0;
    bool flg = false;
};
using namespace std;

bool sort1(const stu &a, const stu &b){
    if(a.scoreall != b.scoreall){
        return a.scoreall > b.scoreall;
    } else if(a.perfectnum != b.perfectnum){
        return a.perfectnum > b.perfectnum;
    }else{
        return a.id < b.id;
    }
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1075/in1075", "r", stdin);
    map<int, stu> ma;
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &pros[i]);
    }
    for (int i = 0; i < m; ++i) {
        int tmpid, tmpproid, tmpob;
        scanf("%d%d%d", &tmpid, &tmpproid, &tmpob);
        ma[tmpid];
        ma[tmpid].permit[tmpproid] = true;
        if(ma[tmpid].grades[tmpproid] <= tmpob){
            if(tmpob == pros[tmpproid] && ma[tmpid].grades[tmpproid] != pros[tmpproid]){
                ma[tmpid].perfectnum++;
            }
            ma[tmpid].grades[tmpproid] = tmpob;
            ma[tmpid].flg = true;
        }
    }
    vector<stu> vec;
    for (auto a : ma) {
        if(a.second.flg){
            a.second.id = a.first;
            for (int i = 1; i <= k ; ++i) {
                a.second.scoreall += a.second.grades[i];
                if(!a.second.permit[i]){
                    a.second.grades[i] = -1;
                }
            }
            vec.push_back(a.second);
        }
    }
    sort(vec.begin(), vec.end(), sort1);
    int cnt;
    int curr = -1;
    for (int i = 0; i < vec.size(); ++i) {
        if(curr == vec[i].scoreall){
            printf("%d ", cnt);
        }else{
            curr = vec[i].scoreall;
            printf("%d ",i+1);
            cnt = i + 1;
        }
        printf("%05d %d", vec[i].id, vec[i].scoreall);
        for (int j = 1; j <= k; ++j) {
            if(vec[i].grades[j] == -1){
                printf(" -");
            }else{
                printf(" %d", vec[i].grades[j]);
            }
        }
        printf("\n");
    }
    return 0;
}