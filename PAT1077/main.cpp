#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1077/in1077", "r", stdin);
    int num;
    scanf("%d\n", &num);
    vector<string> vecs;
    for (int i = 0; i < num; ++i) {
        char tmpc;
        string tmpstr;
        int j = 0;
        while((tmpc = getchar()) != '\n'){
            tmpstr.push_back(tmpc);
            j++;
        }
        vecs.push_back(tmpstr);
    }
//    for (int i = 0; i < vecs.size(); ++i) {
//        cout << vecs[i] << endl;
//    }
    int cnt = 0;
    bool flg = true;
    while(flg){
        if(cnt == vecs[0].size()){
            break;
        }
        char tmpc = vecs[0][vecs[0].size() - 1 - cnt];
        for (int i = 1; i < num; ++i) {
            if(cnt == vecs[i].size()){
                flg = false;
                break;
            }
            if(vecs[i][vecs[i].size() - 1 - cnt] != tmpc){
                flg = false;
                break;
            }
        }
        if(flg){
            cnt++;
        }
    }
    if(cnt == 0){
        printf("nai");
        return 0;
    }
    for (int i = 0; i < cnt; ++i) {
        printf("%c", vecs[0][vecs[0].size() - cnt + i]);
    }
    return 0;
}