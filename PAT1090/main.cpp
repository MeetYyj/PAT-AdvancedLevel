#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int num, rootindex;
int maxlevel = 0;
int maxcnt = 0;
struct person{
    int addr;
    vector<int> nextv;
    int level = 0;
//    bool iscollected = false;
}persons[100001];

void dfs(int index){
//    persons[index].iscollected;
    for (int i = 0; i < persons[index].nextv.size(); ++i) {
        persons[persons[index].nextv[i]].level = persons[index].level + 1;
        if(persons[persons[index].nextv[i]].level > maxlevel){
            maxlevel = persons[persons[index].nextv[i]].level;
            maxcnt = 1;
        } else if(persons[persons[index].nextv[i]].level == maxlevel){
            maxcnt++;
        }
        dfs(persons[index].nextv[i]);
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1090/in1090a", "r", stdin);
    double p, r;
    scanf("%d", &num);
    scanf("%lf%lf", &p, &r);
    for (int i = 0; i < num; ++i) {
        int tmpnext;
        scanf("%d", &tmpnext);
        if(tmpnext == -1){
            rootindex = i;
        }else{
            persons[tmpnext].nextv.push_back(i);
        }
    }
    if(num == 1){
        printf("%.2lf %d", p, 1);
    } else{
        dfs(rootindex);
        double maxp = p * pow((1+r/100), maxlevel);
        printf("%.2lf %d", maxp, maxcnt);
    }

    return 0;
}