#include <iostream>
#include <vector>
using namespace std;
int main() {
    int num;
    int cnt[10001];
    scanf("%d", &num);
    vector<int> ivec;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
        ivec.push_back(tmp);
    }
    bool flg = true;
    for (int i = 0; i < ivec.size(); ++i) {
        if(cnt[ivec[i]] == 1){
            printf("%d", ivec[i]);
            flg = false;
            break;
        }
    }
    if(flg){
        printf("None");
    }
    return 0;
}