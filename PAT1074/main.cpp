#include <iostream>
#include <vector>

using namespace std;
struct node{
    int addr;
    int data;
    int next;
}nodes[100001];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1074/in1074", "r", stdin);
    int s, num, k;
    scanf("%d%d%d", &s, &num, &k);
    for (int i = 0; i < num; ++i) {
        int tmpaddr;
        scanf("%d", &tmpaddr);
        nodes[tmpaddr].addr = tmpaddr;
        scanf("%d%d", &nodes[tmpaddr].data, &nodes[tmpaddr].next);
    }
    int len = 0;
    vector<node> nvec;
    for (int i = s; i!= -1; i = nodes[i].next) {
        len++;
        nvec.push_back(nodes[i]);
    }
    int tmplen = len;
    vector<int> order;
    int cnt = 1;
    for (int i = 0; i < len; ++i) {
        if(tmplen >=  k){
            tmplen -= k;
            for (int j = 1; j <= k; ++j) {
                order.push_back(k * cnt - j);
            }
        } else{
            for (int j = 0; j < tmplen; ++j) {
                order.push_back(k * (cnt - 1) + j);
            }
            tmplen = 0;
        }
        cnt++;
    }
    for (int i = 0; i < order.size(); ++i) {
//        cout << order[i] << endl;
        if(i != order.size() - 1){
            printf("%05d %d %05d\n", nvec[order[i]].addr, nvec[order[i]].data, nvec[order[i+1]].addr);
        } else{
            printf("%05d %d -1\n", nvec[order[i]].addr, nvec[order[i]].data);

        }
    }
    return 0;
}