#include <iostream>
#include <string.h>
#include <limits>
using namespace std;

void addc(char *a, char *b, char *s){
    int l1 = (int)strlen(a), l2 = (int)strlen(b);
    int ci = 0;
    if(l2 < l1){
        char *tmp;
        tmp = a;
        a = b;
        b = tmp;
        int tmpl;
        tmpl = l1;
        l1 = l2;
        l2 = tmpl;

    }
    char st[65];
    int i = 0;
    for (; i < l1; ++i) {
        int value = a[l1 - i - 1] - '0' + b[l2 - i - 1] - '0' + ci;
        if( value < 10){
            st[i] = char(value + '0');
            ci = 0;
        }else{
            st[i] = char(value + '0' - 10);
            ci = 1;
        }
    }
    for (i = l1; i < l2  ; ++i) {
        int value = b[l2 - i - 1] - '0' + ci;
        if( value < 10){
            st[i] = char(value + '0');
            ci = 0;
        }else{
            st[i] = char(value + '0' - 10);
            ci = 1;
        }
    }
    if(ci == 1){
        st[i] = '1';
        i++;
    }
    for (int j = 0; j < i; ++j) {
        s[j] = st[i - j - 1];
    }
    s[i] = '\0';
}

bool calculate(char *a, char *b, char *c) {
    if(a[0] != '-' && b[0] != '-' && c[0] == '-'){
        return true;
    }else if(a[0] == '-' && b[0] == '-' && c[0] != '-'){
        return false;
    }else if(a[0] != '-' && b[0] != '-' && c[0] != '-'){
        char s[65];
        addc(a, b, s);
        if(strlen(s) > strlen(c)){
            return true;
        }else if(strlen(s) < strlen(c)){
            return false;
        }else{
            return strcmp(s, c) > 0;
        }
    }else if(a[0] == '-' && b[0] == '-' && c[0] == '-'){
        char a1[65], b1[65], c1[65];
        strcpy(a1, a+1);
        strcpy(b1, b+1);
        strcpy(c1, c+1);
        char s[65];
        addc(a1, b1, s);
        if(strlen(s) > strlen(c1)){
            return false;
        }else if(strlen(s) < strlen(c1)){
            return true;
        }else{
            return strcmp(s, c1) < 0;
        }
    }else if(a[0] != '-' && b[0] == '-' && c[0] == '-'){
        char *tmp;
        tmp = c;
        c = b;
        b = tmp;
        char s[65], b1[65], c1[65];
        strcpy(b1, b+1);
        strcpy(c1, c+1);
        addc(a, b1, s);
        if(strlen(s) > strlen(c1)){
            return true;
        }else if(strlen(s) < strlen(c1)){
            return false;
        }else{
            return strcmp(s, c1) > 0;
        }
    }else if(a[0] == '-' && b[0] != '-' && c[0] == '-'){
        char *tmp;
        tmp = c;
        c = a;
        a = tmp;
        char s[65], a1[65], c1[65];
        strcpy(a1, a+1);
        strcpy(c1, c+1);
        addc(a1, b, s);
        if(strlen(s) > strlen(c1)){
            return true;
        }else if(strlen(s) < strlen(c1)){
            return false;
        }else{
            return strcmp(s, c1) > 0;
        }
    }else if(a[0] != '-' && b[0] == '-' && c[0] != '-'){
        char s[65], b1[65];
        strcpy(b1, b+1);
        addc(b1, c, s);
        if(strlen(a) > strlen(s)){
            return true;
        }else if(strlen(a) < strlen(s)){
            return false;
        }else{
            return strcmp(a, s) > 0;
        }
    }else if(a[0] == '-' && b[0] != '-' && c[0] != '-'){
        char s[65], a1[65];
        strcpy(a1, a+1);
        addc(a1, c, s);
        if(strlen(b) > strlen(s)){
            return true;
        }else if(strlen(b) < strlen(s)){
            return false;
        }else{
            return strcmp(b, s) > 0;
        }
    }
}




int main() {
    long long a;
//    cout << "unsigned long: \t" << "所占字节数：" << sizeof(long);
//    cout << "\t最大值：" << (numeric_limits<long>::max)();
//    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; ++i) {
        char a[65], b[65], c[65];
        scanf("%s %s %s\n", a, b, c);
        printf("Case #%d: ", i+1);
        bool res = calculate(a, b, c);
        if(res){
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    return 0;
}

//#include <cstdio>
//using namespace std;
//int main() {
//    int n;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        long long a, b, c;
//        scanf("%lld %lld %lld", &a, &b, &c);
//        long long sum = a + b;
//        if(a > 0 && b > 0 && sum < 0) {
//            printf("Case #%d: true\n", i + 1);
//        } else if(a < 0 && b < 0 && sum >= 0){
//            printf("Case #%d: false\n", i + 1);
//        } else if(sum > c) {
//            printf("Case #%d: true\n", i + 1);
//        } else {
//            printf("Case #%d: false\n", i + 1);
//        }
//    }
//    return 0;
//}