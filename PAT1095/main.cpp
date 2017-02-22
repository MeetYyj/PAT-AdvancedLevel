#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
struct record{
    char id[8];
    int hh;
    int mm;
    int ss;
    int time;
    bool isin;
};

//struct nodetime{
//    int time;
//    int partnum = 0;
//    nodetime *next = NULL;
//    nodetime *pre = NULL;
//};

struct car{
    int timeall;
    vector<record> recordc;
};

map<string, car> map1;
vector<int> invec;
vector<int> outvec;
int binarysearch(int querytime){
    int lin= 0 , rin = (int)invec.size();
    int midin;
    while(lin < rin){
        midin = (lin + rin) / 2;
        if(invec[midin] > querytime){
            rin = midin;
        } else{
            lin = midin + 1;
        }
    }

    int lout= 0 , rout = (int)outvec.size();
    int midout;
    while(lout < rout){
        midout = (lout + rout) / 2;
        if(outvec[midout] > querytime){
            rout = midout;
        } else{
            lout = midout + 1;
        }
    }
//    cout << querytime << " " << lin << " " << lout << endl;
    return lin - lout;


}
bool sort1(const record &a, const record &b){
//    if(strcmp(a.id, b.id) != 0){
//        return strcmp(a.id, b.id) < 0;
//    } else{
        return a.time < b.time;
//    }
}

//bool sort2(const timepoit &a, const timepoit &b){
//    return a.time < b.time;
//}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1095/in1095", "r", stdin);
    int recordsnum, queries;
    scanf("%d %d\n", &recordsnum, &queries);
    vector<record> vecr;
    for (int i = 0; i < recordsnum; ++i) {
        record tmpr;
        char state[4];
        scanf("%s %d:%d:%d %s\n", tmpr.id, &tmpr.hh, &tmpr.mm, &tmpr.ss, state);
        if(state[0] == 'i'){
            tmpr.isin = true;
        } else{
            tmpr.isin = false;
        }
        tmpr.time = tmpr.hh * 3600 + tmpr.mm * 60 + tmpr.ss;
        map1[tmpr.id].recordc.push_back(tmpr);
//        vecr.push_back(tmpr);
    }

//    sort(vecr.begin(), vecr.end(), sort1);
    auto map_it = map1.begin();
    int maxpartingtime = 0;
//    vector<timepoit> partnumv;
    vector<string> maxpartingid;
