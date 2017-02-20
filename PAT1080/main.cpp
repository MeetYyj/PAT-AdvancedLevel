#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct stu{
    int ge, gi;
    int choice[6];
    int sum;
    int id;
    int rank;
};
int school[101];
int lastrank[101];
vector<stu> vec;

bool sort1(const stu &a, const stu &b){
    if(a.sum != b.sum){
        return a.sum > b.sum;
    } else{
        return a.ge > b.ge;
    }
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1080/in1080", "r", stdin);
    int stunum, schoolnum, k;
    scanf("%d%d%d", &stunum, &schoolnum, &k);
    for (int i = 0; i < schoolnum; ++i) {
        scanf("%d", &school[i]);
    }
    for (int i = 0; i < stunum; ++i) {
        stu stutmp;
        scanf("%d%d", &stutmp.ge, &stutmp.gi);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &stutmp.choice[j]);
        }
        stutmp.id = i;
        stutmp.sum = stutmp.ge + stutmp.gi;
        vec.push_back(stutmp);
    }
    // sort
    sort(vec.begin(), vec.end(), sort1);
    int cntrank = 1;
    int cntsum = 10000;
    int cntge = 10000;
    //add rank
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i].sum == cntsum && vec[i].ge == cntge){
            vec[i].rank = cntrank;
        }else{
            cntsum = vec[i].sum;
            cntge = vec[i].ge;
            vec[i].rank = i + 1;
            cntrank = i + 1;
        }
    }
    vector<int> vout[schoolnum];
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            if(school[vec[i].choice[j]] > 0){
                school[vec[i].choice[j]]--;
                lastrank[vec[i].choice[j]] = vec[i].rank;
                vout[vec[i].choice[j]].push_back(vec[i].id);
                break;
            } else if(vec[i].rank == lastrank[vec[i].choice[j]]){
                school[vec[i].choice[j]]--;
                vout[vec[i].choice[j]].push_back(vec[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < schoolnum; ++i) {
        sort(vout[i].begin(), vout[i].end());
        for (int j = 0; j < vout[i].size(); ++j) {
            if(j != 0)
                printf(" ");
            printf("%d", vout[i][j]);
        }
        printf("\n");
    }
//    for (int i = 0; i < 101; ++i) {
//        cout << lastrank[i] << " ";
//    }
//    for (int i = 0; i < vec.size(); ++i) {
//        cout << vec[i].id << " " << "rank: " << vec[i].rank << " ";
//        cout << vec[i].ge << " " << vec[i].gi << " ";
//        cout << vec[i].choice[0] << " " << vec[i].choice[1] << " " << vec[i].choice[2] << " ";
//        cout << endl;
//    }
    return 0;
}