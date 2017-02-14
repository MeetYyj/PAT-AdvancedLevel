#include <iostream>
using namespace std;

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1048/in1048", "r", stdin);
    int num, price;
    scanf("%d %d\n", &num, &price);

    int coin[1001];
    for (int i = 0; i < 1001; ++i) {
        coin[i] = 0;
    }
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        coin[tmp]++;
    }
    bool flg = false;
    int v1, v2;
    for (int i = 1; i < price; ++i) {
        if(coin[i] != 0){
//            coin[i]--;
//            if(coin[price - i]){
//                v1 = i;
//                v2 = price - i;
//                flg = true;
//                break;
//            }
            if(i * 2 != price && coin[(price - i)] != 0){
                v1 = i;
                v2 = price - v1;
                flg = true;
                break;
            } else if(i * 2 == price && coin[i] >= 2){
                v1 = v2 = i;
                flg = true;
                break;
            }
        }
    }
    if(flg){
        printf("%d %d", v1, v2);
    }else{
        printf("No Solution");
    }
    return 0;
}