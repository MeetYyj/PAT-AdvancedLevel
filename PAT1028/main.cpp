#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct record{
    int id;
    char name[9];
    int grade;
};

vector<record> vecr;
int n,c;

bool sort1(const record &a, const record &b){
    return a.id < b.id;
}

bool sort2(const record &a, const record &b){
    string as = a.name, bs = b.name;
    if(as < bs)
        return true;
    else if(as == bs)
        return a.id < b.id;
    return false;
}

bool sort3(const record &a, const record &b){
    if(a.grade < b.grade)
        return true;
    else if(a.grade == b.grade)
        return a.id < b.id;
    return false;
}
int main(){
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1028/in1028", "r", stdin);
    scanf("%d %d\n", &n, &c);
    for (int i = 0; i < n; ++i) {
        record tmpr;
        scanf("%d%s%d", &tmpr.id, &tmpr.name, &tmpr.grade);
        vecr.push_back(tmpr);
    }
    switch(c){
        case 1:
            sort(vecr.begin(), vecr.end(), sort1);
            break;
        case 2:
            sort(vecr.begin(), vecr.end(), sort2);
            break;
        case 3:
            sort(vecr.begin(), vecr.end(), sort3);
            break;
        default:
            break;
    }
    for (int i = 0; i < vecr.size(); ++i) {
        printf("%06d %s %d\n", vecr[i].id, vecr[i].name, vecr[i].grade);
    }
//    for (int j = 0; j < vecr.size(); ++j) {
//        cout << vecr[j].id << vecr[j].name << vecr[j].grade << endl;
//    }
    return 0;
}