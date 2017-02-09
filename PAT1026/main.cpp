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
    int servetimes;
    int waitingtime = 0;
    int vip;
};

struct table{
    int finishtime = 8 * 3600;
    int servednum = 0;
    bool isviptable = false;
};

int num;
int k, m;
int normaltablemin = -1, viptablemin = -1;
int normalfinishtimemin = 24 * 3600, vipfinishtimemin = 24 * 3600;

vector<custom> qvec;
vector<table> vect;
vector<custom> vecc;
vector<custom> vecout;
bool sorta(const custom &a, const custom &b){
    return a.arrivingtimes < b.arrivingtimes;
}

void findmintable(){
    normalfinishtimemin = 24 * 3600, vipfinishtimemin = 24 * 3600;
    for (int i = 0; i < vect.size(); ++i) {
        if(vect[i].finishtime < normalfinishtimemin && !vect[i].isviptable){
            normalfinishtimemin = vect[i].finishtime;
            normaltablemin = i;
        }
        if(vect[i].finishtime < vipfinishtimemin && vect[i].isviptable){
            vipfinishtimemin = vect[i].finishtime;
            viptablemin = i;
        }
    }
//    cout << "nt:" << normalfinishtimemin << " nn:" << normaltablemin << " vt:" << vipfinishtimemin << " vn:" << viptablemin << endl;
};

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1026/in1026a", "r", stdin);
    scanf("%d\n", &num);
    for (int i = 0; i < num; ++i) {
        custom tmpc;
        scanf("%d:%d:%d %d %d\n", &tmpc.hh, &tmpc.mm, &tmpc.ss, &tmpc.playingtime, &tmpc.vip);
        tmpc.arrivingtimes = tmpc.hh * 3600 + tmpc.mm *60 + tmpc.ss;
        if(tmpc.playingtime > 120)
            tmpc.playingtime = 120;
        if(tmpc.hh >= 21 || tmpc.hh < 8)
            continue;
        vecc.push_back(tmpc);
    }
    scanf("%d %d\n", &k, &m);
    vect.resize(k);
    for (int i = 0; i < m; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vect[tmp - 1].isviptable = true;
    }
    sort(vecc.begin(), vecc.end(), sorta);
    int cnt = 0;
    findmintable();
    while(cnt < vecc.size() || !qvec.empty()){
        if(qvec.empty()){
            for (int i = 0; i < vect.size(); ++i) {
                if(vecc[cnt].arrivingtimes > vect[i].finishtime){
                    vect[i].finishtime = vecc[cnt].arrivingtimes;
                }
            }
            findmintable();
            if(vecc[cnt].vip){
                if(vipfinishtimemin <= normalfinishtimemin){
                    vecc[cnt].servetimes = vecc[cnt].arrivingtimes;
                    if(vecc[cnt].servetimes < 21 *3600){
                        vecout.push_back(vecc[cnt]);
                        vect[viptablemin].finishtime = vecc[cnt].arrivingtimes + vecc[cnt].playingtime * 60;
                        vect[viptablemin].servednum++;
                    }


                } else{
                    vecc[cnt].servetimes = vecc[cnt].arrivingtimes;
                    if(vecc[cnt].servetimes < 21 *3600){
                        vecout.push_back(vecc[cnt]);
                        vect[normaltablemin].finishtime = vecc[cnt].arrivingtimes + vecc[cnt].playingtime * 60;
                        vect[normaltablemin].servednum++;
                    }

                }
            }else{
                int tablemin;
                if(vipfinishtimemin < normalfinishtimemin){
                    tablemin = viptablemin;
                } else if(vipfinishtimemin > normalfinishtimemin){
                    tablemin = normaltablemin;
                } else{
                    tablemin = vipfinishtimemin < normalfinishtimemin ? viptablemin : normaltablemin;
                }
                vecc[cnt].servetimes = vecc[cnt].arrivingtimes;
                if(vecc[cnt].servetimes < 21 *3600){
                    vecout.push_back(vecc[cnt]);
                    vect[tablemin].finishtime = vecc[cnt].arrivingtimes + vecc[cnt].playingtime * 60;
                    vect[tablemin].servednum++;
                }

            }
            cnt++;
        } else{
            if(vipfinishtimemin == normalfinishtimemin){
                int vipindex = -1;
                custom customtmp;
                for (int i = 0; i < qvec.size(); ++i) {
                    if(qvec[i].vip){
                        vipindex = i;
                        customtmp = qvec[vipindex];
                        qvec.erase(qvec.begin() + vipindex);
                        break;
                    }
                }
                if(vipindex != -1){
                    customtmp.servetimes = vect[viptablemin].finishtime;
                    if(customtmp.servetimes < 21*3600){
                        vecout.push_back(customtmp);
                        vect[viptablemin].finishtime += customtmp.playingtime * 60;
                        vect[viptablemin].servednum++;
                    }

                } else {
                    int tablemin;
                    tablemin = vipfinishtimemin < normalfinishtimemin ? viptablemin : normaltablemin;
                    customtmp = qvec[0];
                    qvec.erase(qvec.begin());
                    customtmp.servetimes = vect[tablemin].finishtime;
                    if(customtmp.servetimes < 21*3600){
                        vecout.push_back(customtmp);
                        vect[tablemin].finishtime += customtmp.playingtime * 60;
                        vect[tablemin].servednum++;
                    }

                }
            } else if(vipfinishtimemin < normalfinishtimemin){
                int vipindex = -1;
                custom customtmp;
                for (int i = 0; i < qvec.size(); ++i) {
                    if(qvec[i].vip){
                        vipindex = i;
                        customtmp = qvec[vipindex];
                        qvec.erase(qvec.begin() + vipindex);
                        break;
                    }
                }
                if(vipindex != -1){
                    customtmp.servetimes = vect[viptablemin].finishtime;
                    if(customtmp.servetimes < 21*3600){
                        vecout.push_back(customtmp);
                        vect[viptablemin].finishtime += customtmp.playingtime * 60;
                        vect[viptablemin].servednum++;
                    }

                } else {
                    customtmp = qvec[0];
                    qvec.erase(qvec.begin());
                    customtmp.servetimes = vect[viptablemin].finishtime;
                    if(customtmp.servetimes < 21*3600){
                        vecout.push_back(customtmp);
                        vect[viptablemin].finishtime += customtmp.playingtime * 60;
                        vect[viptablemin].servednum++;
                    }

                }
            } else{
                custom customtmp;
                customtmp = qvec[0];
                qvec.erase(qvec.begin());
                customtmp.servetimes = vect[normaltablemin].finishtime;
                if(customtmp.servetimes < 21*3600){
                    vecout.push_back(customtmp);
                    vect[normaltablemin].finishtime += customtmp.playingtime * 60;
                    vect[normaltablemin].servednum++;
                }

            }
        }
        findmintable();
        for (int i = cnt; i < vecc.size(); ++i) {
            if(vecc[i].arrivingtimes < min(vipfinishtimemin, normalfinishtimemin)){
                qvec.push_back(vecc[i]);
                cnt++;
            }
        }
    }
    for (int i = 0; i < vecout.size(); ++i) {
        vecout[i].hhs = vecout[i].servetimes / 3600;
        vecout[i].mms = vecout[i].servetimes % 3600 / 60;
        vecout[i].sss = vecout[i].servetimes % 60;
        vecout[i].waitingtime = (vecout[i].servetimes - vecout[i].arrivingtimes + 30) / 60;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", vecout[i].hh, vecout[i].mm, vecout[i].ss, vecout[i].hhs, vecout[i].mms, vecout[i].sss, vecout[i].waitingtime);
    }

    for (int n = 0; n < vect.size(); ++n) {
        printf("%d", vect[n].servednum);
        if(n != vect.size() - 1)
            printf(" ");
    }
    return 0;
}