//    nodetime *startnode = NULL;


    for (; map_it != map1.end(); ++map_it) {
        vector<record> vtmp = map_it->second.recordc;
        sort(vtmp.begin(), vtmp.end(), sort1);
        int flgtmp = true;
        int tmpin = 0, tmpout = 0;
        for (int i = 0; i < vtmp.size(); ++i) {
            if(vtmp[i].isin){
                tmpin = vtmp[i].time;
                flgtmp = false;
            } else if(!vtmp[i].isin && !flgtmp){
                tmpout = vtmp[i].time;
                flgtmp = true;
                map_it->second.timeall += tmpout - tmpin;
                invec.push_back(tmpin);
                outvec.push_back(tmpout);
//                if(!startnode){
//                    nodetime *nodes = new nodetime;
//                    nodetime *nodee = new nodetime;
//                    startnode = nodes;
//                    nodes->partnum = 1;
//                    nodes->time = tmpin;
//                    nodes->next = nodee;
//                    nodee->pre = nodes;
//                    nodee->time = tmpout;
//                    nodee->partnum = 0;
//                } else{
//                    nodetime *nodes = new nodetime;
//                    nodetime *nodee = new nodetime;
//                    bool insertflgs = true, insertflge = true;
//                    nodes->time = tmpin;
//                    nodee->time = tmpout;
//                    nodetime *tmpnode;
//                    nodetime *endnode = NULL;
//                    for (tmpnode = startnode; tmpnode; tmpnode = tmpnode->next) {
//                        if(tmpnode->time < nodes->time){
//                            ;
//                        } else if(tmpnode->time == nodes->time){
//                            tmpnode->partnum++;
//                            insertflgs = false;
//                        } else if(tmpnode->time > nodes->time && tmpnode->time < nodee->time){
//                            if(insertflgs){
//                                insertflgs = false;
//                                tmpnode->partnum++;
//                                if(tmpnode == startnode){
//                                    nodes->next = tmpnode;
//                                    tmpnode->pre = nodes;
//                                    startnode = nodes;
//                                    nodes->partnum = 1;
//                                }else{
//                                    tmpnode->pre->next = nodes;
//                                    nodes->pre = tmpnode->pre;
//                                    nodes->next = tmpnode;
//                                    nodes->partnum = nodes->pre->partnum + 1;
//                                    tmpnode->pre = nodes;
//                                }
//                            } else{
//                                tmpnode->partnum++;
//                            }
//                        } else if(tmpnode->time == nodee->time){
//                            insertflge = false;
//                        } else{
//                            if(insertflge) {
//                                insertflge = false;
//                                tmpnode->pre->next = nodee;
//                                nodee->next = tmpnode;
//                                nodee->pre = tmpnode->pre;
//                                if(nodee->pre->partnum - 1 >= 0){
//                                    nodee->partnum = nodee->pre->partnum - 1;
//                                }else{
//                                    nodee->partnum = 0;
//                                }
//                                tmpnode->pre = nodee;
//                            }
//                        }
//                        endnode = tmpnode;
//                    }
//                    if(insertflgs){
//                        endnode->next = nodes;
//                        nodes->pre = endnode;
//                        nodes->partnum = 1;
//                        endnode = nodes;
//                    }
//                    if(insertflge){
//                        endnode->next = nodee;
//                        nodee->pre = endnode;
//                        nodee->partnum = 0;
//                    }
//                }
//---------------------------------

//                int tmpinindex = 0;
//                int tmpoutindex = 0;
//                if(partnumv.empty()){
//                    timepoit timepoitin;
//                    timepoit timepoitout;
//                    timepoitin.time = tmpin;
//                    timepoitin.partnum = 1;
//                    timepoitout.time = tmpout;
//                    timepoitout.partnum = 0;
//                    partnumv.push_back(timepoitin);
//                    partnumv.push_back(timepoitout);
//                } else{
//                    for (int j = 0; j < partnumv.size(); ++j) {
//                        if(tmpin > partnumv[j].time){
//                            tmpinindex++;
//                        }
//                        if(tmpout > partnumv[j].time){
//                            tmpoutindex++;
//                        }else{
//                            break;
//                        }
//                        if(tmpin <= partnumv[j].time && partnumv[j].time < tmpout){
//                            partnumv[j].partnum++;
//                        }
//                    }


//                    timepoit timepoitin;
//                    timepoit timepoitout;
//                    timepoitin.time = tmpin;
//                    if(tmpinindex == 0){
//                        timepoitin.partnum = 1;
//                        partnumv.push_back(timepoitin);
//                    } else if(tmpinindex != partnumv.size() && tmpin == partnumv[tmpinindex].time){
//                        partnumv[tmpinindex].partnum++;
//                    } else{
//                        timepoitin.partnum = partnumv[tmpinindex - 1].partnum + 1;
//                        partnumv.push_back(timepoitin);
//                    }
//                    timepoitout.time = tmpout;
//                    if(tmpoutindex == 0){
//                        timepoitout.partnum = 0;
//                        partnumv.push_back(timepoitout);
//                    } else if(tmpoutindex != partnumv.size() && tmpout == partnumv[tmpoutindex].time){
//                        ;
//                    } else{
//                        timepoitout.partnum = partnumv[tmpoutindex - 1].partnum - 1;
//                        partnumv.push_back(timepoitout);
//                    }
//                    sort(partnumv.begin(), partnumv.end(), sort2);
//                }
//                for (int u = 0; u < partnumv.size(); ++u) {
//                    cout << partnumv[u].time << " " << partnumv[u].partnum << endl;
//                }
//                nodetime *snode = startnode;
//                for (; snode; snode = snode->next) {
//                    cout << snode->time << " " << snode->partnum << endl;
//                }
//                cout << "--------------"<< endl;
            }
//            cout << vtmp[i].id << " "<< vtmp[i].hh << ":" << vtmp[i].mm << ":" << vtmp[i].ss << " " << vtmp[i].time << " " << vtmp[i].isin << endl;
        }
        if(map_it->second.timeall > maxpartingtime){
            maxpartingtime = map_it->second.timeall;
            maxpartingid.clear();
            maxpartingid.push_back(map_it->first);
        } else if(map_it->second.timeall == maxpartingtime){
            maxpartingid.push_back(map_it->first);
        }
//        cout << "sum: " << map_it->second.timeall << endl;
//        cout << endl;
    }
//    nodetime *snode = startnode;
//    for (; snode; snode = snode->next) {
//        cout << snode->time << " " << snode->partnum << endl;
//    }
//    for (int i = 0; i < partnumv.size(); ++i) {
//        cout << partnumv[i].time << " " << partnumv[i].partnum << endl;
//    }

    sort(invec.begin(), invec.end());
    sort(outvec.begin(), outvec.end());
//    for (int i = 0; i < invec.size(); ++i) {
//        cout << invec[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < outvec.size(); ++i) {
//        cout << outvec[i] << " ";
//    }
//    cout << endl;
    for (int i = 0; i < queries; ++i) {
        int qhh, qmm, qss, qtime;
        scanf("%d:%d:%d", &qhh, &qmm, &qss);
        qtime = qhh * 3600 + qmm * 60 + qss;
        int partnum = binarysearch(qtime);
        printf("%d\n", partnum);
//------------------------------------------------------
//        nodetime *qnode = startnode;
//        for (; qnode; qnode = qnode->next) {
//            if(qtime < qnode->time){
//                break;
//            }
//        }
//        if(!qnode){
//            printf("0\n");
//        }else{
//            printf("%d\n", qnode->pre->partnum);
//        }
//-----------------------------------------------------
//        int pindex = -1;
//        for (int j = 0; j < partnumv.size(); ++j) {
//            if(qtime > partnumv[j].time){
//                pindex++;
//            }
//        }
//        if(pindex == -1){
//            printf("0\n");
//        }else{
//            printf("%d\n", partnumv[pindex].partnum);
//        }

    }
    
    
    
    sort(maxpartingid.begin(), maxpartingid.end());
    for (int i = 0; i < maxpartingid.size(); ++i) {
        cout << maxpartingid[i] << " ";
    }
    printf("%02d:%02d:%02d", maxpartingtime/3600, maxpartingtime%3600/60, maxpartingtime%60);
//    for (int i = 0; i < vecr.size(); ++i) {
//        cout << vecr[i].id << " "<< vecr[i].hh << ":" << vecr[i].mm << ":" << vecr[i].ss << " " << vecr[i].isin << endl;
//    }
    return 0;
}