#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1063/in1063", "r", stdin);
    int linenum;
    scanf("%d", &linenum);
    vector<set<int>> vec;
    for (int i = 0; i < linenum; ++i) {
        set<int> s;
        int numt;
        scanf("%d", &numt);
        for (int j = 0; j < numt; ++j) {
            int tmp;
            scanf("%d", &tmp);
            s.insert(tmp);
        }
        vec.push_back(s);
    }

    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; ++i) {
        int l1, l2;
        scanf("%d%d", &l1, &l2);
        set<int> sinter;
        set_intersection(vec[l1 - 1].cbegin(), vec[l1 - 1].cend(), vec[l2 - 1].cbegin(), vec[l2 - 1].cend(), inserter(sinter, sinter.begin()));
        double result;
        result = (double)sinter.size() / (vec[l1 - 1].size() + vec[l2 - 1].size() - sinter.size());
        result *= 100;
        printf("%.1lf%%\n", result);
    }
    return 0;
}