#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1117/in1117", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<int> vec;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.rbegin(), vec.rend());
    int cnt = 0;
    bool flg = false;
    for (int i = 0; i < vec.size(); ++i) {
        cnt++;
        if(vec[i] > cnt){
        }else{
            flg = true;
            break;
        }
    }
    if(flg){
        cout << --cnt;
    }else{
        cout << cnt;
    }
    return 0;
}