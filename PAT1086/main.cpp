#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> preorder;
vector<int> inorder;
vector<int> postorderv;
void postorder(int left, int right, int root){
    if(left == right){
        return;
    }
    int l1 = left, r1 = -1, l2 = -1, r2 = right;
    for (int i = left; i < right; ++i) {
        if(preorder[root] == inorder[i]){
            r1 = i;
            l2 = i + 1;
            break;
        }
    }
    postorder(l1, r1, root + 1);
    postorder(l2, r2, root + r1 - l1 + 1);
    postorderv.push_back(preorder[root]);
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1086/in1086", "r", stdin);
    int num;
    scanf("%d", &num);
    stack<int> s;
    for (int i = 0; i < num * 2; ++i) {
        string tmps;
        cin >> tmps;
        if(tmps[1] == 'u'){
            int tmpi;
            scanf("%d\n", &tmpi);
            preorder.push_back(tmpi);
            s.push(tmpi);
        }else{
            inorder.push_back(s.top());
            s.pop();
        }
    }
//    for (int i = 0; i < preorder.size(); ++i) {
//        cout << preorder[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < inorder.size(); ++i) {
//        cout << inorder[i] << " ";
//    }


    postorder(0, num, 0);
    for (int i = 0; i < postorderv.size(); ++i) {
        if(i != 0)
            printf(" ");
        printf("%d", postorderv[i]);
    }



    return 0;
}