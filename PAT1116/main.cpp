#include <iostream>
#include <vector>
using namespace std;
struct node{
    int id;
    int rank;
    bool isexit = false;
    bool ischecked = false;
}nodes[10000];

bool isprime(int id){
    if(id == 1){
        return false;
    }else if(id == 2){
        return true;
    }else{
        for (int i = 2; i * i < id + 1; ++i) {
            if(id % i == 0){
                return false;
            }
        }
        return true;
    }
}

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1116/in1116", "r", stdin);
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int id;
        scanf("%d", &id);
        nodes[id].rank = i + 1;
        nodes[id].id = id;
        nodes[id].isexit = true;
    }

    int queries;
    scanf("%d", &queries);
    for (int i = 0; i < queries; ++i) {
        int id;
        scanf("%d", &id);
        if(nodes[id].isexit){
            if(nodes[id].ischecked){
                printf("%04d: Checked\n", id);
            } else{
                if(nodes[id].rank == 1){
                    printf("%04d: Mystery Award\n", id);
                }else if(isprime(nodes[id].rank)){
                    printf("%04d: Minion\n", id);
                }else{
                    printf("%04d: Chocolate\n", id);
                }
                nodes[id].ischecked = true;
            }
        }else{
            printf("%04d: Are you kidding?\n", id);
        }
    }
    return 0;
}