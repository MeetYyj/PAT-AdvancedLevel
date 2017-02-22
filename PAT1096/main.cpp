#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
    int num;
    scanf("%d", &num);
    int maxlenth = 1;
    int maxnum = num;
    for (int i = (int)sqrt(num) + 1; i >= 2; --i) {
        int tmpnum = num;
        if(!(tmpnum % i)){
            int lengthtmp = 0;
            int num1 = i;
            do{
                tmpnum /= num1;
                num1--;
                lengthtmp++;
                if(num1 == 1){
                    break;
                }
            }while(!(tmpnum % num1));
            if(lengthtmp >= maxlenth){
                maxnum = i;
                maxlenth = lengthtmp;
            }
        }
    }
    printf("%d\n", maxlenth);
    for (int j = 0; j < maxlenth; ++j) {
        if(j != 0){
            printf("*");
        }
        printf("%d", maxnum - maxlenth + j + 1);
    }

    return 0;
}