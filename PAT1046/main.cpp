#include <iostream>
using namespace std;
int sum[100002];
int main(){
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1046/in1046", "r", stdin);
    int num;
    scanf("%d", &num);
    for (int i = 2; i <= num + 1; ++i) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    int ask;
    scanf("%d", &ask);
    for (int i = 0; i < ask; ++i) {
        int tmp1, tmp2, tmp;
        scanf("%d%d", &tmp1, &tmp2);
        if(tmp1 > tmp2){
            tmp = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        int tmpsum = sum[tmp2] - sum[tmp1];
        int out = min(tmpsum, sum[num + 1] - tmpsum);
        printf("%d\n", out);
    }
    return 0;
}