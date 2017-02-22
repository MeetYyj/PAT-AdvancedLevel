#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int left;
    int right;
    int data;
};
int cnt = 0;
void inorder(int root, vector<node> &vecn, vector<int> &vecd){
    if(vecn[root].left != -1){
        inorder(vecn[root].left, vecn, vecd);
    }
    vecn[root].data = vecd[cnt++];
//    cout << root << " " << vecn[root].data << endl;
    if(vecn[root].right != -1){
        inorder(vecn[root].right, vecn, vecd);
    }
}

void levelorder(vector<node> &vecn, vector<int> &vecd){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int tmp = q.front();
        if(tmp != 0){
            printf(" ");
        }
        printf("%d", vecn[tmp].data);
        q.pop();
        if(vecn[tmp].left != -1){
            q.push(vecn[tmp].left);
        }
        if(vecn[tmp].right != -1){
            q.push(vecn[tmp].right);
        }
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1099/in1099", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<node> vecn((unsigned long)num);
    for (int i = 0; i < num; ++i) {
        scanf("%d%d", &vecn[i].left, &vecn[i].right);
    }
    vector<int> vecd((unsigned long)num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &vecd[i]);
    }
    sort(vecd.begin(), vecd.end());
    //inorder-----
    inorder(0, vecn, vecd);
    levelorder(vecn, vecd);
//    stack<int> s;
//    s.push(0);
//    while(!s.empty()){
//        int tmp = s.top();
//        s.pop();
//        if(vecn[tmp].right != -1){
//            s.push(vecn[tmp].right);
//        }
//        if(vecn[tmp].left != -1){
//            s.push(vecn[tmp].left);
//        }
//
//    }


    return 0;
}