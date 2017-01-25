#include <iostream>
using namespace std;
int main() {
    int num;
    scanf("%d", &num);
    int preFloor = 0, timeSum = 0;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp > preFloor){
            timeSum += (tmp - preFloor) * 6;
        } else{
            timeSum += (preFloor - tmp) * 4;
        }
        timeSum += 5;
        preFloor = tmp;
    }
    printf("%d", timeSum);
    return 0;
}