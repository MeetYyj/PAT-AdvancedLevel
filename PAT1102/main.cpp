#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int left = -1;
    int right = -1;
};
vector<node> vec;
int num;
int cnt = 0;
void inorder(int index){
    cnt++;
    if(vec[index].left != -1){
        inorder(vec[index].left);
    }
    if(vec[index].right != -1){
        inorder(vec[index].right);
    }
}

int findroot(){
    for (int i = 0; i < num; ++i) {
        int tmp = i;
        inorder(i);
        if(cnt == num){
            return i;
        }
        cnt = 0;
    }
}

void levelorder(int root){
    queue<int> q;
    q.push(root);
    int cnttmp = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(cnttmp){
            printf(" ");
        }
        printf("%d", tmp);
        cnttmp++;
        if(vec[tmp].right != -1){
            q.push(vec[tmp].right);
        }
        if(vec[tmp].left != -1){
            q.push(vec[tmp].left);
        }
    }
    printf("\n");
}

int cntinorder = 0;
void inorderp(int index){
    if(vec[index].right != -1){
        inorderp(vec[index].right);
    }
    if(cntinorder != 0)
        printf(" ");
    printf("%d", index);
    cntinorder++;
    if(vec[index].left != -1){
        inorderp(vec[index].left);
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1102/in1102", "r", stdin);
    scanf("%d\n", &num);
    for (int i = 0; i < num; ++i) {
        char tmpl, tmpr;
        node tmpnode;
        scanf("%c %c\n", &tmpl, &tmpr);
        if(isdigit(tmpl)){
            tmpnode.left = tmpl - '0';
        }
        if(isdigit(tmpr)){
            tmpnode.right = tmpr - '0';
        }
        vec.push_back(tmpnode);
    }
//    for (int i = 0; i < vec.size(); ++i) {
//        cout << vec[i].left << " " << vec[i].right << endl;
//    }
    int root = findroot();
    levelorder(root);
    inorderp(root);
//    cout << root;

    return 0;
}