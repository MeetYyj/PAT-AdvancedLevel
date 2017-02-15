#include <iostream>
using namespace std;
int main() {
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int cnt3 = 0, cnt2 = 0;
    if(b3 + a3 >= 29){
        c3 = a3 + b3 - 29;
        cnt3 = 1;
    }else{
        c3 = a3 + b3;
    }

    if(b2 + a2 + cnt3 >= 17){
        c2 = a2 + b2 + cnt3 - 17;
        cnt2 = 1;
    }else{
        c2 = a2 + b2 + cnt3;
    }
    c1 = a1 + b1 + cnt2;
    printf("%d.%d.%d", c1, c2, c3);
    return 0;
}