#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int num;
    scanf("%d", &num);
    int a[4], b[4];
    int tmp = num;
    int tmp2 = num;
    bool flg = false;
    for (int i = 0; i < 4; ++i) {
        b[i] = tmp % 10;
        tmp /= 10;
    }
    if(b[0] == b[1] && b[1] == b[2] && b[2] == b[3]){
        flg = true;
    }
    if (flg){
        printf("%04d - %04d = 0000\n", num, num);
        return 0;
    }
    while(1){
        tmp = tmp2;
        for (int i = 0; i < 4; ++i) {
            b[i] = tmp % 10;
            tmp /= 10;
        }
        sort(b, b+4);
        for (int i = 0; i < 4; ++i) {
            a[3 - i] = b[i];
        }
        int a1 = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        int b1 = b[0] * 1000 + b[1] * 100 + b[2] * 10 + b[3];
        tmp2 = a1 - b1;
        if(tmp2 == 6174){
            printf("%04d - %04d = %04d\n", a1, b1, tmp2);
            break;
        }
        else{
            printf("%04d - %04d = %04d\n", a1, b1, tmp2);
        }
    }


    return 0;
}