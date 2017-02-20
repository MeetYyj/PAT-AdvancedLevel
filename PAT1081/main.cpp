#include <iostream>
using namespace std;
int findlcm(int a, int b){
    int tmpa = a, tmpb = b;
    while(tmpa % tmpb){
        int tmp = tmpa % tmpb;
        tmpa = tmpb;
        tmpb = tmp;
    }
    return a * b / tmpb;
}

void calfunc(int &a, int &b, int &a1, int &b1){
    int lcm = findlcm(b, b1);
    a = lcm/b*a + lcm/b1*a1;
    b = lcm;
    if(a == 0){
        b = 1;
        return;
    }
    int tmpa = a, tmpb = b;
    while(tmpa % tmpb){
        int tmp = tmpa % tmpb;
        tmpa = tmpb;
        tmpb = tmp;
    }
    a /= tmpb;
    b /= tmpb;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1081/in1081", "r", stdin);
    int num;
    scanf("%d", &num);
    int a = 0,b = 1;
    for (int i = 0; i < num; ++i) {
        int tmpa, tmpb;
        scanf("%d/%d", &tmpa, &tmpb);
        calfunc(a, b, tmpa, tmpb);
    }
    if(b == 1){
        printf("%d", a);
    } else if(abs(a) > b){
        printf("%d %d/%d", a/b, abs(a)%b, b);
    } else{
        printf("%d/%d", a, b);
    }
    return 0;
}