#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person{
    char name[11];
    char id[11];
    int grade;
};

bool sort1(const person &a, const person &b){
    return a.grade > b.grade;
}
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1083/in1083a", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<person> vec;
    for (int i = 0; i < num; ++i) {
        person tmpp;
        scanf("%s %s %d\n", tmpp.name, tmpp.id, &tmpp.grade);
        vec.push_back(tmpp);
    }
    sort(vec.begin(), vec.end(), sort1);
    int lowg, highg;
    scanf("%d %d", &lowg, &highg);
    vector<person> vout;
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i].grade >= lowg && vec[i].grade <= highg){
            vout.push_back(vec[i]);
        }
    }
    if(vout.size()){
        for (int i = 0; i < vout.size(); ++i) {
            printf("%s %s\n", vout[i].name, vout[i].id);
        }
    }else{
        printf("NONE\n");
    }

    return 0;
}