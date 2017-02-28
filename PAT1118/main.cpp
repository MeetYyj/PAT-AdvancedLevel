#include <iostream>
#include <vector>

using namespace std;
int pa[10001];
int find(int a){
    while(pa[a] != a){
        a = pa[a];
    }
    return a;
};

void union1(int a, int b){
    int ppa = find(a);
    int ppb = find(b);
    if(ppa == ppb){
        return;
    }else{
        pa[ppa] = ppb;
        return;
    }
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1118/in1118", "r", stdin);
    int num;
    scanf("%d", &num);
    int maxx = -1;
    for (int i = 1; i <= 10000; ++i) {
        pa[i] = i;
    }
    for (int i = 0; i < num; ++i) {
        int k;
        scanf("%d", &k);
        int t;
        scanf("%d", &t);
        maxx = max(t, maxx);
        for (int j = 0; j < k - 1; ++j) {
            int tmp;
            scanf("%d", &tmp);
            maxx = max(tmp, maxx);
            union1(t, tmp);
        }
    }

    int cnttree = 0;
    for (int i = 1; i <= maxx; ++i) {
        if(pa[i] == i)
            cnttree++;
    }

    printf("%d %d\n", cnttree, maxx);
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; ++i) {
        int b1, b2;
        scanf("%d%d", &b1, &b2);
        if(find(b1) == find(b2)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
//    for (int i = 1; i <= 10; ++i) {
//        cout << pa[i] << ' ';
//    }
    return 0;
}