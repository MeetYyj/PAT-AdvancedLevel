#include <iostream>
using namespace std;
struct node{
    int data;
    int level;
    node *left;
    node *right;
};

int cntlevel[1001];
int cntlevel2[1001];
int maxlevel = 0;
node* insert(node *root, int data, int level){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->level = level;
        root->left = NULL;
        root->right = NULL;
    }else{
        if(data <= root->data){
            root->left = insert(root->left, data, level + 1);
        }else{
            root->right = insert(root->right, data, level + 1);
        }
    }
    cntlevel[level]++;
    if(level > maxlevel){
        maxlevel = level;
    }
    return root;
}

void dfs(node *root, int level){
    if(root == NULL){
        return;
    }
    cntlevel2[level]++;
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
}

int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1115/in1115", "r", stdin);
    int num;
    scanf("%d", &num);
    node *root = NULL;
    for (int i = 0; i < num; ++i) {
        int tmpdata;
        scanf("%d", &tmpdata);
        root = insert(root, tmpdata, 0);
    }
    dfs(root, 0);
    printf("%d + %d = %d", cntlevel2[maxlevel], cntlevel2[maxlevel - 1], cntlevel2[maxlevel - 1] + cntlevel2[maxlevel]);

//    printf("%d + %d = %d", cntlevel[maxlevel], cntlevel[maxlevel - 1] - cntlevel[maxlevel], cntlevel[maxlevel - 1]);
    return 0;
}