#include <iostream>
using namespace std;
char num[101];
char numtmp[101];
int length;
bool isPalindromicNumber(){
    int i = 0, j = length - 1;
    while (i <= j ){
        if(num[i] != num[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void operatorfunc(){
    bool lengthflg = false;
    for (int i = 0; i < length; ++i) {
        int  tmpi =  num[i] + num[length - 1 - i] - '0' - '0';
        if(tmpi >= 10){
            numtmp[i+1] = '1';
            if(i == length - 1)
                lengthflg = true;
        }
        if(numtmp[i] == '1' && tmpi%10 == 9){
            numtmp[i] = '0';
            numtmp[i+1] = '1';
            if(i == length - 1)
                lengthflg = true;
        }else if(numtmp[i] == '1'){
            numtmp[i] += tmpi%10;
        } else{
            numtmp[i] = tmpi%10 + '0';
        }
    }
    if(lengthflg)
        length++;
    for (int j = 0; j < length; ++j) {
        num[j] = numtmp[j];
        numtmp[j] = '\0';
    }
}

int main() {
    char tmp;
    int k, i = 0;
    while((tmp = getchar()) != ' '){
        num[i] = tmp;
        numtmp[i] = '\0';
        i++;
    }
    length = i;
    num[i] = '\0';
    numtmp[i] = '\0';
    scanf("%d", &k);
    int ktmp = 0;
    bool flg;
    flg = isPalindromicNumber();
    while(!flg && ktmp < k){
        operatorfunc();
        flg = isPalindromicNumber();
        ktmp++;
    }
    for (int j = length - 1; j >= 0; --j) {
        printf("%c", num[j]);
    }
    printf("\n");
    if(ktmp > k){
        printf("%d", k);
    } else {
        printf("%d", ktmp);
    }
    return 0;
}
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//string s;
//void add() {
//    string t = s;
//    reverse(t.begin(), t.end());
//    int len = s.length(), carry = 0;
//    for(int i = 0; i < len; i++) {
//        s[i] = s[i] + t[i] + carry - '0';
//        carry = 0;
//        if(s[i] > '9') {
//            s[i] = s[i] - 10;
//            carry = 1;
//        }
//    }
//    if(carry) s += '1';
//    reverse(s.begin(), s.end());
//}
//int main() {
//    int cnt;
//    cin >> s >> cnt;
//    for(int i = 0; i <= cnt; i++) {
//        string t = s;
//        reverse(t.begin(), t.end());
//        if(s == t) {
//            cout << s << endl << i;
//            return 0;
//        }
//        if(i != cnt) add();
//    }
//    cout << s << endl << cnt;
//    return 0;
//}