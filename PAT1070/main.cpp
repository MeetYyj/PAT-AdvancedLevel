#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cake{
    double inventory;
    double price;
    double unitprice;
};
bool sort1(const cake &a, const cake &b){
    return a.unitprice > b.unitprice;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1070/in1070", "r", stdin);
    int num, request;
    scanf("%d%d", &num, &request);
    vector<cake> cvec;
    for (int i = 0; i < num; ++i) {
        cake caketmp;
        scanf("%lf", &caketmp.inventory);
        cvec.push_back(caketmp);
    }
    for (int i = 0; i < num; ++i) {
        scanf("%lf", &cvec[i].price);
        cvec[i].unitprice = cvec[i].price / cvec[i].inventory;
    }
    sort(cvec.begin(), cvec.end(), sort1);
    double profit = 0;
    for (int i = 0; i < cvec.size(); ++i) {
        if(request >= cvec[i].inventory){
            request -= cvec[i].inventory;
            profit += cvec[i].price;
        } else{
            profit += request * cvec[i].unitprice;
            request = 0;
            break;
        }
    }
    printf("%.2lf", profit);
    return 0;
}