#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct stu{
    string id;
    int grade;
    int finalrank;
    int group;
    int localrank;
};

bool sortA(const stu &a, const stu &b){
    if(a.grade > b.grade){
        return true;
    } else if(a.grade == b.grade && a.id < b.id){
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1025/in1025", "r", stdin);
    int n;
    cin >> n;
    vector<vector<stu>> vec(n);
    vector<stu> vecall;
    for (int i = 0; i < n; ++i) {
        int tmpn;
        scanf("%d\n", &tmpn);
        for (int j = 0; j < tmpn; ++j) {
            stu tmpstu;
            cin >> tmpstu.id >> tmpstu.grade;
            tmpstu.group = i +1;
            getchar();
            vec[i].push_back(tmpstu);
        }
    }

    for (int i = 0; i < n; ++i) {
        sort(vec[i].begin(), vec[i].end(), sortA);
        int tmpgrade = 101, rank = 0;
        for (int j = 0; j < vec[i].size(); ++j) {
            if(vec[i][j].grade < tmpgrade){
                rank = j + 1;
                vec[i][j].localrank = rank;
                tmpgrade = vec[i][j].grade;
            } else{
                vec[i][j].localrank = rank;
            }
            vecall.push_back(vec[i][j]);
        }
    }
    sort(vecall.begin(), vecall.end(), sortA);
    int tmpgrade = 101, rank = 0;
    for (int i = 0; i < vecall.size(); ++i) {
        if(vecall[i].grade < tmpgrade){
            rank = i + 1;
            vecall[i].finalrank = rank;
            tmpgrade = vecall[i].grade;
        } else{
            vecall[i].finalrank = rank;
        }
    }
    cout << vecall.size() << endl;
    for (int i = 0; i < vecall.size(); ++i) {
        cout << vecall[i].id << " " << vecall[i].finalrank << " " << vecall[i].group << " " << vecall[i].localrank << endl;
    }
    return 0;
}