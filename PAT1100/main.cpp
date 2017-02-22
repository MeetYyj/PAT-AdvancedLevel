#include <iostream>
#include <string>
using namespace std;
string zero = {"tret"};
string lowbit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highbit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void print(string str){
    if('0' <= str[0] && str[0] <= '9'){
        int a = stoi(str);
        if(a == 0){
            printf("tret\n");
        }else if(!(a%13)){
            cout << highbit[a/13] << endl;
        }else if(a/13){
            cout << highbit[a/13] << " " << lowbit[a%13] << endl;
        }else{
            cout << lowbit[a] << endl;
        }
    }else{
        if(str.length() < 5){
            for (int i = 0; i < 13; ++i) {
                if(str == lowbit[i]){
                    printf("%d\n", i);
                    break;
                }
                if(str == highbit[i]){
                    printf("%d\n", i * 13);
                    break;
                }
            }
        } else{
            string s1(str.begin(), str.begin() + 3);
            string s2(str.begin() + 4, str.begin() + 7);
            int tmp = 0;
            for (int i = 0; i < 13; ++i) {
                if(s1 == highbit[i]){
                    tmp += i * 13;
                    break;
                }
            }
            for (int i = 0; i < 13; ++i) {
                if(s2 == lowbit[i]){
                    tmp += i;
                    break;
                }
            }
            cout << tmp << endl;
        }
    }


}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1100/in1100", "r", stdin);
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; ++i) {
        char tmpc;
        string tmpstr;
        int index = 0;
        while((tmpc = getchar()) != '\n'){
            tmpstr.push_back(tmpc);
        }
        print(tmpstr);
    }
    return 0;
}