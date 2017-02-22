#include <iostream>
#include <vector>
using namespace std;
bool issmaller[100001];
bool isbigger[100001];

int main() {
    int num;
    scanf("%d", &num);
    vector<int> vec(num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &vec[i]);
    }
    int maxx = -1, minn = 1000000001;
    for (int i = 0; i < num; ++i) {
        if(vec[i] > maxx){
            maxx = vec[i];
            issmaller[i] = true;
        }
        if(vec[num - 1 - i] < minn){
            minn = vec[num - 1 - i];
            isbigger[num - 1 - i] = true;
        }
    }
    vector<int> ovec;
    for (int i = 0; i < num; ++i) {
        if(issmaller[i] && isbigger[i]){
            ovec.push_back(vec[i]);
        }
    }

    printf("%ld\n", ovec.size());
    for (int i = 0; i < ovec.size(); ++i) {
        if(i != 0){
            printf(" ");
        }
        printf("%d", ovec[i]);
    }
    printf("\n");

    return 0;
}