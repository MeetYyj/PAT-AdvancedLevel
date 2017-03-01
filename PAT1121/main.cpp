#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person{
    int id;
    int cid;
    bool iscome;
}persons[100001];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1121/in1121", "r", stdin);
    int couplenum;
    scanf("%d", &couplenum);
    for (int i = 0; i < couplenum; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        persons[v1].id = v1;
        persons[v1].cid = v2;
        persons[v2].id = v2;
        persons[v2].cid = v1;
    }
    int num;
    scanf("%d", &num);
    vector<int> vec;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        persons[persons[tmp].cid].iscome = true;
        vec.push_back(tmp);
    }
    vector<int> vout;
    for (int j = 0; j < vec.size(); ++j) {
        if(!persons[vec[j]].iscome){
            vout.push_back(vec[j]);
        }
    }
    sort(vout.begin(), vout.end());
    printf("%ld\n", vout.size());
    for (int i = 0; i < vout.size(); ++i) {
        if(i)
            printf(" ");
        printf("%05d", vout[i]);
    }
    return 0;
}