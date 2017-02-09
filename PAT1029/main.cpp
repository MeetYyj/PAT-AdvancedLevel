#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n1,n2;
vector<int> vecl;
int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1029/in1029", "r", stdin);
    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i) {
        int tmpl;
        scanf("%d", &tmpl);
        vecl.push_back(tmpl);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; ++i) {
        int tmpl;
        scanf("%d", &tmpl);
        vecl.push_back(tmpl);
    }
    sort(vecl.begin(), vecl.end());
    printf("%d", vecl[(vecl.size() - 1)/2]);
    return 0;
}