#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct p{
    int w;
    int rank;
}p1[1000];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1056/in1056", "r", stdin);
    int num, group;
    scanf("%d%d", &num, &group);
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        p1[i].w = tmp;
    }
    vector<int> gindex;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        gindex.push_back(tmp);
    }

    vector<int> tmpindex;
    while(!gindex.empty()){
        int index = 0;
        int maxw = -1, maxindex = 0;
        if(gindex.size() == 1){
            p1[gindex[0]].rank = 1;
            break;
        } else{
            while(index != gindex.size()){
                for (int j = 0; j < group && index != gindex.size(); ++j) {
                    if(p1[gindex[index]].w > maxw){
                        maxw = p1[gindex[index]].w;
                        maxindex = gindex[index];
                    }
                    index++;
                }
                tmpindex.push_back(maxindex);
                maxw = -1;
                maxindex = 0;
            }
            for (int i = 0; i < gindex.size(); ++i) {
                p1[gindex[i]].rank = (int)tmpindex.size() + 1;
            }
            gindex = {tmpindex.cbegin(), tmpindex.cend()};
            tmpindex.clear();
        }


    }

    for (int i = 0; i < num; ++i) {
        if(i != 0){
            printf(" ");
        }
        printf("%d", p1[i].rank);
    }


    return 0;
}