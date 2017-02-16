#include <iostream>
using namespace std;
string day[7] = {"MON","TUE", "WED", "THU", "FRI", "SAT","SUN"};
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1061/in1061", "r", stdin);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int cnt = 0;
    for (int i = 0; i < s1.length() && i < s2.length(); ++i) {
        if(s1[i] == s2[i] && 'A' <= s1[i] && s1[i] <= 'G' && cnt == 0){
                cout << day[s1[i] - 'A'] << " ";
                cnt++;
        } else if(cnt == 1 && s1[i] == s2[i] && 'A' <= s1[i] && s1[i] <= 'N'){
            printf("%02d:", s1[i] - 'A' + 10);
            cnt++;
        } else if(cnt == 1 && s1[i] == s2[i] && '0' <= s1[i] && s1[i] <= '9'){
            printf("%02d:", s1[i] - '0');
            cnt++;
        }
    }

    for (int i = 0; i < s3.length() && i < s4.length(); ++i) {
        if(s3[i] == s4[i] && ('A' <= s3[i] && s3[i] <= 'Z' || 'a' <= s3[i] && s3[i] <= 'z' )) {
            printf("%02d", i);
        }
    }
    return 0;
}