#include <iostream>
using namespace std;
int main() {
    char num1[21], num2[21];
    int digit[2][10];

    for (int k = 0; k < 21; ++k) {
        num1[k] = '\0';
        num2[k] = '\0';
    }
    for (int m = 0; m < 10; ++m) {
        digit[0][m] = 0;
        digit[1][m] = 0;
    }
    int i = 0;
    char tmpc;
    while((tmpc = getchar()) != '\n'){
        num1[i] = tmpc;
        i++;
    }
    int g = 0;
    for (int j = i - 1; j >= 0; --j) {
        int tmpi = num1[j] - '0';
        tmpi *= 2;
        if(tmpi >= 10){
            num2[g+1] = '1';
        }
        if(num2[g] != '1'){
            num2[g] = tmpi%10 + '0';
        } else {
            num2[g] += tmpi%10;
        }
        g++;
    }
    int j = 0;
    while(num1[j] != '\0'){
        digit[0][num1[j] - '0']++;
        j++;
    }
    j = 0;
    while(num2[j] != '\0'){
        digit[1][num2[j] - '0']++;
        j++;
    }
    bool flg = true;
    for (int l = 0; l < 10; ++l) {
        if(digit[0][l] != digit[1][l]){
            flg =false;
            break;
        }
    }
    if(flg){
        cout << "Yes" << endl;
        j--;
        while(j >= 0){
            printf("%c", num2[j]);
            j--;
        }
    } else{
        cout << "No" << endl;
        j--;
        while(j >= 0){
            printf("%c", num2[j]);
            j--;
        }
    }
    return 0;
}