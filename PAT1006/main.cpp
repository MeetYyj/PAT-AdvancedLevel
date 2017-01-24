#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct person{
    char ID[16];
    int inH,inM,inS,outH,outM,outS;
};

bool isearler(const person a, const person b){
    return a.inH * 3600 + a.inM * 60 + a.inS <
            b.inH * 3600 + b.inM * 60 + b.inS;
}

bool islater(const person a, const person b){
    return a.outH * 3600 + a.outM * 60 + a.outS >
           b.outH * 3600 + b.outM * 60 + b.outS;
}
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1006/in1006", "r", stdin);
    int num;
    scanf("%d\n", &num);
    vector<person> pvec;
    for (int i = 0; i < num; ++i) {
        person tmp;
        scanf("%s %d:%d:%d %d:%d:%d",
              &tmp.ID, &tmp.inH, &tmp.inM, &tmp.inS,
              &tmp.outH, &tmp.outM, &tmp.outS);
        pvec.push_back(tmp);
    }
    sort(pvec.begin(), pvec.end(), isearler);
    cout << pvec[0].ID << " ";
    sort(pvec.begin(), pvec.end(), islater);
    cout << pvec[0].ID;
    return 0;
}