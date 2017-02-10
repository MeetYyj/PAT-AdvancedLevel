#include <iostream>
using namespace std;
struct node{
    int addr;
    char c;
    int next;
    int cnt = 0;
    bool flg = false;
}nodes[100005];
int start1, start2, num;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1032/in1032a", "r", stdin);
    scanf("%d %d %d\n", &start1, &start2, &num);
    for (int i = 0; i < num; ++i) {
        node tmp;
        scanf("%d %c %d\n", &tmp.addr, &tmp.c, &tmp.next);
        nodes[tmp.addr] = tmp;
    }
    for (int i = start1; i != -1 ; i = nodes[i].next) {
        nodes[i].flg = true;
    }
    int i;
    for ( i= start2; i != -1 ; i = nodes[i].next) {
        if(nodes[i].flg){
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");

    return 0;
}