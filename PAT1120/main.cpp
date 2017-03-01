#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ischecked[100000];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1120/in1120", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<int> veco;
    for(int i = 0; i < num; i++){
        int tmp;
        scanf("%d", &tmp);
        int sum = 0;
        while(tmp){
            sum += tmp % 10;
            tmp /= 10;
        }
        if(!ischecked[sum]){
            ischecked[sum] = true;
            veco.push_back(sum);
        }
    }
    sort(veco.begin(), veco.end());
    printf("%ld\n", veco.size());
    for (int i = 0; i < veco.size(); ++i) {
        if(i)
            printf(" ");
        printf("%d", veco[i]);
    }
    return 0;
}