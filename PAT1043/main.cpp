#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;
struct node{
    node *left = NULL;
    node *right = NULL;
    int data;
};

node *insert1(node *t, int a){
    if(t == NULL){
        t = new node;
        t->data = a;
    } else if(a >= t->data){
        t->right = insert1(t->right, a);
    } else{
        t->left = insert1(t->left, a);
    }
    return t;
}
node *insert2(node *t, int a){
    if(t == NULL){
        t = new node;
        t->data = a;
    } else if(a >= t->data){
        t->left = insert2(t->left, a);
    } else{
        t->right = insert2(t->right, a);
    }
    return t;
}

void preorder(node *t, vector<int> &v){
    v.push_back(t->data);
    if(t->left != NULL){
        preorder(t->left, v);
    }
    if(t->right != NULL){
        preorder(t->right, v);
    }
}
void postorder(node *t, vector<int> &v){
    if(t->left != NULL){
        postorder(t->left, v);
    }
    if(t->right != NULL){
        postorder(t->right, v);
    }
    v.push_back(t->data);
}
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1043/in1043b", "r", stdin);
    int num;
    vector<int> ivec, v1, v2, ovec;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ivec.push_back(tmp);
    }
    node *t1 = NULL, *t2 = NULL;
    for (int i = 0; i < ivec.size(); ++i) {
        t1 = insert1(t1, ivec[i]);
        t2 = insert2(t2, ivec[i]);
    }
    preorder(t1, v1);
    preorder(t2, v2);
//
//    for (int i = 0; i < ivec.size(); ++i) {
//        cout << ivec[i] << " ";
//    }
//    cout << endl;
//
//    for (int i = 0; i < v1.size(); ++i) {
//        cout << v1[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < v2.size(); ++i) {
//        cout << v2[i] << " ";
//    }
//    cout << endl;
    if(ivec != v1 && ivec != v2){
        printf("NO");
    } else if(ivec == v1){
        postorder(t1, ovec);
        printf("YES\n");
        for (int i = 0; i < ovec.size(); ++i) {
            if(i == 0)
                printf("%d", ovec[i]);
            else
                printf(" %d", ovec[i]);
        }
    } else{
        postorder(t2, ovec);
        printf("YES\n");
        for (int i = 0; i < ovec.size(); ++i) {
            if(i == 0)
                printf("%d", ovec[i]);
            else
                printf(" %d", ovec[i]);
        }
    }

    return 0;
}