#include <iostream>
#include <vector>
using namespace std;
int graph[201][201];
bool iscollected[201];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1122/in1122", "r", stdin);
    int num;
    scanf("%d", &num);
    int edges;
    scanf("%d", &edges);
    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    int queries;
    scanf("%d", &queries);
    for (int i = 0; i < queries; ++i) {
        int k;
        scanf("%d", &k);
        bool flg = true;
        for (int j = 1; j <= num; ++j) {
            iscollected[j] = false;
        }
        if(k != num + 1){
            flg = false;
        }
        vector<int> vec;
        for (int j = 0; j < k; ++j) {
            int tmp;
            scanf("%d", &tmp);
            vec.push_back(tmp);
            if(j == 0){

            }else{
                if(iscollected[tmp]){
                    flg = false;
                }else{
                    iscollected[tmp] = true;
                }
            }
        }
        for (int j = 0; j < vec.size() - 1; ++j) {
            if(!graph[vec[j]][vec[j+1]]){
                flg = false;
            }
        }
        if(flg){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}