#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int rate[24];
struct rec{
    int MM,DD,hh,mm;
    int online; //online = 1, offline = 0
};
struct custom{
    string name;
    vector<rec> records;
    double cost = 0;
};

struct pri{
    int oDD, ohh, omm, fDD, fhh, fmm, min;
    double cost;
};
pri pri1;

bool compareTime(const rec &a, const rec &b){
    return a.DD * 24 * 60 + a.hh * 60 + a.mm <
            b.DD * 24 * 60 + b.hh * 60 + b.mm;
}
bool compareName(const custom &a, const custom &b){
    return a.name < b.name;
}

void calcost(int onlineIndex, int offlineIndex, custom &a){
    rec onlineRec = a.records[onlineIndex];
    rec offlineRec = a.records[offlineIndex];
    int mintotal = ((offlineRec.DD - onlineRec.DD) * 24
                    + (offlineRec.hh - onlineRec.hh))* 60
                    + offlineRec.mm - onlineRec.mm;
    int mintotalp = mintotal;
    int cnt = onlineRec.hh;
    double reccost = 0;
    if(mintotal <= (60 - onlineRec.mm)){
        reccost += mintotal * rate[cnt];
        mintotal = 0;
    } else {
        reccost += (60 - onlineRec.mm) * rate[cnt];
        mintotal -= (60 - onlineRec.mm);
        cnt++;
    }
    while (mintotal >= 60){
        reccost += 60 * rate[cnt%24];
        cnt++;
        mintotal -= 60;
    }
    reccost += mintotal * rate[cnt%24];
    reccost /= 100;
    a.cost += reccost;
    pri1.oDD = onlineRec.DD;
    pri1.ohh = onlineRec.hh;
    pri1.omm = onlineRec.mm;
    pri1.fDD = offlineRec.DD;
    pri1.fhh = offlineRec.hh;
    pri1.fmm = offlineRec.mm;
    pri1.min = mintotalp;
    pri1.cost = reccost;
//    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02lf\n",
//           onlineRec.DD, onlineRec.hh, onlineRec.mm,
//           offlineRec.DD, offlineRec.hh, offlineRec.mm,
//           mintotalp, reccost);


//    cout << onlineRec.DD << ":" << onlineRec.hh << ":" << onlineRec.mm << endl;
//    cout << offlineRec.DD << ":" << offlineRec.hh << ":" << offlineRec.mm << endl;
//    cout << reccost << endl;
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1016/in1016a", "r", stdin);
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &rate[i]);
    }
    int records;
    scanf("%d\n", &records);
    vector<custom> cvec;
    for (int i = 0; i < records; ++i) {
        char name[21], state[9];
        rec tmprec;
        scanf("%s %d:%d:%d:%d %s\n",
              &name, &tmprec.MM, &tmprec.DD, &tmprec.hh, &tmprec.mm, &state);
        string sname = name;
        if (state[1] == 'n'){
            tmprec.online = 1;
        } else {
            tmprec.online = 0;
        }
        int cindex = -1;
        for (int j = 0; j < cvec.size(); ++j) {
            if(sname == cvec[j].name){
                cindex = j;
                break;
            }
        }
        if(cindex == -1){
            custom ctmp;
            ctmp.name = sname;
            ctmp.records.push_back(tmprec);
            cvec.push_back(ctmp);
        } else{
            cvec[cindex].records.push_back(tmprec);
        }
    }
    sort(cvec.begin(), cvec.end(), compareName);
    for (int i = 0; i < cvec.size(); ++i) {
        sort(cvec[i].records.begin(), cvec[i].records.end(), compareTime);
        bool flgonline = false;
        bool flgvalid = true;
        bool flgvalid1 = false;
        int onlineIndex, offlineIndex;
        for (int j = 0; j < cvec[i].records.size(); ++j) {
            if(cvec[i].records[j].online){
                flgonline = true;
                onlineIndex = j;
            }
            if(flgonline){
                if(cvec[i].records[j].online == 0){
                    offlineIndex = j;
                    calcost(onlineIndex, offlineIndex, cvec[i]);
                    if(pri1.cost != 0){
                        if(flgvalid){
                            cout << cvec[i].name;
                            printf(" %02d\n", cvec[i].records[0].MM);
                            flgvalid = false;
                            flgvalid1 = true;
                        }
                        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02lf\n",
                               pri1.oDD, pri1.ohh, pri1.omm,
                               pri1.fDD, pri1.fhh, pri1.fmm,
                               pri1.min, pri1.cost);
                        flgonline = false;
                    }
                }
            }
        }
        if(flgvalid1){
            cout << "Total amount: $";
            printf("%.2lf\n", cvec[i].cost);
        }


//        for (int j = 0; j < cvec[i].records.size(); ++j) {
//            cout << cvec[i].name << endl;
//            cout << cvec[i].records[j].DD << ":" << cvec[i].records[j].hh << ":" << cvec[i].records[j].mm << endl;
//        }
    }
    
    return 0;
}