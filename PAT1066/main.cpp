#include <iostream>
#define max(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

struct node{
    int data;
    node *left = NULL;
    node *right = NULL;
};

int getheight(node *t){
    if(t == NULL){
        return 0;
    }else{
        return max(getheight(t->left), getheight(t->right)) + 1;
    }
}

node* singleLeftRotation(node *root){
    node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

node* singleRightRotation(node *root){
    node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}


node* leftRightRotation(node* root){
    root->left = singleRightRotation(root->left);
    return singleLeftRotation(root);
}

node* rightLeftRotation(node* root){
    root->right = singleLeftRotation(root->right);
    return singleRightRotation(root);
}

node* insert(node *root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
    } else if(data < root->data){
        root->left = insert(root->left, data);
        if((getheight(root->left) - getheight(root->right)) == 2){
            if(data < root->left->data){
                root = singleLeftRotation(root);
//                cout << "L" << endl;
            }else{
                root = leftRightRotation(root);
//                cout << "LR" << endl;
            }
        }
    }else{
        root->right = insert(root->right, data);
        if((getheight(root->right) - getheight(root->left)) == 2){
            if(data > root->right->data){
                root = singleRightRotation(root);
//                cout << "R" << endl;
            } else{
                root = rightLeftRotation(root);
//                cout << "RL" << endl;
            }
        }
    }
    return root;
}


int main(){
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1066/in1066", "r", stdin);
    int num;
    scanf("%d", &num);
    node *root = NULL;
    for (int i = 0; i < num; ++i) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("%d", root->data);
    return 0;
}