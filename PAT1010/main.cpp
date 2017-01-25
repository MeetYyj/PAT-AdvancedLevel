#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char str1[11], str2[11];
int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1010/in1010", "r", stdin);
    int tag, radix;
    scanf("%s %s %d %d", &str1, &str2, &tag, &radix);
    //-----
    string A = str1;
    string B = str2;
    if(A == B){
        cout << radix;
        return 0;
    }
    //-----
    if(tag == 2){
        char strtmp[11];
        strcpy(strtmp, str1);
        strcpy(str1, str2);
        strcpy(str2, strtmp);
    }
    long long res10 = 0;
    int str1len = (int)strlen(str1);
    int str2len = (int)strlen(str2);
    for (int i = str1len - 1; i >= 0 ; --i) {
        if( 'a' <= str1[i] && str1[i] <= 'z'){
            res10 += (str1[i] - 'a' + 10) * pow(radix, str1len - 1 - i);
        } else {
            res10 += (str1[i] - '0') * pow(radix, str1len - 1 - i);
        }
    }

//    cout << res10 << endl;
    long long left = 2, right = res10 + 1, mid;
    bool flg = false;
    long long resA10 = 0;
    int cnt = 0;
    while(left <= right){
        mid = (left + right)/2;
        for (int i = str2len - 1; i >= 0 ; --i) {
            if( 'a' <= str2[i] && str2[i] <= 'z'){
                if((str2[i] - 'a' + 10) >= mid){
                    resA10 = -1;
                    break;
                }
                resA10 += (str2[i] - 'a' + 10) * pow(mid, str2len - 1 - i);
                if(resA10 > res10)
                    break;
            } else {
                if((str2[i] - '0') >= mid){
                    resA10 = -1;
                    break;
                }
                resA10 += (str2[i] - '0') * pow(mid, str2len - 1 - i);
                if(resA10 > res10)
                    break;
            }
        }
        if ( resA10 > res10){
            right = mid - 1;
        } else if(resA10 < res10){
            left = mid + 1;
        } else {
            flg = true;
            break;
        }
        cnt++;
//        cout << "cnt:" << cnt << " radix:" << mid << " int10:" << resA10 << endl;
        resA10 = 0;
    }
//    cout << "str1:" << str1 << " str2:" << str2 << endl;
//    cout << "radix1:" << radix << " radix2:" << mid << endl;
//    cout << "1int10:" << res10 << " 2int10:" << resA10 << endl;
    if(flg){
        cout << mid;
    } else {
        cout << "Impossible" ;
    }

    return 0;
}