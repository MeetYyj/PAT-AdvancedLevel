#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a;
    scanf("%d", &a);
    int cnt = 0;
    int tmp = a;
    int sum = 0;
    while(tmp){
        tmp /= 10;
        cnt++;
    }
    for (int i = 0; i < cnt; ++i) {
        int r = a%(int)pow(10, i + 1);
        if(r < pow(10, i)){
            sum += 0;
        }else if( 2 * pow(10, i) <= r){
            sum += pow(10, i);
        }else {
            sum += a%(int)pow(10, i) + 1;
        }
        sum += int(a / pow(10, i+1)) * pow(10, i);
    }
    cout << sum;
    return 0;
}