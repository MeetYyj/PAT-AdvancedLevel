#include <iostream>
#include <vector>
using namespace std;
int pre[35], post[35], inorder[35];
int len = 0;
bool flg = true;
void checked(int prel, int prer, int postl, int postr){
    if(prel == prer){
        inorder[len] = pre[prel];
        len++;
        return;
    }
    int i;
    for (i = prel; i <= prer ; ++i) {
        if(pre[i] == post[postr - 1]){
            break;
        }
    }

    if(i - prel > 1){
        checked(prel + 1, i - 1, postl, postl + i - prel - 2);
        inorder[len] = pre[prel];
        len++;
        checked(i, prer, postl + i - prel - 1, postr - 1);
    }else{
        flg = false;
        inorder[len] = pre[prel];
        len++;
        checked(prel + 1, prer, postl, postr - 1);
    };
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1119/in1119a", "r", stdin);
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < num; ++i) {
        scanf("%d", &post[i]);
    }
    checked(0, num - 1, 0, num - 1);
    if(flg){
        printf("Yes\n");
        for (int i = 0; i < num; ++i) {
            if(i)
                printf(" ");
            printf("%d", inorder[i]);
        }
    } else{
        printf("No\n");
        for (int i = 0; i < num; ++i) {
            if(i)
                printf(" ");
            printf("%d", inorder[i]);
        }
    }
    printf("\n");
    return 0;
}