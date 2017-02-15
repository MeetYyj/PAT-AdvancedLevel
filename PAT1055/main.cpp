#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct person{
    char name[9];
    int age;
    int wealth;

};
int cntp[201];

bool sort1(const person &a, const person &b){
    if(a.wealth > b.wealth){
        return true;
    } else if(a.wealth == b.wealth && a.age < b.age){
        return true;
    } else if(a.wealth == b.wealth && a.age == b.age){
        return strcmp(a.name, b.name) < 0;
    } else{
        return false;
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1055/in1055", "r", stdin);
    int num, quries;
    scanf("%d %d\n", &num, &quries);
    vector<person> vecp;
    for (int i = 0; i < num; ++i) {
        person tmp;
        scanf("%s%d%d", tmp.name, &tmp.age, &tmp.wealth);
        vecp.push_back(tmp);
    }
    sort(vecp.begin(), vecp.end(), sort1);
    vector<person> vp;
    for (int i = 0; i < vecp.size(); ++i) {
        if(cntp[vecp[i].age] < 100){
            vp.push_back(vecp[i]);
            cntp[vecp[i].age]++;
        }
    }

//    sort(vecp.begin(), vecp.end(), sort1);
    for (int i = 0; i < quries; ++i) {
        int outnum, ageb, agee;
        scanf("%d%d%d", &outnum, &ageb, &agee);
        vector<person> vect;
        for (int j = 0; j < vp.size(); ++j) {
            if(vp[j].age <= agee && vp[j].age >= ageb && vect.size() <= outnum){
                vect.push_back(vp[j]);
            }
        }
        printf("Case #%d:\n", i+1);
        for (int k = 0; k < outnum && k < vect.size(); ++k) {
            printf("%s %d %d\n", vect[k].name, vect[k].age, vect[k].wealth);
        }
        if (vect.size() == 0){
            printf("None\n");
        }
    }

    return 0;
}

