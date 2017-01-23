#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    if(c < 0){
        printf("-");
        c = -c;
    }
    if(c == 0){
        printf("0");
    } else {
        int num = (int)(log(c)/log(1000));
        printf("%d", c/(int)pow(1000,num));
        c %= (int)pow(1000,num);
        num--;
        while(num >= 0){
            printf(",%03d", c/(int)pow(1000,num));
            c %= (int)pow(1000,num);
            num--;
        }
    }

    return 0;
}