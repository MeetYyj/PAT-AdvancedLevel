#include <iostream>
#include <vector>
int need[256];
int have[256];
using namespace std;
int main() {
    string s1, s2;
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1092/in1092a", "r", stdin);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) {
        have[s1[i]]++;
    }
    for (int j = 0; j < s2.length(); ++j) {
        need[s2[j]]++;
    }
    bool flg = true;
    int cnt = 0;
    for (int i = '0'; i <= '9' ; ++i) {
        if(need[i] > have[i]){
            flg = false;
            cnt += need[i] - have[i];
        }
    }
    for (int i = 'a'; i <= 'z' ; ++i) {
        if(need[i] > have[i]){
            flg = false;
            cnt += need[i] - have[i];
        }
    }
    for (int i = 'A'; i <= 'Z' ; ++i) {
        if(need[i] > have[i]){
            flg = false;
            cnt += need[i] - have[i];
        }
    }
    if(flg){
        cout << "Yes " << s1.length() - s2.length();
    }else{
        cout << "No " << cnt;
    }
    return 0;
}