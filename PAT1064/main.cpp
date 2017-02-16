#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1064/in1064", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<int> ivec;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ivec.push_back(tmp);
    }
    sort(ivec.begin(), ivec.end());
    int left = 0, right = (int)ivec.size() - 1;
    queue<int> q;
    q.push(left);
    q.push(right);
    int flg = false;
    while(!q.empty()){
        left = q.front();
        q.pop();
        right = q.front();
        q.pop();
        if(left < right){
            int allsizep1 = right - left + 1 + 1;
            int i = 0;
            while(2 * pow(2, i) < allsizep1){
                i++;
            }
            i--;
            int pindex;
            if(pow(2, i) + pow(2, i+1) >= allsizep1){
                pindex = (right - left + 1) - (pow(2, i) - 1) - 1 + left;
                //all nodes - right tree nodes - 1 + leftstartnodeindex
            } else{
                pindex = (pow(2, i + 1) - 1) + 1 - 1 + left;
                //left tree nodes + rootnode(1) - 1 + leftstartnodeindex
            }
            int l1, r1, l2, r2;
            if(!flg){
                flg = true;
            }else{
                printf(" ");
            }
            printf("%d", ivec[pindex]);
            l1 = left;
            r1 = pindex - 1;
            q.push(l1);
            q.push(r1);
            l2 = pindex + 1;
            r2 = right;
            q.push(l2);
            q.push(r2);
        }else if (left == right){
            if(!flg){
                flg = true;
            }else{
                printf(" ");
            }
            printf("%d", ivec[left]);
        }
    }
    return 0;
}