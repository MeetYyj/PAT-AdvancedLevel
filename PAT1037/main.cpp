#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sortpos(const int &a, const int &b){
    return a > b;
}
bool sortneg(const int &a, const int &b){
    return a < b;
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1037/in1037", "r", stdin);
    int nc, np;
    scanf("%d", &nc);
    vector<int> veccpos, veccneg, vecppos, vecpneg;
    for (int i = 0; i < nc; ++i) {
        int tmps;
        cin >> tmps;
        if(tmps>0){
            veccpos.push_back(tmps);
        }else{
            veccneg.push_back(tmps);
        }
    }
    scanf("%d", &np);
    for (int i = 0; i < np; ++i) {
        int tmps;
        cin >> tmps;
        if(tmps > 0){
            vecppos.push_back(tmps);
        }else{
            vecpneg.push_back(tmps);
        }
    }

    int sum = 0;
    sort(veccpos.begin(), veccpos.end(), sortpos);
    sort(veccneg.begin(), veccneg.end(), sortneg);
    sort(vecppos.begin(), vecppos.end(), sortpos);
    sort(vecpneg.begin(), vecpneg.end(), sortneg);
    for (int i = 0; i < (veccpos.size() < vecppos.size() ? veccpos.size() : vecppos.size()); ++i) {
        sum += veccpos[i] * vecppos[i];
    }
    for (int i = 0; i < (veccneg.size() < vecpneg.size() ? veccneg.size() : vecpneg.size()); ++i) {
        sum += veccneg[i] * vecpneg[i];
    }
    cout << sum;
    return 0;
}