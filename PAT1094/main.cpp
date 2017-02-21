#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct person{
    int addr;
    int level = 0;
    vector<int> sons;
}persons[101];
int maxlevel = 0;
int levelcnt[101];
void bfs(){
    queue<int> q;
    persons[1].level = 1;
    q.push(1);
    while(!q.empty()){
        int tmp = q.front();
        if(persons[tmp].level > maxlevel){
            maxlevel = persons[tmp].level;
        }
        q.pop();
        for (int i = 0; i < persons[tmp].sons.size(); ++i) {
            q.push(persons[tmp].sons[i]);
            persons[persons[tmp].sons[i]].level = persons[tmp].level + 1;
        }
    }
}



int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1094/in1094", "r", stdin);
    int num, fucker;
    scanf("%d %d\n", &num, &fucker);
    for (int i = 0; i < fucker; ++i) {
        int addr;
        scanf("%d", &addr);
        int sonnum;
        scanf("%d", &sonnum);
        persons[addr].addr = addr;
        for (int j = 0; j < sonnum; ++j) {
            int tmpson;
            scanf("%d", &tmpson);
            persons[addr].sons.push_back(tmpson);
        }
    }
    bfs();
    int maxlevelindex;
    int maxnum = 0;
    for (int i = 1; i <= num; ++i) {
        levelcnt[persons[i].level]++;
        if(levelcnt[persons[i].level] > maxnum){
            maxnum = levelcnt[persons[i].level];
            maxlevelindex = persons[i].level;
        }
    }

    cout << maxnum << " " << maxlevelindex;
//    for (int i = 1; i <= num; ++i) {
//        for (int j = 0; j < persons[i].sons.size(); ++j) {
//            cout << persons[i].sons[j] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}