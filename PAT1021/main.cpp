#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int num;
struct node{
    int data = -1;
    vector<int> next;
    int depth = 0;
}nodes[10001];
bool iscollected[10001];
int level[10001];
int components = 1;
int maxdepth = 0;

void bfs(){
    for (int startnode = 1; startnode <= num; ++startnode) {
        for (int i = 1; i <= num; ++i) {
            iscollected[i] = false;
            components = 1;
            level[i] = 0;
        }
        queue<int> q;
        q.push(startnode);
        iscollected[startnode] = true;
        level[startnode] = 1;
        nodes[startnode].depth++;
        for (int i = 1; i <= num; ++i) {
            if(q.front() == startnode){
                ;
            }else if(q.front() != startnode && !iscollected[i]){
                q.push(i);
                components++;
            }
            while(!q.empty()){
                int tmp = q.front();
                q.pop();
                nodes[startnode].depth = max(nodes[startnode].depth, level[tmp]);
                for (int j = 0; j < nodes[tmp].next.size(); ++j) {
                    if (!iscollected[nodes[tmp].next[j]]){
                        q.push(nodes[tmp].next[j]);
                        iscollected[nodes[tmp].next[j]] = true;
                        level[nodes[tmp].next[j]] = level[tmp] + 1;
                    }
                }
            }
        }
        maxdepth = max(maxdepth, nodes[startnode].depth);
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1021/in1021a", "r", stdin);
    scanf("%d\n", &num);
    for (int i = 0; i < num - 1; ++i) {
        int tmp1, tmp2;
        scanf("%d %d\n", &tmp1, &tmp2);
        nodes[tmp1].next.push_back(tmp2);
        nodes[tmp2].next.push_back(tmp1);
    }
//    for (int j = 1; j <= num; ++j) {
//        cout << j << ":";
//        for (int i = 0; i < nodes[j].next.size(); ++i) {
//            cout << nodes[j].next[i] << " ";
//        }
//        cout << endl;
//    }
    bfs();
    if(components != 1){
        printf("Error: %d components\n", components);
    } else{
        for (int i = 1; i <= num; ++i) {
            if(nodes[i].depth == maxdepth){
                printf("%d\n", i);
            }
        }
    }

    return 0;
}