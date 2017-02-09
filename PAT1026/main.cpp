#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct custom{
    int hh, mm, ss;
    int hhs, mms, sss;
    int arrivingtimes;
    int playingtime;
    int waitingtime = 0;
    int vip;
    bool canbeserved = true;
};

struct table{
    int hh = 8, mm = 0, ss = 0;
    int servednum = 0;
    bool isviptable = false;
    bool isempty = true;
    custom cust;
};

int num;
int k, m;
int chh = 8, cmm = 0, css = 0;
vector<custom> qvec;
bool sorta(const custom &a, const custom &b){
    return a.hh * 3600 + a.mm *60 + a.ss <
            b.hh * 3600 + b.mm *60 + b.ss;
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1026/in1026", "r", stdin);
    scanf("%d\n", &num);
    vector<custom> vecc;
    for (int i = 0; i < num; ++i) {
        custom tmpc;
        scanf("%d:%d:%d %d %d\n", &tmpc.hh, &tmpc.mm, &tmpc.ss, &tmpc.playingtime, &tmpc.vip);
        tmpc.arrivingtimes = tmpc.hh * 3600 + tmpc.mm *60 + tmpc.ss;
        vecc.push_back(tmpc);
    }
    scanf("%d %d\n", &k, &m);
    vector<table> vect(k);
    for (int i = 0; i < m; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vect[tmp - 1].isviptable = true;
    }

    sort(vecc.begin(), vecc.end(), sorta);
    int cnt = 0;
    while (cnt < num || !qvec.empty()) {
        bool allfull = true;
        for (int j = 0; j < k; ++j) {
            if(vect[j].isempty){
                if(qvec.empty()){
                    vect[j].cust = vecc[cnt];
                    chh = vecc[cnt].hh;
                    cmm = vecc[cnt].mm;
                    css = vecc[cnt].ss;
                    vect[j].hh = chh;
                    vect[j].mm = cmm;
                    vect[j].ss = css;
                    vecc[cnt].waitingtime = 0;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", vecc[cnt].hh, vecc[cnt].mm, vecc[cnt].ss, chh, cmm, css, vecc[cnt].waitingtime);
                    cnt++;
//                    cout << chh << ":" << cmm << ":" << css << endl;
                } else{
                    if(vect[j].isviptable){
                        int vipnum = -1;
                        for (int l = 0; l < qvec.size(); ++l) {
                            if(qvec[l].vip){
                                vipnum = l;
                                break;
                            }
                        }
                        if(vipnum != -1){
                            vect[j].cust = qvec[vipnum];
                            qvec.erase(qvec.begin() + vipnum);
                        } else {
                            vect[j].cust = qvec[0];
                            qvec.erase(qvec.begin());
                        }
                    } else {
                        vect[j].cust = qvec[0];
                        qvec.erase(qvec.begin());
                    }
                    int waitseconds;
                    waitseconds = (chh - vect[j].cust.hh) * 3600 + (cmm - vect[j].cust.mm) * 60 + css - vect[j].cust.ss;
                    if(waitseconds%60){
                        vect[j].cust.waitingtime = waitseconds/60 + 1;
                    } else{
                        vect[j].cust.waitingtime = waitseconds/60;
                    }
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", vect[j].cust.hh, vect[j].cust.mm, vect[j].cust.ss, chh, cmm, css, vect[j].cust.waitingtime);
                }
                vect[j].servednum++;
//                cout << cnt << "as" << endl;
                allfull = false;
            }
            vect[j].isempty = false;
        }
        if(allfull){
            int mintime = 21*3600, indexmin = 0;
            for (int i = 0; i < vect.size(); ++i) {
                int servetimetmp = vect[i].hh * 3600 + vect[i].mm * 60 + vect[i].ss + vect[i].cust.playingtime * 60;
                if(servetimetmp < mintime){
                    mintime = servetimetmp;
                    indexmin = i;
                }
            }
            if(vect[indexmin].mm + vect[indexmin].cust.playingtime >= 60){
                vect[indexmin].mm += vect[indexmin].cust.playingtime - 60;
                vect[indexmin].hh++;
            } else {
                vect[indexmin].mm += vect[indexmin].cust.playingtime;
            }
            chh = vect[indexmin].hh;
            cmm = vect[indexmin].mm;
            css = vect[indexmin].ss;
            while(vecc[cnt].arrivingtimes <= mintime){
                if(chh < 21)
                    qvec.push_back(vecc[cnt]);
//                cout << vecc[cnt].arrivingtimes << " " << mintime << endl;
//                cout << cnt << endl;
                cnt++;
                if(cnt == num)
                    break;
            }
            vect[indexmin].isempty = true;
//            cout << chh << ":" << cmm << ":" << css << endl;
        }
    }

    for (int n = 0; n < vect.size(); ++n) {
        printf("%d", vect[n].servednum);
        if(n != vect.size() - 1)
            printf(" ");
    }

//    for (int i = 0; i < vecc.size(); ++i) {
//        cout << vecc[i].hh << ":"  << vecc[i].mm << ":" << vecc[i].ss << " " << vecc[i].vip << endl;
//    }

    return 0;
}