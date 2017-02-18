#include <iostream>
using namespace std;
struct node{
    int addr = -1;
    int data = -1;
    bool iscollected = false;
}nodes[100001];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1067/in1067c", "r", stdin);
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        nodes[i].data = tmp;
        nodes[i].addr = i;
        if(tmp == i){
            nodes[i].iscollected = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < num; ++i) {
        if(!nodes[i].iscollected){
            nodes[i].iscollected = true;
            int tmp = i;
            bool flg = true;
            if(nodes[tmp].data == 0){
                flg = false;
            } else{
                cnt++;
            }
            while(nodes[tmp].data != i){
                tmp = nodes[tmp].data;
                nodes[tmp].iscollected = true;
                if(nodes[tmp].data == 0){
                    flg = false;
                } else{
                    cnt++;
                }
            }
            if(flg){
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}