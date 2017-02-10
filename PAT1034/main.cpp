#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int graph[2001][2001];
int orgidtime[2001] = {0};
int orgnum[2001] = {0};
int orgid = 0;
bool iscollected[2001];
struct person{
    string name;
    int id;
    int sumtime = 0;
    int orgid;
};
vector<person> vecp;
void bfs(int size){
    for (int i = 0; i < size; ++i) {
        if(!iscollected[i]){
            iscollected[i] = true;
            vecp[i].orgid = orgid;
            orgnum[orgid]++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                for (int j = 0; j < size; ++j) {
                    if(!iscollected[j] && graph[tmp][j] != 0){
                        q.push(j);
                        iscollected[j] = true;
                        vecp[j].orgid = orgid;
                        orgnum[orgid]++;
                    }
                }
            }
            orgid++;
        }
    }

}

bool sort1(const person &a, const person &b){
    return a.name < b.name;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1034/in1034", "r", stdin);
    int num, threshold;
    int peoplenum = 0;
    scanf("%d %d", &num, &threshold);
    for (int i = 0; i < 2001; ++i) {
        for (int j = 0; j < 2001; ++j) {
            iscollected[j] = false;
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < num; ++i) {
        char tmp1[4], tmp2[4];
        int tmptime;
        scanf("%s %s %d\n", tmp1, tmp2, &tmptime);
        person tmpp1, tmpp2;
        tmpp1.name = tmp1;
        tmpp1.sumtime = tmptime;
        tmpp2.name = tmp2;
        tmpp2.sumtime = tmptime;
        bool flg1 = true, flg2 = true;
        for (int j = 0; j < vecp.size() ; ++j) {
            if(vecp[j].name == tmpp1.name){
                vecp[j].sumtime += tmpp1.sumtime;
                tmpp1.id = vecp[j].id;
                flg1 = false;
            }
            if(vecp[j].name == tmpp2.name){
                vecp[j].sumtime += tmpp2.sumtime;
                tmpp2.id = vecp[j].id;
                flg2 = false;
            }
        }
        if(flg1){
            tmpp1.id = peoplenum;
            vecp.push_back(tmpp1);
            peoplenum++;
        }
        if(flg2){
            tmpp2.id = peoplenum;
            vecp.push_back(tmpp2);
            peoplenum++;
        }
        graph[tmpp1.id][tmpp2.id] += tmptime;
        graph[tmpp2.id][tmpp1.id] += tmptime;
    }
    bfs(vecp.size());
    for (int i = 0; i < vecp.size(); ++i) {
        orgidtime[vecp[i].orgid] += vecp[i].sumtime;
    }
//    for (int i = 0; i < vecp.size(); ++i) {
//        cout << vecp[i].sumtime << " " << vecp[i].orgid << " " << orgnum[vecp[i].orgid] << endl;
//        cout <<iscollected[i] << endl;
//    }
    vector<person> vecout;
    for (int i = 0; i < orgid; ++i) {
        if(orgidtime[i] > threshold * 2 && orgnum[i] > 2){
            int headtime = -1;
            int headindex = -1;
            for (int j = 0; j < vecp.size(); ++j) {
                if(vecp[j].orgid == i && vecp[j].sumtime > headtime){
                    headtime = vecp[j].sumtime;
                    headindex = j;
                }
            }
            vecout.push_back(vecp[headindex]);
        }
    }
    if(vecout.size() == 0){
        printf("0");
    }else{
        sort(vecout.begin(), vecout.end(), sort1);
        cout << vecout.size() << endl;
        for (int i = 0; i < vecout.size(); ++i) {
            cout << vecout[i].name << " " << orgnum[vecout[i].orgid] << endl;
        }
    }


//    for (int i = 0; i < 8; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}