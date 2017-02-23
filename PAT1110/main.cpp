#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isbooked[21];
struct node{
    int left = -1;
    int right = -1;
}nodes[21];
int root = -1;
int lastnode = -1;
int num;

bool bfs(){
    int cnt = 0;
    queue<int> q;
    q.push(root);
    cnt++;
    int tmp = -1;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(nodes[tmp].left == -1 && cnt != num){
            return false;
        }else{
            if(nodes[tmp].left != -1){
                q.push(nodes[tmp].left);
            }
            if(cnt != num){
                cnt++;
            }
        }
        if(nodes[tmp].right == -1 && cnt != num){
            return false;
        }else{
            if(nodes[tmp].right != -1){
                q.push(nodes[tmp].right);
            }
            if(cnt != num){
                cnt++;
            }
        }
    }
    lastnode = tmp;
    return true;
};

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1110/in1110", "r", stdin);
    scanf("%d\n", &num);
    for (int i = 0; i < num; ++i) {
        char tmpl[3], tmpr[3];
        scanf("%s %s\n", tmpl, tmpr);
        if(tmpl[0] == '-'){
            ;
        }else{
            nodes[i].left = stoi(tmpl);
            isbooked[stoi(tmpl)] = true;
        }
        if(tmpr[0] == '-'){
            ;
        }else{
            nodes[i].right = stoi(tmpr);
            isbooked[stoi(tmpr)] = true;
        }
    }

    for (int i = 0; i < num; ++i) {
        if(!isbooked[i]){
            root = i;
            break;
        }
    }

    bool res = bfs();
    if(res){
        printf("YES %d", lastnode);
    }else{
        printf("NO %d", root);
    }
    return 0;
}