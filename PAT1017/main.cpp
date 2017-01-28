#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int custom, window;
struct cus{
    int hh, mm, ss;
    int arrivingtime;
    int processingTime;
};

bool isearlier(const cus &a, const cus &b){
    return a.arrivingtime < b.arrivingtime;
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1017/in1017", "r", stdin);
    scanf("%d %d\n", &custom, &window);
    vector<cus> cvec;
    for (int i = 0; i < custom; ++i) {
        cus ctmp;
        scanf("%d:%d:%d %d\n", &ctmp.hh, &ctmp.mm, &ctmp.ss, &ctmp.processingTime);
        ctmp.arrivingtime = ctmp.hh * 3600 + ctmp.mm * 60 + ctmp.ss;
        cvec.push_back(ctmp);
    }
    sort(cvec.begin(), cvec.end(), isearlier);
    int currenttime = 8 * 3600;
    int spendtime = 0;
    int waitingtime = 0;
    vector<int> vwindow(window, 0);
//    fill(vwindow.begin(), vwindow.end(), 100);
//    cout << vwindow[2] << endl;
    int validcus = 0;
    for (int i = 0; i < custom; ++i) {
        if(cvec[i].arrivingtime <= 8*3600){
            waitingtime += 8 * 3600 - cvec[i].arrivingtime;
        } else if(cvec[i].arrivingtime >= 17 * 3600){
            continue;
        } else if(cvec[i].arrivingtime > currenttime){
            spendtime = cvec[i].arrivingtime - currenttime;
            currenttime = cvec[i].arrivingtime;
            for (int j = 0; j < vwindow.size(); ++j) {
                vwindow[j] -= spendtime;
                if(vwindow[j] < 0){
                    vwindow[j] = 0;
                }
            }
        } else{
            waitingtime += currenttime - cvec[i].arrivingtime;
        }
        int minindex = 0;
        int mintime = 9999999999;
        for (int j = 0; j < vwindow.size(); ++j) {
            if(vwindow[j] < mintime){
                minindex = j;
                mintime = vwindow[j];
            }
        }
        if(mintime > 0){
            waitingtime += mintime;
            for (int j = 0; j < vwindow.size(); ++j) {
                vwindow[j] -= mintime;
            }
            vwindow[minindex] = cvec[i].processingTime * 60;
            currenttime += mintime;
        } else {
            vwindow[minindex] = cvec[i].processingTime * 60;
        }
//        for (int k = 0; k < vwindow.size(); ++k) {
//            cout << vwindow[k]<< ":";
//        }
//        cout << endl;
        validcus++;
    }
//    for (int i = 0; i < cvec.size(); ++i) {
//        cout << cvec[i].hh << ":" << cvec[i].mm << ":" << cvec[i].ss << " " << cvec[i].processingTime << endl;
//    }
    double averageWaitingtime = (double)waitingtime / validcus / 60;
    printf("%.1lf", averageWaitingtime);
    return 0;
}