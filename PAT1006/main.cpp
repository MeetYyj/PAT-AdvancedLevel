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

bool cmp(int th, int tm, int ts, int h, int m, int s) {
    if(th > h) {
        return true;
    } else if(tm > m) {
        return true;
    } else if(ts > s) {
        return true;
    }
    return false;
}
//the following one is also good and save time
//int main() {
//    int n;
//    scanf("%d", &n);
//    string unlocked, locked;
//    int unlockedh = 23, unlockedm = 59, unlockeds = 59;
//    int lockedh = 0, lockedm = 0, lockeds = 0;
//    for(int i = 0; i < n; i++) {
//        string t;
//        cin >> t;
//        int h1, m1, s1, h2, m2, s2;
//        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
//        if(cmp(h1, m1, s1, unlockedh, unlockedm, unlockeds) == false) {
//            unlockedh = h1;
//            unlockedm = m1;
//            unlockeds = s1;
//            unlocked = t;
//        }
//        if(cmp(h2, m2, s2, lockedh, lockedm, lockeds) == true) {
//            lockedh = h2;
//            lockedm = m2;
//            lockeds = s2;
//            locked = t;
//        }
//    }
//    cout << unlocked << " " << locked;
//    return 0;
//}