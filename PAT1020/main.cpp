#include <iostream>
#include <queue>

using namespace std;

struct point{
//    int data = -1;
    int left = -1, right = -1;
};

point tree[31];
int post[31];
int in[31];
int buildtree(int* a, int* b, int size){
    if(size <= 0 ){
        return -1;
    }
    int root = a[size - 1];
    int i = 0;
    while(i < size && b[i] != root)
        i++;
    tree[root].left = buildtree(a, b, i);
    tree[root].right = buildtree(a+i, b+i+1, size - i - 1);
    return root;
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1020/in1020", "r", stdin);
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < size; ++i) {
        scanf("%d", &in[i]);
    }
    buildtree(post, in, size);
    queue<int> q;
    q.push(post[size - 1]);
    int cnt = 1;
    while(!q.empty()){
        int tmp = q.front();
        if(cnt != size){
            printf("%d ", tmp);
            cnt++;
        }
        else{
            printf("%d", tmp);
        }
        q.pop();
        if (tree[tmp].left != -1)
            q.push(tree[tmp].left);
        if (tree[tmp].right != -1)
            q.push(tree[tmp].right);

    }
    return 0;
}

//#include <cstdio>
//#include <vector>
//using namespace std;
//vector<int> post, in, level(100000, -1);
//void pre(int root, int start, int end, int index) {
//    if(start > end) return ;
//    int i = start;
//    while(i < end && in[i] != post[root]) i++;
//    level[index] = post[root];
//    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
//    pre(root - 1, i + 1, end, 2 * index + 2);
//}
//int main() {
//    int n, cnt = 0;
//    scanf("%d", &n);
//    post.resize(n);
//    in.resize(n);
//    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
//    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
//    pre(n-1, 0, n-1, 0);
//    for(int i = 0; i < level.size(); i++) {
//        if(level[i] != -1 && cnt != n - 1) {
//            printf("%d ", level[i]);
//            cnt++;
//        } else if(level[i] != -1){
//            printf("%d", level[i]);
//            break;
//        }
//    }
//    return 0;
//}