#include <iostream>
#include <queue>

using namespace std;
struct node{
    int data;
    node *left = NULL;
    node *right = NULL;
};

int getheight(node *root){
    if(!root){
        return 0;
    }else{
        return max(getheight(root->left), getheight(root->right)) + 1;
    }
}

node *rotationleft(node *root){
    node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

node *rotationright(node *root){
    node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

node *rotationleftright(node *root){
    root->left = rotationright(root->left);
    return rotationleft(root);
}

node *rotationrightleft(node *root){
    root->right = rotationleft(root->right);
    return rotationright(root);
}

node *insert(node *root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
    }else{
        if(data < root->data){
            root->left = insert(root->left, data);
            if(getheight(root->left) - getheight(root->right) == 2){
                if(data < root->left->data){
                    root = rotationleft(root);
                }else{
                    root = rotationleftright(root);
                }
            }
        }else{
            root->right = insert(root->right, data);
            if(getheight(root->right) - getheight(root->left) == 2){
                if(data >= root->right->data){
                    root = rotationright(root);
                }else{
                    root = rotationrightleft(root);
                }
            }
        }
    }

    return root;
}

int cnt = 0;
int num;

bool flg = true;
void levelorder(node *root){
    queue<node*> q;
    q.push(root);
    cnt++;
    while(!q.empty()){
        node *tmp = q.front();
        q.pop();
        if(cnt != 1)
            printf(" ");
        printf("%d", tmp->data);
        if(cnt != num && !tmp->left){
            flg = false;
        }
        if(tmp->left){
            q.push(tmp->left);
            cnt++;
        }
        if(cnt != num && !tmp->right){
            flg = false;
        }
        if(tmp->right){
            q.push(tmp->right);
            cnt++;
        }
    }
    printf("\n");
}


int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1123/in1123a", "r", stdin);
    scanf("%d", &num);
    node *root = NULL;
    for (int i = 0; i < num; ++i) {
        int tmpdata;
        scanf("%d", &tmpdata);
        root = insert(root, tmpdata);
    }
    levelorder(root);
    if(flg){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}