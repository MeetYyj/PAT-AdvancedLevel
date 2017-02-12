#include <iostream>
using namespace std;
string s[55] =  {"  ",
                 "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
                 "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
                 "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
                 "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
                 "J1", "J2"};
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1042/in1042", "r", stdin);
    int num;
    scanf("%d", &num);
    int req[55];
    for (int i = 1; i < 55; ++i) {
        scanf("%d", &req[i]);
    }
    int tmp[55];
    for (int i = 1; i < 55; ++i) {
        tmp[i] = i;
    }
    int tmp2[55];
    for (int i = 0; i < num; ++i) {
        for (int j = 1; j < 55; ++j) {
            tmp2[j] = tmp[j];
        }
        for (int j = 1; j < 55; ++j) {
            tmp[req[j]] = tmp2[j];
        }

    }
    for (int i = 1; i < 54; ++i) {
        cout << s[tmp[i]] << " ";
    }
    cout << s[tmp[54]];
    return 0;
}

//char c[6] = {"SHCDJ"};
//for(int i = 1; i < 55; i++) {
//     end[i] = end[i] - 1;
//     printf("%c%d", c[end[i] / 13], end[i] % 13 + 1);
//     if(i != 54) printf(" ");
//}