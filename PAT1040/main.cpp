#include <iostream>

int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1040/in1040", "r", stdin);
    char str[1001];
    int i = 0;
    while((str[i] = getchar()) != '\n'){
        i++;
    }
    str[i] = '\0';
    int longestsy = 1;
    for (int j = 0; j < i; ++j) {
        int longlen = 1;
        for (int k = 1; j - k >= 0 && j + k < i; ++k) {
            if(str[j-k] == str[j+k]){
                longlen += 2;
            } else {
                break;
            }
        }
        if(longlen > longestsy){
            longestsy = longlen;
        }
    }
    for (int j = 0; j < i; ++j) {
        int longlen = 0;
        for (int k = 1; j - k + 1 >= 0 && j + k < i; ++k) {
            if(str[j-k+1] == str[j+k]){
                longlen += 2;
            } else {
                break;
            }
        }
        if(longlen > longestsy){
            longestsy = longlen;
        }
    }
    printf("%d", longestsy);
    return 0;
}