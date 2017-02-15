#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
struct color{
    int value;
    int cnt = 0;
};
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1054/in1054", "r", stdin);
    int m, n;
    scanf("%d %d\n", &m, &n);
    map<int, color> mp;
    for (int i = 0; i < m*n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        mp[tmp].cnt++;
    }
    int mcnt = 0;
    int mvalue;
    for (auto a : mp) {
        if(a.second.cnt > mcnt){
            mcnt = a.second.cnt;
            mvalue = a.first;
        }
    }
    printf("%d", mvalue);
    return 0;
}