#include <iostream>
#include <vector>
#include <algorithm>
struct stu{
    int id = -1;
    int c, m, e;
    double a;
    int r[4];
};

bool isahigher(stu a, stu b){
    return a.a > b.a;
}
bool ischigher(stu a, stu b){
    return a.c > b.c;
}
bool ismhigher(stu a, stu b){
    return a.m > b.m;
}
bool isehigher(stu a, stu b){
    return a.e > b.e;
}
using namespace std;
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1012/in1012", "r", stdin);
    int numN, numM;
    scanf("%d %d\n", &numN, &numM);
    vector<stu> vstu;
    for (int i = 0; i < numN; ++i) {
        stu tmp;
        scanf("%d%d%d%d", &tmp.id, &tmp.c, &tmp.m, &tmp.e);
        tmp.a = ((double)tmp.c + tmp.m + tmp.e)/3;
        vstu.push_back(tmp);
    }
    sort(vstu.begin(),vstu.end(),isahigher);
    vstu[0].r[0] = 0;
    for (int i = 1; i < vstu.size(); ++i) {
        if(vstu[i-1].a == vstu[i].a){
            vstu[i].r[0] = vstu[i-1].r[0];
        } else{
            vstu[i].r[0] = i;
        }
    }
    sort(vstu.begin(),vstu.end(),ischigher);
    vstu[0].r[1] = 0;
    for (int i = 1; i < vstu.size(); ++i) {
        if(vstu[i-1].c == vstu[i].c){
            vstu[i].r[1] = vstu[i-1].r[1];
        } else{
            vstu[i].r[1] = i;
        }
    }
    sort(vstu.begin(),vstu.end(),ismhigher);
    vstu[0].r[2] = 0;
    for (int i = 1; i < vstu.size(); ++i) {
        if(vstu[i-1].m == vstu[i].m){
            vstu[i].r[2] = vstu[i-1].r[2];
        } else{
            vstu[i].r[2] = i;
        }
    }
    sort(vstu.begin(),vstu.end(),isehigher);
    vstu[0].r[3] = 0;
    for (int i = 1; i < vstu.size(); ++i) {
        if(vstu[i-1].e == vstu[i].e){
            vstu[i].r[3] = vstu[i-1].r[3];
        } else{
            vstu[i].r[3] = i;
        }
    }
    int checkid;
    char rank[5] = {"ACME"};
    for (int i = 0; i < numM; ++i) {
        int flg = false;
        scanf("%d", &checkid);
        for (int j = 0; j < vstu.size(); ++j) {
            if(checkid == vstu[j].id){
                flg = true;
                int rtmp = 1000000, index = -1;
                for (int k = 0; k < 4; ++k) {
                    if(rtmp > vstu[j].r[k]){
                        rtmp = vstu[j].r[k];
                        index = k;
                    }
                }
                printf("%d %c", vstu[j].r[index] + 1, rank[index]);
            }
        }
        if(!flg)
            printf("N/A");
        if(i != numM - 1)
            printf("\n");
    }
    return 0;
}

//struct node {
//    int id, best;
//    int score[4], rank[4];
//}stu[2005];
//int exist[1000000], flag = -1;
//bool cmp1(node a, node b) {return a.score[flag] > b.score[flag];}
//int main() {
//    int n, m, id;
//    scanf("%d %d", &n, &m);
//    for(int i = 0; i < n; i++) {
//        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
//        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
//    }
//    for(flag = 0; flag <= 3; flag++) {
//        sort(stu, stu + n, cmp1);
//        stu[0].rank[flag] = 1;
//        for(int i = 1; i < n; i++) {
//            stu[i].rank[flag] = i + 1;
//            if(stu[i].score[flag] == stu[i-1].score[flag])
//                stu[i].rank[flag] = stu[i-1].rank[flag];
//        }
//    }
//    for(int i = 0; i < n; i++) {
//        exist[stu[i].id] = i + 1;
//        stu[i].best = 0;
//        int minn = stu[i].rank[0];
//        for(int j = 1; j <= 3; j++) {
//            if(stu[i].rank[j] < minn) {
//                minn = stu[i].rank[j];
//                stu[i].best = j;
//            }
//        }
//    }
//    char c[5] = {'A', 'C', 'M', 'E'};
//    for(int i = 0; i < m; i++) {
//        scanf("%d", &id);
//        int temp = exist[id];
//        if(temp) {
//            int best = stu[temp-1].best;
//            printf("%d %c\n", stu[temp-1].rank[best], c[best]);
//        } else {
//            printf("N/A\n");
//        }
//    }
//    return 0;
//}