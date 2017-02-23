#include <iostream>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1108/in1108a", "r", stdin);
    int num;
    scanf("%d", &num);
    int cnt = 0;
    double sum = 0;
    for (int i = 0; i < num; ++i) {
        string str;
        cin >> str;
        int posdot = -1;
        int numdot = 0;
        bool flg = true;
        for (int j = 0; j < str.length(); ++j) {
            if(str[j] == '.'){
                numdot++;
                posdot = j;
            }else if(('0' <= str[j] && str[j] <= '9') || (str[j] == '-') ){

            }else{
                flg = false;
                break;
            }
        }
        if(numdot > 1){
            flg = false;
        }
        if(numdot != 0 && str.length() - (posdot + 1) > 2){
            flg = false;
        }
        if(flg && (stod(str) > 1000 || stod(str) < -1000)){
            flg = false;
        }
        if(flg){
            sum += stod(str);
            cnt++;
        }else{
            cout << "ERROR: " << str << " is not a legal number" << endl;
        }
    }
    if(cnt == 0){
        printf("The average of 0 numbers is Undefined");
    }else if(cnt == 1){
        printf("The average of %d number is %.2lf", cnt, sum/cnt);
    }else{
        printf("The average of %d numbers is %.2lf", cnt, sum/cnt);

    }
    return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <string.h>
//using namespace std;
//int main() {
//    int n, cnt = 0;
//    char a[50], b[50];
//    double temp, sum = 0.0;
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        scanf("%s", a);
//        sscanf(a, "%lf", &temp);
//        sprintf(b, "%.2lf",temp);
//        int flag = 0;
//        for(int j = 0; j < strlen(a); j++) {
//            if(a[j] != b[j]) {
//                flag = 1;
//            }
//        }
//        if(flag || temp < -1000 || temp > 1000) {
//            printf("ERROR: %s is not a legal number\n", a);
//            continue;
//        } else {
//            sum += temp;
//            cnt++;
//        }
//    }
//    if(cnt == 1) {
//        printf("The average of 1 number is %.2lf", sum);
//    } else if(cnt > 1) {
//        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
//    } else {
//        printf("The average of 0 numbers is Undefined");
//    }
//    return 0;
//}