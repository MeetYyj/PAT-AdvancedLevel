#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int hashname(char *c){
    return  (c[0] - 'A') * 26 * 26 *10 +
            (c[1] - 'A') * 26 * 10 +
            (c[2] - 'A') * 10 +
            (c[3] - '0');
}



int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1047/in1047", "r", stdin);
    int stunum, cournum;
    scanf("%d %d\n", &stunum, &cournum);
    vector<vector<int>> cvec(cournum);
    for (int i = 0; i < stunum; ++i) {
        char name[5];
        scanf("%s", name);
        int hname = hashname(name);
        int tnum;
        scanf("%d", &tnum);
        for (int j = 0; j < tnum; ++j) {
            int cnum;
            scanf("%d", &cnum);
            cvec[cnum - 1].push_back(hname);
        }
    }
    for (int i = 0; i < cvec.size(); ++i) {
        printf("%d %ld\n", i + 1, cvec[i].size());
        sort(cvec[i].begin(), cvec[i].end());
        for (int j = 0; j < cvec[i].size(); ++j) {
            int numname = cvec[i][j];
            printf("%c%c%c%c\n", numname/26/26/10 + 'A', numname/26/10 %26 + 'A', numname/10%26 + 'A', numname%10 + '0');
        }
    }
    return 0;
}