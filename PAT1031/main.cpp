#include <iostream>
using namespace std;
int main() {
    char c[81];
    int i = 0;
    char tmpc;
    while ((tmpc = getchar()) != '\n'){
        c[i] = tmpc;
        i++;
    }
    c[i] = '\0';
    int n1 = (i + 2)/3;
    for (int j = 0; j < n1 -1; ++j) {
        printf("%c", c[j]);
        for (int k = 0; k < (i - n1 *2); ++k) {
            printf(" ");
        }
        printf("%c\n", c[i - 1 - j]);
    }
    for (int j = 0; j < (i - (n1 - 1) * 2); ++j) {
        printf("%c", c[j + n1 - 1]);
    }
//    cout << c << endl;
    return 0;
}