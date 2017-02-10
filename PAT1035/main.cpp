#include <iostream>
#include <vector>
using namespace std;

struct stu{
    string id;
    string passwd;
};
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1035/in1035b", "r", stdin);
    int num;
    vector<stu> vecs;
    scanf("%d\n", &num);
    for (int i = 0; i < num; ++i) {
        stu tmps;
        cin >> tmps.id >> tmps.passwd;
        vecs.push_back(tmps);
    }
    int cnt = 0;
    vector<stu> veco;
    for (int i = 0; i < vecs.size(); ++i) {
        bool flg = false;
        for (int j = 0; j < vecs[i].passwd.size(); ++j) {
            if(vecs[i].passwd[j] == '1'){
                vecs[i].passwd[j] = '@';
                flg = true;
            }
            if(vecs[i].passwd[j] == '0'){
                vecs[i].passwd[j] = '%';
                flg = true;
            }
            if(vecs[i].passwd[j] == 'l'){
                vecs[i].passwd[j] = 'L';
                flg = true;
            }
            if(vecs[i].passwd[j] == 'O'){
                vecs[i].passwd[j] = 'o';
                flg = true;
            }
        }
        if(flg){
            cnt++;
            veco.push_back(vecs[i]);
        }
    }
    if(cnt != 0){
        cout << cnt << endl;
        for (int i = 0; i < cnt; ++i) {
            cout << veco[i].id << " " << veco[i].passwd << endl;
        }
    } else {
        if(num == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else{
            cout << "There are " << num << " accounts and no account is modified" << endl;
        }
    }

    return 0;
}