#include <iostream>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1050/in1050", "r", stdin);
    char s1[10001];
    bool flg[1000];
    char tmp;
    int i = 0;
    while((tmp = getchar()) != '\n'){
        s1[i] = tmp;
        i++;
    }
    s1[i] = '\0';
    for (int j = 0; j < 1000; ++j) {
        flg[j] = true;
    }
    while((tmp = getchar()) != '\n'){
        flg[tmp] = false;
    }
    for (int k = 0; k < i; ++k) {
        if(flg[s1[k]]){
            printf("%c", s1[k]);
        }
    }
    return 0;
}