#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int addr;
    int data;
    int next;
}nodes[100001];

bool sort1(const node &a, const node &b){
    return a.data < b.data;
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1052/in1052a", "r", stdin);
    int num, start;
    scanf("%d%d", &num, &start);
    for (int i = 0; i < num; ++i) {
        int addr, tmpdata, tmpnext;
        scanf("%d%d%d", &addr, &tmpdata, &tmpnext);
        nodes[addr].addr = addr;
        nodes[addr].data = tmpdata;
        nodes[addr].next = tmpnext;
    }
    vector<node> vnode;
    for (int i = start; i != -1; i = nodes[i].next) {
        vnode.push_back(nodes[i]);
    }
//    cout << vnode.size() << endl;
    if(vnode.size() == 0){
        printf("0 -1");
    } else{
        sort(vnode.begin(), vnode.end(), sort1);
        printf("%ld %05d\n", vnode.size(), vnode[0].addr);
        for (int i = 0; i < vnode.size(); ++i) {
            if(i != vnode.size() - 1){
                printf("%05d %d %05d\n", vnode[i].addr, vnode[i].data, vnode[i+1].addr);
            } else{
                printf("%05d %d -1\n", vnode[i].addr, vnode[i].data);
            }
        }
    }


    return 0;
}