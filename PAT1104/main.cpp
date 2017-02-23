#include <iostream>
#include <vector>
using namespace std;
//vector<double> vecd;
int main() {
    int num;
    double sum = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        double tmp;
        scanf("%lf", &tmp);
//        vecd.push_back(tmp);
        sum += (double)(i + 1) * (num - i) * tmp;
    }
    printf("%.2lf", sum);


    return 0;
}