#include <iostream>
#include <vector>

using namespace std;
int main() {
    int num, base;
    scanf("%d%d", &num, &base);
    vector<int> ivec;
    if(num == 0)
        ivec.push_back(num);
    while(num != 0){
        ivec.push_back(num%base);
        num /= base;
    }
    int flg = true;
    for (int i = 0; i < ivec.size()/2; ++i) {
        if(ivec[i] != ivec[ivec.size() - i - 1]){
            flg = false;
            break;
        }
    }
    if(flg){
        cout << "Yes" << endl;
        for (int i = ivec.size() - 1; i >= 0; --i) {
            printf("%d", ivec[i]);
            if(i != 0)
                printf(" ");
        }
    } else{
        cout << "No" << endl;
        for (int i = ivec.size() - 1; i >= 0; --i) {
            printf("%d", ivec[i]);
            if(i != 0)
                printf(" ");
        }
    }

    return 0;
}