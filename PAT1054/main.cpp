#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1054/in1054", "r", stdin);
    int m, n;
    scanf("%d %d\n", &m, &n);
    map<int, int> mp;
    for (int i = 0; i < m*n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        mp[tmp]++;
    }
    int mcnt = 0;
    int mvalue;
    for (auto a : mp) {
        if(a.second > mcnt){
            mcnt = a.second;
            mvalue = a.first;
        }
    }
    printf("%d", mvalue);
    return 0;
}