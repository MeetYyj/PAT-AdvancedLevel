#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1113/in1113a", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<int> vec;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    if(vec.size() % 2){
        printf("1 ");
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < vec.size() / 2; ++i) {
            sum1 += vec[i];
        }
        for (int i = vec.size() / 2; i < vec.size(); ++i) {
            sum2 += vec[i];
        }
        printf("%d", sum2 - sum1);
    }else{
        printf("0 ");
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < vec.size() / 2; ++i) {
            sum1 += vec[i];
        }
        for (int i = vec.size() / 2; i < vec.size(); ++i) {
            sum2 += vec[i];
        }
        printf("%d", sum2 - sum1);
    }
    return 0;
}