#include <iostream>
using namespace std;
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1011/in1011", "r", stdin);
    double inOdd[3][3];
    int index[3];
    fill(index, index + 3, 0);
    double tmpMax = -1;
    for (int i = 0; i < 3; ++i) {
        scanf("%lf%lf%lf", &inOdd[i][0], &inOdd[i][1], &inOdd[i][2]);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(inOdd[i][j] > tmpMax){
                tmpMax = inOdd[i][j];
                index[i] = j;
            }
        }
        tmpMax = -1;
    }
    for (int i = 0; i < 3; ++i) {
        switch (index[i]){
            case 0:
                cout << "W ";
                break;
            case 1:
                cout << "T ";
                break;
            case 2:
                cout << "L ";
                break;
        }
    }
    double res = (inOdd[0][index[0]] * inOdd[1][index[1]] * inOdd[2][index[2]] * 0.65 - 1) * 2;
    //right
//    int restmp = res*1000;
//    if(res*1000 - restmp/10 *10 > 4.999)
//        res += 0.01;
    //error 1
//    res = res+0.005001;
    //error 2
//    int z = res * 1000 + 5.001;
//    res = (double)z/1000;
    //right
    printf("%.2lf", res);
    return 0;

//    char c[4] = {"WTL"};
//    double ans = 1.0;
//    for(int i = 0; i < 3; i++) {
//        double maxvalue = 0.0;
//        int maxchar = 0;
//        for(int j = 0; j < 3; j++) {
//            double temp;
//            scanf("%lf", &temp);
//            if(maxvalue <= temp) {
//                maxvalue = temp;
//                maxchar = j;
//            }
//        }
//        ans *= maxvalue;
//        printf("%c ", c[maxchar]);
//    }
//    printf("%.2f", (ans * 0.65 - 1) * 2);
//    return 0;
}