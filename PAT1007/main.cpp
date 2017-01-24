#include <iostream>
#include <vector>

using namespace std;
int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1007/in1007", "r", stdin);
    int num;
    scanf("%d", &num);
    int sum = -1, tmp = 0, left = 0, lefttmp = 0, right = 0;
    bool flg = true;
    vector<int> iv;
    for (int i = 0; i < num; ++i) {
        int t;
        scanf("%d", &t);
        if(t >= 0){
            flg = false;
        }
        iv.push_back(t);
        tmp += t;
        if(tmp > sum){
            left = lefttmp;
            right = i;
            sum = tmp;
        } else if(tmp < 0){
            lefttmp = i + 1;
            tmp = 0;
        }
    }
    if(flg){
        cout << 0 << " " << iv[0] << " " << iv[num - 1];
    } else{
        cout << sum << " " << iv[left] << " " << iv[right];
    }
    return 0;
}