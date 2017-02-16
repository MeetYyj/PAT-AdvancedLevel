#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person{
    int id;
    int v;
    int t;
    int sum;
};
bool sort1(const person &a, const person &b){
    if(a.sum > b.sum)
        return true;
    else if(a.sum == b.sum && a.v > b.v)
        return true;
    else if(a.sum == b.sum && a.v == b.v && a.id < b.id)
        return true;
    else
        return false;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1062/in1062", "r", stdin);
    vector<person> sages, noblemen, foolmen, afterfool;
    int num, lowline, highline;
    scanf("%d %d %d\n", &num, &lowline, &highline);
    for (int i = 0; i < num; ++i) {
        person tmp;
        scanf("%d %d %d\n", &tmp.id, &tmp.v, &tmp.t);
        tmp.sum = tmp.v + tmp.t;
        if(tmp.v >= highline && tmp.t >= highline){
            sages.push_back(tmp);
        }else if(tmp.v >= highline && tmp.t < highline && tmp.t >= lowline){
            noblemen.push_back(tmp);
        }else if(tmp.v < highline && tmp.v >= lowline && tmp.t < highline && tmp.t >= lowline && tmp.v >= tmp.t){
            foolmen.push_back(tmp);
        }else if(tmp.v >= lowline && tmp.t >= lowline){
            afterfool.push_back(tmp);
        }
    }
    printf("%ld\n", sages.size() + noblemen.size() + foolmen.size() + afterfool.size());
    sort(sages.begin(), sages.end(), sort1);
    for (int i = 0; i < sages.size(); ++i) {
        printf("%08d %d %d\n", sages[i].id, sages[i].v, sages[i].t);
    }
    sort(noblemen.begin(), noblemen.end(), sort1);
    for (int i = 0; i < noblemen.size(); ++i) {
        printf("%08d %d %d\n", noblemen[i].id, noblemen[i].v, noblemen[i].t);
    }
    sort(foolmen.begin(), foolmen.end(), sort1);
    for (int i = 0; i < foolmen.size(); ++i) {
        printf("%08d %d %d\n", foolmen[i].id, foolmen[i].v, foolmen[i].t);
    }
    sort(afterfool.begin(), afterfool.end(), sort1);
    for (int i = 0; i < afterfool.size(); ++i) {
        printf("%08d %d %d\n", afterfool[i].id, afterfool[i].v, afterfool[i].t);
    }
    return 0;
}