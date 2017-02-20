#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool book[10001];
int findminprime(int a){
    if(a == 0 || a == 1)
        return 2;
    int flg = false;
    int i = a;
    for (; !flg ; ++i) {
        flg = true;
        for (int j = 2; j * j < i + 1; ++j) {
            if(i % j == 0){
                flg = false;
            }
        }
    }
    return i - 1;
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1078/in1078", "r", stdin);
    int msize, num;
    scanf("%d %d\n", &msize, &num);
    int p = findminprime(msize);
//    cout << p << endl;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        int j = 0;
        for (; j < p; ++j) {
            if(!book[(tmp + j * j) % p]){
                if(i != 0)
                    printf(" ");
                printf("%d", (tmp + j * j) % p);
                book[(tmp + j * j) % p] = true;
                break;
            }
        }
        if(j == p){
            printf(" -");
        }
    }
    return 0;
}