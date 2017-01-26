#include <iostream>
#include <vector>
using namespace std;
int windows, capacity, kcustom, qqueries;
int sum[20];
struct custom{
    int starttime;
    int time;
};
vector<custom> vcustom;

int insertCustomFull(int tmp, vector<vector<int>> &yellowv){
    int minW = 9999, minIndex = 0;
    for (int i = 0; i < windows; ++i) {
        if(yellowv[i][0] < minW){
            minIndex = i;
            minW = yellowv[i][0];
        }
    }
    for (int i = 0; i < windows; ++i) {
        if(yellowv[i][0] != 0)
            yellowv[i][0] -= minW;
    }
    for (int i = 0; i < capacity - 1; ++i) {
        yellowv[minIndex][i] = yellowv[minIndex][i + 1];
    }
    yellowv[minIndex][capacity - 1] = tmp;
    sum[minIndex] += tmp;
    return sum[minIndex];
}

int insertCustomUnfull(int tmp, int whichwindow, vector<vector<int>> &yellowv){
    yellowv[whichwindow].push_back(tmp);
    sum[whichwindow] += tmp;
    return sum[whichwindow];
}

int isempty(vector<vector<int>> &yellowv){
    int minNum = 9999, index = 0;
    for (int i = 0; i < windows; ++i) {
        if(yellowv[i].size() < minNum){
            minNum = yellowv[i].size();
            index = i;
        }
    }
    if(minNum == capacity){
        return -1;
    } else {
        return index;
    }
}

void showtime(custom cus){
    if( cus.starttime >= 540){
        printf("Sorry\n");
    } else{
        int hour = 8 + cus.time / 60;
        int min = cus.time % 60;
        printf("%02d:%02d\n", hour,min);
    }
}

int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1014/in1014", "r", stdin);
    scanf("%d%d%d%d", &windows, &capacity, &kcustom, &qqueries);
    fill(sum, sum+20, 0);
    vector<vector<int>> yellowv(windows);
    for (int i = 0; i < kcustom; ++i) {
        int tmp;
        scanf("%d", &tmp);
        custom ctmp;
        int whichwindow = isempty(yellowv);
        if(whichwindow == -1){
            ctmp.time = insertCustomFull(tmp, yellowv);
        } else {
            ctmp.time = insertCustomUnfull(tmp, whichwindow, yellowv);
        }
        ctmp.starttime = ctmp.time - tmp;
//        cout << ctmp.time << endl;
        vcustom.push_back(ctmp);
    }

    for (int i = 0; i < qqueries; ++i) {
        int request;
        scanf("%d", &request);
        showtime(vcustom[request-1]);
    }
    return 0;
}