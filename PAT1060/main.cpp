#include <iostream>
using namespace std;
void change(char *c, char *t, int &exp, int n){
    t[0] = '0';
    t[1] = '.';
    int lent = 0;
    int i = 0;
    bool iflg = true;
    while(c[i] != '.' && c[i] != '\0'){
        if(c[i] == '0' && iflg){

        }else{
            exp++;
            t[2+lent] = c[i];
            lent++;
            iflg = false;
        }
        i++;
    }
    bool digitflg = true;
    if(c[i] == '.'){
        i++;
        while(c[i] != '\0'){
            if(digitflg && iflg){
                if(c[i] == '0'){
                    exp--;
                }else{
                    digitflg = false;
                    t[2+lent] = c[i];
                    lent++;
                }
            } else{
                t[2+lent] = c[i];
                lent++;
            }
            i++;
        }
    }
    if(iflg && digitflg){
        exp = 0;
    }
    while(lent < n){
        t[2+lent] = '0';
        lent++;
    }
}
int main(){
    char a[1001], b[1001], at[1001], bt[1001];
    int expa = 0, expb = 0;
    int n;
    bool flg = true;
    scanf("%d %s %s", &n, a, b);
    change(a, at, expa, n);
    change(b, bt, expb, n);
    if(expa != expb){
        flg = false;
    }
    for (int i = 0; i < n; ++i) {
        if(at[i+2] != bt[i+2]){
            flg = false;
            break;
        }
    }
    if(flg){
        printf("YES ");
        printf("0.");
        for (int i = 0; i < n; ++i) {
            printf("%c", at[i+2]);
        }
//        if(expa != 0){
            printf("*10^%d", expa);
//        }
    }else{
        printf("NO ");
        printf("0.");
        for (int i = 0; i < n; ++i) {
            printf("%c", at[i+2]);
        }
//        if(expa != 0){
            printf("*10^%d", expa);
//        }
        printf(" ");
        printf("0.");
        for (int i = 0; i < n; ++i) {
            printf("%c", bt[i+2]);
        }
//        if(expb != 0){
            printf("*10^%d", expb);
//        }
    }


    return 0;
}
//#include <cstdio>
//#include <cstring>
//int tran(char *s, char *r, int n){
//    char *p, *pr;
//    int len, fr = 0, t = 0;
//    if (p = strchr(s, '.')){
//        char *tp = s + strlen(s) - 1;
//        while (tp != p && *tp == '0'){ //清理小数部分末尾0
//            *tp = '\0';
//            --tp;
//        }
//        len = p - s;
//        while (*p){
//            *p = *(p+1);
//            ++p;
//        }
//    }else{
//        len = strlen(s);
//    }
//    p = s;
//    while (*p){
//        if (*p == '0'){
//            ++fr;
//        }else{
//            break;
//        }
//        ++p;
//    }
//    strcpy(r, "0.");
//    pr = &r[2];
//    while (*p && t < n){
//        *pr++ = *p++;
//        ++t;
//    }
//    while (t++ < n){
//        *pr++ = '0';
//    }
//    printf("%d %d\n", len, fr);
//    sprintf(pr, "*10^%d", len - fr);
//    return len;
//}
//int main()
//{
//    int n;
//    char s1[200], s2[200], rs1[200], rs2[200];
//    scanf("%d%s%s", &n, s1, s2);
//    int len1 = tran(s1, rs1, n);
//    int len2 = tran(s2, rs2, n);
//    if (0 == strcmp(rs1, rs2)){
//        printf("YES %s\n", rs1);
//    }else{
//        printf("NO %s %s\n", rs1, rs2);
//    }
//    return 0;
//}