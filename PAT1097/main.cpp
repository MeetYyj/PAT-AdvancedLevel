#include <iostream>
#include <vector>
using namespace std;
struct node{
    int addr;
    int data;
    int next;
}nodes[100001];
bool iscollected[100001];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1097/in1097", "r", stdin);
    int start, num;
    scanf("%d%d", &start, &num);
    for (int i = 0; i < num; ++i) {
        int addrtmp;
        scanf("%d", &addrtmp);
        scanf("%d%d", &nodes[addrtmp].data, &nodes[addrtmp].next);
        nodes[addrtmp].addr = addrtmp;
    }
    int sflg = true;
    vector<node> resv, rmv;
    for (int i = start; i != -1; i = nodes[i].next) {
        if(!iscollected[abs(nodes[i].data)]){
            iscollected[abs(nodes[i].data)] = true;
            resv.push_back(nodes[i]);
        }else{
            rmv.push_back(nodes[i]);
        }
    }


    for (int i = 0; i < resv.size(); ++i) {
        if(i != resv.size() - 1){
            printf("%05d %d %05d\n", resv[i].addr, resv[i].data, resv[i+1].addr);
        }else{
            printf("%05d %d -1\n", resv[i].addr, resv[i].data);
        }
    }
    for (int i = 0; i < rmv.size(); ++i) {
        if(i != rmv.size() - 1){
            printf("%05d %d %05d\n", rmv[i].addr, rmv[i].data, rmv[i+1].addr);
        }else{
            printf("%05d %d -1\n", rmv[i].addr, rmv[i].data);
        }
    }
    return 0;
}