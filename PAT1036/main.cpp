#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct stu{
    string name;
    string id;
    int grade;
};

bool sortm(const stu &a, const stu &b){
    return a.grade < b.grade;
}
bool sortf(const stu &a, const stu &b){
    return a.grade > b.grade;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1036/in1036a", "r", stdin);
    int num;
    scanf("%d\n", &num);
    vector<stu> vecm, vecf;
    for (int i = 0; i < num; ++i) {
        stu tmps;
        char c;
        cin >> tmps.name >> c >> tmps.id >> tmps.grade;
        if(c == 'M'){
            vecm.push_back(tmps);
        } else{
            vecf.push_back(tmps);
        }
    }
    sort(vecm.begin(), vecm.end(), sortm);
    sort(vecf.begin(), vecf.end(), sortf);
    if(vecf.empty()){
        cout << "Absent" << endl;
    } else{
        cout << vecf[0].name << " " << vecf[0].id << endl;
    }

    if(vecm.empty()){
        cout << "Absent" << endl;
    } else{
        cout << vecm[0].name << " " << vecm[0].id << endl;
    }

    if(!vecm.empty() && !vecf.empty()){
        cout << vecf[0].grade - vecm[0].grade << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}